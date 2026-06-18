// Decompiled FPGA bring-up + acquisition-drive functions of SDS1000_arm.app
// (md5 e1bd88fb, image base 0x8000). Ghidra 12.1.2 ARM:LE:32:v8. Reference for
// validating the runtime reglog + sim/fpga against specs/04.

// ===== FUN_000cc184 PLANE-A byte writer (strb#1=CS1) @0xcc184 =====

uint FUN_000cc184(uint param_1,byte param_2)

{
  undefined1 local_1c [2];
  undefined2 local_1a;
  ushort local_18;
  undefined4 local_c;
  
  local_c = 0;
  if (-1 < *DAT_000cc21c) {
    local_1c[0] = 1;
    local_1a = (undefined2)((param_1 & 0xffff) >> 1);
    local_18 = (ushort)param_2;
    param_1 = ioctl(*DAT_000cc21c,DAT_000cc220,local_1c);
  }
  return param_1;
}



// ===== FUN_000cc224 GPMC read primitive @0xcc224 =====

undefined2 FUN_000cc224(uint param_1)

{
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_e;
  undefined4 local_c;
  
  local_c = 0;
  local_e = 0;
  if (*DAT_000cc2bc < 0) {
    local_1c = 0;
  }
  else {
    local_20[0] = 1;
    local_1e = (undefined2)((param_1 & 0xffff) >> 1);
    ioctl(*DAT_000cc2bc,DAT_000cc2c0,local_20);
  }
  return local_1c;
}



// ===== FUN_001b3500 PLANE-A write wrapper @0x1b3500 =====

void FUN_001b3500(undefined4 param_1,undefined1 param_2)

{
  FUN_000cc184(param_1,param_2);
  return;
}



// ===== FUN_000cc628 bitstream-load entry @0xcc628 =====

void FUN_000cc628(void)

{
  int iVar1;
  
  FUN_001d7db4();
  FUN_00136e60();
  FUN_001b24d4();
  FUN_0008d190();
  FUN_001b1bb0();
  FUN_0006fb4c();
  FUN_0006fb38();
  FUN_0006fb24();
  FUN_001b1a50();
  FUN_001b1a7c();
  FUN_001ad984();
  FUN_001bba20();
  FUN_0006fb88();
  FUN_001c17e0();
  FUN_001ebd00();
  FUN_001bc5a4();
  FUN_000754ac();
  FUN_0007597c();
  iVar1 = FUN_000cc48c();
  if (iVar1 == 1) {
    FUN_00074f84();
    FUN_00074fd4();
    FUN_000cd274();
  }
  FUN_000cc4c4();
  FUN_001ea290();
  FUN_001b33ac();
  FUN_000b5ab4();
  FUN_0020dcb8();
  FUN_000c99c4();
  FUN_000e1ba0(1);
  FUN_0022f838();
  FUN_001ad078();
  FUN_001ee50c();
  FUN_001dd338();
  FUN_00229cf0();
  FUN_00216680();
  FUN_0015aaa4();
  FUN_00096a28();
  FUN_001bb030();
  *DAT_000cc7fc = *DAT_000cc7fc + 1;
  FUN_001bad68(0);
  FUN_001a3118();
  FUN_000b6018();
  iVar1 = FUN_000cc35c();
  if (iVar1 == 0) {
    FUN_0004f8f0();
  }
  else {
    FUN_00015700(DAT_000cc800);
    iVar1 = FUN_000db46c(0x1d);
    if (iVar1 == 0) {
      FUN_001beae0();
      FUN_001bb3f4();
    }
    else {
      FUN_001bfafc();
      FUN_000cc954();
      FUN_001bdfd0(0);
    }
  }
  FUN_001a3080();
  FUN_001ea59c();
  FUN_000db640(0x33);
  FUN_0007aee8();
  FUN_001b1460(1);
  FUN_000dff60();
  FUN_001ad9d8();
  FUN_001eb920();
  FUN_0008c42c();
  FUN_0020644c();
  FUN_0009732c();
  FUN_000976f0();
  FUN_002165dc();
  FUN_0021b474();
  FUN_001bb7d8();
  FUN_000f01ac();
  FUN_00219ec8();
  FUN_001d36cc();
  FUN_001b0dac();
  iVar1 = FUN_001c15c8();
  if ((iVar1 != 3) && (iVar1 = FUN_001c15c8(), iVar1 == 0)) {
    *(undefined1 *)(DAT_000cc804 + 0x40) = 2;
  }
  *(undefined1 *)(DAT_000cc808 + 0x44) = 1;
  FUN_001c15c8();
  return;
}



// ===== FUN_001bba20 bitstream load @0x1bba20 =====

void FUN_001bba20(void)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0;
  *DAT_001bbb20 = 0;
  uVar1 = DAT_001bbb24;
  bVar2 = FUN_001ea214();
  if (bVar2 == 0) {
    local_10 = FUN_00018324(DAT_001bbb28);
    local_c = FUN_00018394(DAT_001bbb28,DAT_001bbb2c);
  }
  else if (bVar2 == 1) {
    local_10 = FUN_00018324(DAT_001bbb30);
    local_c = FUN_00018394(DAT_001bbb30,DAT_001bbb2c);
  }
  if (local_c == 0) {
    printf(DAT_001bbb34,(uint)bVar2);
  }
  else {
    FUN_00018508(uVar1,1,local_10,local_c);
    FUN_00018704(local_c);
    FUN_001b0dc4(uVar1,local_10);
  }
  return;
}



// ===== FUN_001b0dc4 bit-clocking loader @0x1b0dc4 =====

void FUN_001b0dc4(int param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int local_18;
  byte local_11;
  uint local_10;
  uint local_c;
  
  bVar2 = false;
  local_11 = 0;
  do {
    if (2 < local_11) {
LAB_001b1034:
      if (2 < local_11) {
        puts(DAT_001b1078);
        *DAT_001b1070 = 0;
      }
      return;
    }
    FUN_001adfdc(DAT_001b1060,0);
    bVar3 = FUN_001adfb0(DAT_001b1060);
    if ((bVar3 & 0x40) == 0) {
      FUN_001adfdc(DAT_001b1060,2);
      local_18 = 0;
      do {
        bVar3 = FUN_001adfb0(DAT_001b1060);
        if ((bVar3 & 0x40) != 0) {
          iVar4 = printf(DAT_001b1064,local_18);
          goto LAB_001b0ed4;
        }
        local_18 = local_18 + 1;
        FUN_00015700(DAT_001b1068);
      } while (local_18 < 0x15);
      bVar2 = true;
      iVar4 = puts(DAT_001b106c);
LAB_001b0ed4:
      if (!bVar2) {
        iVar4 = FUN_000cc440(iVar4);
        if (iVar4 == 1) {
          FUN_001adfdc(DAT_001b1060,10);
          FUN_000ce2f0(param_1,param_2);
          FUN_001adfdc(DAT_001b1060,2);
        }
        else {
          for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
            bVar3 = *(byte *)(param_1 + local_c);
            for (local_10 = 7; -1 < (int)local_10; local_10 = local_10 - 1) {
              bVar1 = (byte)(((int)(uint)bVar3 >> (local_10 & 0xff) & 1U) << 2);
              FUN_001adfdc(DAT_001b1060,bVar1 | 2);
              FUN_001985a4(1);
              FUN_001adfdc(DAT_001b1060,bVar1 | 3);
              FUN_001985a4(1);
            }
          }
        }
        bVar3 = FUN_001adfb0(DAT_001b1060);
        if ((bVar3 & 0x80) != 0) {
          *DAT_001b1070 = 1;
          puts(DAT_001b1074);
          goto LAB_001b1034;
        }
      }
    }
    local_11 = local_11 + 1;
  } while( true );
}



// ===== FUN_000ce2f0 SPI xfer @0xce2f0 =====

int FUN_000ce2f0(int param_1,uint param_2)

{
  int *piVar1;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  if ((*DAT_000ce430 < 0) || (param_1 == 0)) {
    local_14 = 0;
  }
  else {
    FUN_000ce05c();
    piVar1 = DAT_000ce434;
    DAT_000ce434[2] = 0;
    piVar1[3] = 0;
    *(undefined1 *)((int)DAT_000ce434 + 0x1a) = 8;
    for (; local_18 + 0x1000 <= param_2; local_18 = local_18 + 0x1000) {
      DAT_000ce434[4] = 0x1000;
      piVar1 = DAT_000ce434;
      *DAT_000ce434 = param_1 + local_18;
      piVar1[1] = 0;
      local_14 = ioctl(*DAT_000ce430,DAT_000ce438,DAT_000ce434);
    }
    if (local_18 < param_2) {
      DAT_000ce434[4] = param_2 - local_18;
      piVar1 = DAT_000ce434;
      *DAT_000ce434 = param_1 + local_18;
      piVar1[1] = 0;
      local_14 = ioctl(*DAT_000ce430,DAT_000ce438,DAT_000ce434);
    }
    FUN_000cdf48();
  }
  return local_14;
}



// ===== FUN_001ae530 0x44 enable strobe @0x1ae530 =====

void FUN_001ae530(void)

{
  FUN_001b3500(DAT_001ae55c,1);
  FUN_001b3500(DAT_001ae55c,0);
  return;
}



// ===== FUN_0021371c 0x35 run/mode writer @0x21371c =====

void FUN_0021371c(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 local_9;
  
  iVar2 = FUN_002135f4();
  iVar3 = FUN_00078d94();
  if (iVar2 == 0) {
    local_9 = 0;
  }
  else {
    local_9 = FUN_001ae594();
    if ((*(char *)(DAT_00213848 + 0x20) == '\0') && (*(char *)(DAT_0021384c + 0x40) == '\0')) {
      local_9 = local_9 & 0xfd;
    }
    else {
      local_9 = local_9 | 2;
    }
    if (iVar3 == 0xb) {
      local_9 = local_9 | 5;
    }
    else {
      if ((*(char *)(DAT_00213850 + 4) == '\x01') && (*(char *)(DAT_00213850 + 0x14) == '\0')) {
        bVar1 = local_9 & 0xf7 | 1;
      }
      else {
        bVar1 = local_9 | 1;
        if ((*(char *)(DAT_00213850 + 4) == '\0') && (*(char *)(DAT_00213850 + 0x14) == '\x01')) {
          bVar1 = local_9 | 9;
        }
      }
      local_9 = bVar1;
      local_9 = local_9 & 0xfb;
    }
  }
  FUN_001ae560(local_9);
  return;
}



// ===== FUN_001b05c8 divisor class mapper @0x1b05c8 =====

uint FUN_001b05c8(uint param_1,uint param_2)

{
  ushort local_e;
  undefined2 local_c;
  undefined1 local_9;
  
  if ((byte)param_1 < 4) {
    local_e = 0;
    local_c = 0;
    switch(param_1 & 0xff) {
    case 0:
      local_9 = 0x20;
      break;
    case 1:
      local_9 = 1;
      break;
    case 2:
      local_9 = 2;
      break;
    case 3:
      local_9 = 0x80;
      local_c = (undefined2)(param_2 & 0x3ffffff);
      local_e = (ushort)((((param_2 & 0x3ffffff) >> 0x10) << 0x16) >> 0x16);
    }
    FUN_001b3500(DAT_001b06c0,local_9);
    FUN_001b3560(DAT_001b06c4,local_c);
    param_1 = FUN_001b3560(DAT_001b06c8,local_e);
  }
  return param_1;
}



// ===== FUN_001b0570 rt-mode divisor 0x36 @0x1b0570 =====

void FUN_001b0570(undefined2 param_1)

{
  FUN_001b3560(DAT_001b05a0,param_1);
  return;
}



// ===== FUN_001b07dc arm (0xC0/0x57/0xC3) @0x1b07dc =====

void FUN_001b07dc(void)

{
  FUN_001b3500(DAT_001b0814,0xc0);
  FUN_002086f4();
  FUN_001ae070();
  FUN_002086f4();
  FUN_001b3500(DAT_001b0814,0xc3);
  return;
}



// ===== FUN_001b083c stop/latch 0xC8 @0x1b083c =====

void FUN_001b083c(void)

{
  FUN_001b3500(DAT_001b085c,200);
  return;
}



// ===== FUN_000d3148 per-tick dispatcher @0xd3148 =====

void FUN_000d3148(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_002135f4();
  if (iVar2 == 1) {
    FUN_0020dc04();
    FUN_00078ebc();
    FUN_0021371c();
    FUN_001d424c();
    uVar1 = FUN_002129c4();
    FUN_001ad510(uVar1,0xff);
    FUN_002155c4();
    if (*(char *)(DAT_000d3254 + 0x20) == '\0') {
      FUN_001b035c();
      if ((int)(DAT_000d3250 -
               (*(float *)(DAT_000d3258 + 8) * DAT_000d324c) / *(float *)(DAT_000d325c + 8)) <
          DAT_000d3260) {
        *(int *)(DAT_000d3258 + 4) = DAT_000d3260;
      }
    }
    else {
      FUN_002131f4();
      FUN_001b0398();
      if (((*DAT_000d3264 == '\x01') && (*DAT_000d3268 == 0)) &&
         (*(char *)(DAT_000d326c + 0x40) != '\x04')) {
        FUN_0021eb08();
      }
    }
  }
  return;
}



// ===== FUN_001b06cc status 0x38 bit0 @0x1b06cc =====

bool FUN_001b06cc(void)

{
  byte bVar1;
  
  bVar1 = FUN_001b34d4(DAT_001b0714);
  return (bVar1 & 1) == 0;
}



// ===== FUN_001b04e4 0x39 done @0x1b04e4 =====

bool FUN_001b04e4(void)

{
  byte bVar1;
  
  bVar1 = FUN_001ae5c8();
  return (bVar1 & 1) != 0;
}



// ===== FUN_001aef60 roll ADC 0x41/0x59 @0x1aef60 =====

void FUN_001aef60(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_001b3534(DAT_001aefb0);
  *param_1 = uVar1;
  uVar1 = FUN_001b3534(DAT_001aefb4);
  *param_2 = uVar1;
  return;
}



// ===== FUN_001af1fc deep-frame drain 0x30-0x34 @0x1af1fc =====

void FUN_001af1fc(int param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int local_2c [6];
  
  local_2c[3] = 0;
  for (local_2c[4] = 0; local_2c[4] < 2; local_2c[4] = local_2c[4] + 1) {
    local_2c[local_2c[4]] = *(int *)(param_1 + local_2c[4] * 4);
  }
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
    for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
      local_2c[2] = uVar2 * 2;
      uVar1 = FUN_001b3534(local_2c[2] + DAT_001af338);
      if (local_2c[1] != 0) {
        *(char *)(local_2c[1] + uVar2 + local_2c[3]) = (char)uVar1;
      }
      if (local_2c[0] != 0) {
        *(char *)(local_2c[0] + uVar2 + local_2c[3]) = (char)((ushort)uVar1 >> 8);
      }
    }
    local_2c[3] = local_2c[3] + 5;
  }
  return;
}



// ===== FUN_001ae850 coupling 0x22 @0x1ae850 =====

void FUN_001ae850(byte param_1)

{
  FUN_001b3500(DAT_001ae88c,param_1 & 3);
  return;
}



// ===== FUN_00075ad4 offset/cal volts->code @0x75ad4 =====

int FUN_00075ad4(byte param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  uint in_fpscr;
  float fVar5;
  short local_e;
  float fStack_c;
  
  iVar2 = FUN_00078d94();
  psVar4 = (short *)(DAT_00075e80 +
                    (uint)param_1 * 0xf0 + *(char *)(DAT_00075e84 + (uint)param_1 * 0x10 + 5) * 0x14
                    );
  sVar1 = FUN_001ee760(param_1);
  iVar3 = FUN_001597d4(param_1,2);
  if (iVar3 == 1) {
    fVar5 = (float)VectorSignedToFloat((int)(short)(sVar1 + -0xe6),(byte)(in_fpscr >> 0x16) & 3);
    fStack_c = (fVar5 * *(float *)(psVar4 + 2)) /
               *(float *)(DAT_00075e88 +
                         ((uint)param_1 * 0xc +
                         (int)*(char *)(DAT_00075e84 + (uint)param_1 * 0x10 + 5)) * 4);
  }
  else {
    fStack_c = (float)VectorSignedToFloat((int)(short)(sVar1 + -0xe6),(byte)(in_fpscr >> 0x16) & 3);
    fStack_c = fStack_c * *(float *)(psVar4 + 2);
  }
  fStack_c = fStack_c + DAT_00075e7c;
  iVar3 = FUN_001597d4(param_1,0);
  if (iVar3 == 1) {
    iVar3 = FUN_001597d4(param_1,4);
    if (iVar3 == 1) {
      fVar5 = (float)VectorSignedToFloat((uint)(ushort)psVar4[9],(byte)(in_fpscr >> 0x16) & 3);
      local_e = (short)(int)(fVar5 - fStack_c);
    }
    else {
      fVar5 = (float)VectorSignedToFloat((uint)(ushort)psVar4[9],(byte)(in_fpscr >> 0x16) & 3);
      local_e = (short)(int)(fVar5 + fStack_c);
    }
  }
  else {
    iVar3 = FUN_001597d4(param_1,4);
    if (iVar3 == 1) {
      fVar5 = (float)VectorSignedToFloat((uint)(ushort)psVar4[4],(byte)(in_fpscr >> 0x16) & 3);
      local_e = (short)(int)(fVar5 - fStack_c);
    }
    else {
      fVar5 = (float)VectorSignedToFloat((uint)(ushort)psVar4[4],(byte)(in_fpscr >> 0x16) & 3);
      local_e = (short)(int)(fVar5 + fStack_c);
    }
  }
  if (param_1 == 0) {
    if (((iVar2 == 8) || (iVar2 == 9)) || (iVar2 == 0xb)) {
      FUN_00076440((int)*psVar4,0x10);
      iVar3 = FUN_00076440((int)local_e,0x20);
    }
    else if (iVar2 == 0) {
      FUN_00076440((int)*psVar4,0x10);
      iVar3 = FUN_00076440((int)local_e,0x20);
    }
  }
  else if (((iVar2 == 8) || (iVar2 == 10)) || (iVar2 == 0xb)) {
    FUN_00076440((int)*psVar4,0x11);
    iVar3 = FUN_00076440((int)local_e,0x21);
  }
  else if (iVar2 == 1) {
    FUN_00076440((int)*psVar4,0x11);
    iVar3 = FUN_00076440((int)local_e,0x21);
  }
  return iVar3;
}



// ===== FUN_001adbcc offset-DAC fanout @0x1adbcc =====

uint FUN_001adbcc(uint param_1,ushort param_2)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  switch(param_1 & 0xff) {
  case 2:
    local_c = DAT_001add68;
    local_10 = DAT_001add6c;
    break;
  case 3:
    local_c = DAT_001add78;
    local_10 = DAT_001add7c;
    break;
  default:
    break;
  case 8:
    local_c = DAT_001add70;
    local_10 = DAT_001add74;
    break;
  case 0x20:
    local_c = DAT_001add58;
    local_10 = DAT_001add5c;
    break;
  case 0x21:
    local_c = DAT_001add60;
    local_10 = DAT_001add64;
  }
  if ((local_c != 0) && (local_10 != 0)) {
    FUN_001adfdc(local_10,param_2 & 0xff);
    param_1 = FUN_001adfdc(local_c,(int)((int)(short)param_2 & 0xff00U) >> 8);
  }
  return param_1;
}



