#! /bin/sh
. /usr/bin/siglent/usr/usr/upgrade/siglentlib.sh
#. ./siglentlib.sh

echo "update.sh starting ..."

#upgrade_uboot ./MLO ./u-boot.img
chmod -R 777 /usr/bin/siglent/usr/usr/upgrade/*
is_rootfs_rw
if [  $? -eq "1" ]; then
	cp /usr/bin/siglent/usr/usr/upgrade/*.app /usr/bin/siglent/
	cp /usr/bin/siglent/usr/usr/upgrade/siglentlib.sh /usr/lib/
	mkdir /usr/bin/siglent/firmdata0
	echo "++is 2.0 parition  version"
else
	upgrade_uimage /usr/bin/siglent/usr/usr/upgrade/rw_uImage
	echo "++is 3.0 parition  version"
fi

reboot -f
#chmod -R 777 /usr/bin/siglent/usr/usr/upgrade/*
#rm -rf /usr/bin/siglent/*.app
#cp /usr/bin/siglent/usr/usr/upgrade/*.app /usr/bin/siglent/
#cp -rf /usr/bin/siglent/usr/usr/upgrade/drivers   /usr/bin/siglent/
#cp -rf /usr/bin/siglent/usr/usr/upgrade/config  /usr/bin/siglent/
#cp -rf /usr/bin/siglent/usr/usr/upgrade/lib  /usr/
#cp -rf /usr/bin/siglent/usr/usr/upgrade/app/networking  /etc/init.d/
#rm -rf /usr/bin/siglent/usr/config/NSP_config.xml

echo "update.sh ending ..."
