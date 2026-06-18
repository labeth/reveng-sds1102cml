#! /bin/sh
 #	name: 	 	get_mtd_num 
 #	function: get mtd number thouch mtd name
 #	parameter:    p1 --- mtd name 
 #	author:			Bookwore.Peng 		
 get_mtd_num()
 {
	MTD_NAME=$1 
	
	MTD_NUM=$(cat /proc/mtd | grep $MTD_NAME | cut -d :  -f 1)
	echo $MTD_NUM
 }
 
 #	name: 	 	format 
 #	function:  partion file system	 
 #	parameter:    	p1 --- mtd name
 #					p2 --- format image idr
 #	author:			Bookwore.Peng 		 
format()
{
	MTD_NAME=$1 
	FORMAT_IMAGE=$2

	echo "format:disk name is - "$MTD_NAME
	echo "format:image dir is - "$FORMAT_IMAGE
	
	MTD_NUM=$(get_mtd_num $MTD_NAME)
	echo "format: mtd number is - "${MTD_NUM}
	flash_erase "/dev/"${MTD_NUM} 0x00 0x00
	
	echo "format:nand write"
	nandwrite -m -p /dev/$MTD_NUM $FORMAT_IMAGE
	
	echo "format:mtd number is - "$MTD_NUM
}

 #	name: 	 	attach_ubi 
 #	function:		 	attach ubi	 
 #	parameter:    p1--- mtd name
 #	author:			Bookwore.Peng 
attach_ubi() 
{
	MTD_NAME=$1
	echo "attach_ubi:"$MTD_NAME
	MTD_NUM=$(get_mtd_num $MTD_NAME | cut -b 4-10 )
	echo "attach_ubi:"$MTD_NUM
	
	ubiattach /dev/ubi_ctrl -m ${MTD_NUM} -O 2048
	return $?
}

 #	name: 	is_ubi_attached 
 #	function: juge ubi is attched? 
 #	parameter:
 #	author:			Bookwore.Peng 		
is_ubi_fs_attached()
{
	UBI_INDEX=$1
	if [ -e /dev/$UBI_INDEX ]; then
		echo $UBI_INDEX"attached"
		return 1
	else
		echo $UBI_INDEX"unattached"
		return 0
	fi
}
 #	name: 	 	is_fs_mounted 
 #	function: is fs mounted?	 
 #	parameter:  p1--- mount dir	  
 #	author:			Bookwore.Peng 		 
is_fs_mounted()
{
	MOUNT_DIR_NAME=$1

	echo "MOUNT_DIR_NAME = "$MOUNT_DIR_NAME
	TEST_RESTURN=$(cat /proc/mounts | grep $MOUNT_DIR_NAME)
	echo "TEST_RESTURN = "$TEST_RESTURN
	if [ -n "$TEST_RESTURN" ]; then
		echo "is_fs_mounted 1 --- "$TEST_RESTURN
		return 1
	else
		echo "is_fs_mounted 0 --- "$TEST_RESTURN
		return 0
	fi
}
 #	name: 	 	mount_fs 
 #	function: mount file system	 
 #	parameter:    	p1--- mtd name	  
 #					p2--- mount dir
 #					p3--- mtd ubi index
 #					p4--- image dir
 #					p5--- permission
 #	author:			Bookwore.Peng
 #	return:			MOUNT_FAILED=255 mount failed
MOUNT_FAILED=255
mount_fs()
{
	MTD_NAME=$1
	MOUNT_DIR=$2
	UBI_INDEX=$3
	FORMAT_IMAGE=$4
	PERMISSION=$5
	
	echo "mount_fs: "${PERMISSION},${UBI_INDEX},${MOUNT_DIR}
	is_ubi_fs_attached $UBI_INDEX
	if [  $? -eq "0" ]; then
		MTD_NUM=$(get_mtd_num $MTD_NAME | cut -b 4-10 )
		attach_ubi $MTD_NAME
		#if [ $? -ne "0" ]; then
		#format $MTD_NAME $FORMAT_IMAGE
	fi
	
	is_fs_mounted $MOUNT_DIR
	if [  $? -eq "0" ]; then
		mount -o $PERMISSION -t ubifs $UBI_INDEX $MOUNT_DIR
		if [ $? -eq $MOUNT_FAILED ]; then
			format $MTD_NAME $FORMAT_IMAGE
			return $MOUNT_FAILED
		fi
	else
		mount -o $PERMISSION -t ubifs $UBI_INDEX $MOUNT_DIR
		echo "mount_fs: mounted "
	fi
}


 #	name: 	 	is_no_firmdata0_partition 
 #	function:  juge firmdata0 if exist
 #	parameter:	  
 #	author:			Bookwore.Peng 
 is_no_firmdata0_partition()
 {
	#echo $(cat /proc/mtd | grep firmdata0 | cut -b 25-40)
	if [ -z $(cat /proc/mtd | grep firmdata0 | cut -b 25-40) ]; then
		echo "is_no_firmdata0_partition:partion 2.0"
		return 1
	else
		echo "is_no_firmdata0_partition:partion 3.0"
		return 0
	fi
 }
 
 #	name: 	 	is_rootfs_rw 
 #	function: judge rootfs permmison
 #	parameter:	  
 #	author:			Bookwore.Peng 
 is_rootfs_rw()
 {
	cat /proc/mounts | grep rootfs | grep "ubifs ro"
	if [ $? -eq "1" ]; then
		echo "rootfs rw"
		return 1
	else
		echo "rootfs ro"
		return 0
	fi
 }
 
 #	name: 	 	is_need_upgrade 
 #	function:  judge is need upgrade by test upgrade.sh if exist
 #	parameter:	  
 #	author:			Bookwore.Peng 
 is_need_upgrade()
 {
	echo "is_need_upgrade"
	if [ -f /usr/bin/siglent/usr/usr/upgrade/upgrade.sh ]; then
		echo "is_need_upgrade:need upgrade"
		return 1
	else
		echo "is_need_upgrade:not need upgrade"
		return 0
	fi
 }

 #	name: 	 	delele_upgrade_flag 
 #	function:  delet upgarade flag(delete update.sh)
 #	parameter:	  
 #	author:			Bookwore.Peng 
 delele_upgrade_flag()
 {
	rm -rf /usr/bin/siglent/usr/usr/upgrade/*
 }
 
 #	name: 	 	partition_firmdata0_from_datafs 
 #	function:  format firmdata0from datafs,
 #			   datafs will become smaller             
 #	parameter:	  
 #	author:			Bookwore.Peng 
 partition_firmdata0_from_datafs()
 {
	is_no_firmdata0_partition
	if [  $? -eq "1" ]; then
		umount /usr/bin/siglent/usr/
		MTD_NUM=$(get_mtd_num datafs)
		flash_erase /dev/$MTD_NUM 0 0
		nandwrite -s 0 -p /dev/$MTD_NUM /usr/bin/siglent/upgrade/firmdata0.img
		nandwrite -s 0x6400000 -p /dev/$MTD_NUM /usr/bin/siglent/upgrade/datafs.img
	fi
 }
 
 #	name: 	 	upgrade_uboot 
 #	function:   upgrade uboot
 #	parameter:	1-MLO dir
 #              2-u-boot.img dir 
 #	author:			Bookwore.Peng 
 upgrade_uboot()
 {
 	MLO_DIR=$1
	UBOOT_DIR=$2
	
	echo "upgrade "$MLO_DIR
	echo "upgrade "$UBOOT_DIR

	flash_erase /dev/mtd0 0 0 # SPL
	nandwrite -s 0 -p /dev/mtd0 $MLO_DIR
	MTD_NUM=$(get_mtd_num SPL.backup1) # SPL.backup1
	flash_erase /dev/$MTD_NUM 0 0
	nandwrite -s 0 -p /dev/$MTD_NUM $MLO_DIR
	MTD_NUM=$(get_mtd_num SPL.backup2) # SPL.backup2
	flash_erase /dev/$MTD_NUM 0 0	
	nandwrite -s 0 -p /dev/$MTD_NUM $MLO_DIR
	MTD_NUM=$(get_mtd_num SPL.backup3) # SPL.backup3
	flash_erase /dev/$MTD_NUM 0 0
	nandwrite -s 0 -p /dev/$MTD_NUM $MLO_DIR	

	flash_erase /dev/mtd4 0 0 # U-Boot	
	nandwrite -s 0 -p /dev/mtd4 $UBOOT_DIR
 }
 #	name: 	 	upgrade_uimage 
 #	function:  upgrade kernel
 #	parameter:	p1 --- kernel dir
 #	author:			Bookwore.Peng 
upgrade_uimage()
{
	UIMAGE_DIR=$1
	
	echo upgrade $UIMAGE_DIR
	MTD_NUM=$(get_mtd_num kerneldata)
	flash_erase /dev/$MTD_NUM 0 0
	nandwrite -s 0 -p /dev/$MTD_NUM $UIMAGE_DIR
}

 #	name: 	 	upgrade_app 
 #	function:  upgrade app files
 #	parameter:	 
 #	author:			Bookwore.Peng 
upgrade_app()
{
	echo "upgrade_app:starting"
	chmod -R 777 /usr/bin/siglent/usr/usr/upgrade/*
	cp /usr/bin/siglent/usr/usr/upgrade/SDS1000_arm.app /usr/bin/siglent/
	cp -r /usr/bin/siglent/usr/usr/upgrade/*.ko   /usr/bin/siglent/drivers/
	cp -r /usr/bin/siglent/usr/usr/upgrade/help.bin   /usr/bin/siglent/usr/help
	cp -r /usr/bin/siglent/usr/usr/upgrade/sds1000_fpga.rbf   /usr/bin/siglent/fpga/
	cp -r /usr/bin/siglent/usr/usr/upgrade/sds1000a_al.bin   /usr/bin/siglent/fpga/
	cp -r /usr/bin/siglent/usr/usr/upgrade/libglog.so.0   /usr/lib/
	echo "upgrade_app:ending"
}

MTD_DATAFS="datafs"
MTD_FIRMDATA0="firmdata0"

UBI_INDEX_DATAFS="ubi1_0"
UBI_INDEX_FIRMDATA0="ubi2_0"

FORMAT_IMAGE_DATAFS="/usr/bin/siglent/upgrade/datafs.img"
FORMAT_IMAGE_FIRMDATA0="/usr/bin/siglent/upgrade/firmdata0.img"

MOUNT_DIR_DATAFS=/usr/bin/siglent/usr
MOUNT_DIR_FIRMDATA0=/usr/bin/siglent/firmdata0

PERMISSON_RW="rw,sync"
PERMISSON_RO="ro,sync"
PERMISSON_RW_REMOUNT="rw,remount"
PERMISSON_RO_REMOUNT="ro,remount"

 #	name: 	 	check_and_upgrade 
 #	function:  check if need upgrade, if need upgrade immediately
 #	parameter:	 
 #	author:			Bookwore.Peng 
check_and_upgrade()
{
	echo "check_and_upgrade:starting..."
	mount_fs $MTD_DATAFS $MOUNT_DIR_DATAFS $UBI_INDEX_DATAFS $FORMAT_IMAGE_DATAFS $PERMISSON_RW
	is_need_upgrade
	if [ $? -eq "1" ]; then
		echo "check_and_upgrade: upgrade start ..."
		cp /usr/bin/siglent/usr/usr/upgrade/datafs.img /usr/bin/siglent/upgrade/
		cp /usr/bin/siglent/usr/usr/upgrade/firmdata0.img /usr/bin/siglent/upgrade/
		cp /usr/bin/siglent/usr/usr/upgrade/siglentlib.sh /usr/lib/
		upgrade_uboot /usr/bin/siglent/usr/usr/upgrade/MLO /usr/bin/siglent/usr/usr/upgrade/u-boot.img
		upgrade_uimage /usr/bin/siglent/usr/usr/upgrade/ro_uImage
		upgrade_app
		partition_firmdata0_from_datafs
		delele_upgrade_flag
		echo "check_and_upgrade: upgrade end... rebooting"
		reboot -f
	fi
	echo "check_and_upgrade:end..."
}

 #	name: 	 	check_and_copy_appdata 
 #	function:  check is need copy app data(cali data, serial number data etc.) to new partition
 #	parameter:	 
 #	author:			Bookwore.Peng
mount_check_copy_appdata()
{
	echo "++mount_check_copy_appdata: starting"
	mount_fs $MTD_FIRMDATA0 $MOUNT_DIR_FIRMDATA0 $UBI_INDEX_FIRMDATA0 $FORMAT_IMAGE_FIRMDATA0 $PERMISSON_RO
	if [ ! -f "/usr/bin/siglent/firmdata0/calibration.dat" ]; then
		umount -f $MOUNT_DIR_FIRMDATA0
		sync
		mount_fs $MTD_FIRMDATA0 $MOUNT_DIR_FIRMDATA0 $UBI_INDEX_FIRMDATA0 $FORMAT_IMAGE_FIRMDATA0 $PERMISSON_RW
		cp /usr/bin/siglent/calibration/calibration.dat /usr/bin/siglent/firmdata0/
		umount -f $MOUNT_DIR_FIRMDATA0
		sync
		mount_fs $MTD_FIRMDATA0 $MOUNT_DIR_FIRMDATA0 $UBI_INDEX_FIRMDATA0 $FORMAT_IMAGE_FIRMDATA0 $PERMISSON_RO
	fi
	echo "--mount_check_copy_appdata: ending"
}
#upgrade_uboot ./temp/MLO
#upgrade_uboot ./temp/MLO ./temp/u-boot.img

#upgrade_uimage ./temp/ro_uImage

#partition_firmdata0_from_datafs

#attach_ubi $MTD_DATAFS

#echo $(is_ubi_fs_attached $MTD_DATAFS)

#is_fs_mounted "/usr/bin/siglent/usr"
#is_fs_mounted $MOUNT_DIR_DATAFS
#if [  $? -eq "0" ]; then
#	mount_fs $MTD_DATAFS $MOUNT_DIR_DATAFS $UBI_INDEX_DATAFS $FORMAT_IMAGE_DATAFS
#else
#	echo "1"
#fi

#if [ $(is_fs_mounted "/usr/bin/siglent/usr") ]; then
#	format "datafs"
#fi
#if [ $(is_fs_mounted "/usr/bin/siglent/usr") = 0 ]; then
#	format "Manufacturedata"
#fi

