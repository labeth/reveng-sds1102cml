// Decompiled reference: every FUN_ address the open specs cite, from
// SDS1000_arm.app (md5 e1bd88fb, base 0x8000). Ghidra 12.1.2 ARM:LE:32:v8.

// ===== FUN_0000c9b8 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setitimer(__itimer_which_t __which,itimerval *__new,itimerval *__old)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000c9c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_002b22f8)(__which);
  return iVar1;
}



// ===== FUN_000156d8 =====

void FUN_000156d8(uint param_1)

{
  sleep(param_1);
  return;
}



// ===== FUN_00017e34 =====

int FUN_00017e34(char *param_1)

{
  ostream *poVar1;
  LogMessageFatal aLStack_14 [8];
  int local_c;
  
  if (param_1 == (char *)0x0) {
    google::LogMessageFatal::LogMessageFatal(aLStack_14,DAT_00017edc,DAT_00017ee0);
    poVar1 = (ostream *)google::LogMessage::stream();
    std::operator<<(poVar1,DAT_00017ee4);
    google::LogMessageFatal::~LogMessageFatal(aLStack_14);
  }
  local_c = system(param_1);
  if (local_c < 0) {
    FUN_00018eb8(param_1);
    printf(DAT_00017ee8,param_1);
  }
  return local_c;
}



// ===== FUN_00029ed4 =====

void FUN_00029ed4(int param_1,int param_2)

{
  ostream *poVar1;
  LogMessage aLStack_10 [8];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    google::LogMessage::LogMessage(aLStack_10,DAT_00029f84,0x5b,2);
    poVar1 = (ostream *)google::LogMessage::stream();
    std::operator<<(poVar1,DAT_00029f88);
    google::LogMessage::~LogMessage(aLStack_10);
  }
  else {
    *DAT_00029f7c = param_1;
    *DAT_00029f80 = param_2;
  }
  return;
}



// ===== FUN_00029f8c =====

void FUN_00029f8c(void)

{
  ostream *poVar1;
  LogMessage aLStack_10 [8];
  
  if (*DAT_0002a01c == 0) {
    google::LogMessage::LogMessage(aLStack_10,DAT_0002a020,0x71,2);
    poVar1 = (ostream *)google::LogMessage::stream();
    std::operator<<(poVar1,DAT_0002a024);
    google::LogMessage::~LogMessage(aLStack_10);
  }
  else {
    (*(code *)*DAT_0002a01c)();
  }
  return;
}



// ===== FUN_0002a028 =====

void FUN_0002a028(void)

{
  ostream *poVar1;
  LogMessage aLStack_10 [8];
  
  if (*DAT_0002a0bc == 0) {
    google::LogMessage::LogMessage(aLStack_10,DAT_0002a0c0,0x87,2);
    poVar1 = (ostream *)google::LogMessage::stream();
    std::operator<<(poVar1,DAT_0002a0c4);
    google::LogMessage::~LogMessage(aLStack_10);
  }
  else {
    (*(code *)*DAT_0002a0bc)();
  }
  return;
}



// ===== FUN_0002a2d8 =====

void FUN_0002a2d8(void)

{
  undefined4 *puVar1;
  int iVar2;
  ostream *poVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  LogMessage aLStack_10 [8];
  
  FUN_0000e950(DAT_0002a3f4,0xf);
  local_18 = DAT_0002a3f8;
  FUN_0002a540(DAT_0002a3fc,&local_18);
  FUN_0002a588(&local_1c);
  local_1c = FUN_0002a5b8(DAT_0002a3fc);
  while( true ) {
    local_14 = FUN_0002a5f4(DAT_0002a3fc);
    iVar2 = FUN_0002a62c(&local_1c,&local_14);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)FUN_0002a6a8(&local_1c);
    (*(code *)*puVar1)(DAT_0002a3f4);
    FUN_0002a670(&local_1c);
  }
  FUN_000161b0(0xe,DAT_0002a400);
  google::LogMessage::LogMessage(aLStack_10,DAT_0002a404,DAT_0002a408);
  poVar3 = (ostream *)google::LogMessage::stream();
  std::operator<<(poVar3,DAT_0002a40c);
  google::LogMessage::~LogMessage(aLStack_10);
  do {
    FUN_0000e848(DAT_0002a3f4,0x1000,0);
  } while( true );
}



// ===== FUN_0004bb38 =====

undefined4 FUN_0004bb38(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ifstream aiStack_1b4 [144];
  ios aiStack_124 [136];
  char acStack_9c [100];
  undefined1 auStack_38 [20];
  undefined4 local_24;
  int local_20;
  void *local_1c;
  void *local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = (void *)0x0;
  local_1c = (void *)0x0;
  local_20 = 0;
  memset(acStack_9c,0,100);
  local_24 = 0;
  FUN_000425d0(DAT_0004bdd8);
  std::ifstream::ifstream(aiStack_1b4,DAT_0004bdd8,4);
  pvVar1 = std::ios::operator_cast_to_void_(aiStack_124);
  uVar2 = DAT_0004bddc;
  if (pvVar1 != (void *)0x0) {
    std::istream::seekg(aiStack_1b4);
    std::istream::tellg();
    uVar3 = FUN_00046074(auStack_38);
    local_14 = (int)uVar3;
    std::istream::seekg(aiStack_1b4,(int)((ulonglong)uVar3 >> 0x20),0,0,0);
    local_1c = operator_new__(local_14 + 0x98);
    if (local_1c == (void *)0x0) {
      puts(DAT_0004bde0);
      uVar2 = DAT_0004bddc;
    }
    else {
      std::istream::read((char *)aiStack_1b4,(int)local_1c + 0x98);
      std::ifstream::close();
      sprintf(acStack_9c,DAT_0004bde4,DAT_0004bdd8);
      FUN_00017e34(acStack_9c);
      local_18 = local_1c;
      FUN_000424cc((int)local_1c + 4);
      local_20 = (int)local_18 + 4;
      FUN_00012e0c(local_18,local_20,local_14 + 0x94);
      FUN_0001ccb4(param_1,local_1c,local_14 + 0x98);
      local_24 = FUN_00018394(DAT_0004bde8,DAT_0004bdec);
      FUN_000185b8(local_1c,1,local_14 + 0x98,local_24);
      FUN_00018704(local_24);
      local_24 = 0;
      printf(DAT_0004bdf0,local_14 + 0x98);
      sprintf(acStack_9c,DAT_0004bde4,DAT_0004bde8);
      FUN_00017e34(acStack_9c);
      FUN_00017e34(DAT_0004bdf4);
      if (local_1c != (void *)0x0) {
        operator_delete__(local_1c);
      }
      uVar2 = 1;
    }
  }
  std::ifstream::~ifstream(aiStack_1b4);
  return uVar2;
}



// ===== FUN_00072584 =====

int FUN_00072584(byte *param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  byte *local_10;
  int local_c;
  
  iVar4 = FUN_00015e18(param_2);
  if ((param_1 != (byte *)0x0) && (iVar4 != 0)) {
    for (local_c = 0; local_c < (int)param_2; local_c = local_c + 1) {
      *(byte *)(iVar4 + local_c) = param_1[local_c];
    }
    iVar1 = (int)param_2 / 2;
    for (local_c = 0; local_c < iVar1 / 2; local_c = local_c + 1) {
      uVar2 = *(undefined1 *)(iVar4 + local_c);
      uVar3 = *(undefined1 *)(iVar4 + (param_2 - iVar1) + local_c);
      *(undefined1 *)(iVar4 + local_c) = *(undefined1 *)(iVar4 + (iVar1 - local_c) + -1);
      *(undefined1 *)(iVar4 + (param_2 - iVar1) + local_c) =
           *(undefined1 *)(iVar4 + (param_2 - local_c) + -1);
      *(undefined1 *)(iVar4 + (iVar1 - local_c) + -1) = uVar2;
      *(undefined1 *)(iVar4 + (param_2 - local_c) + -1) = uVar3;
    }
    for (local_c = 0; local_c < iVar1; local_c = local_c + 1) {
      param_1[local_c] = *(byte *)(iVar4 + (param_2 - iVar1) + local_c);
    }
    for (local_c = 0; local_c < iVar1; local_c = local_c + 1) {
      param_1[(param_2 - iVar1) + local_c] = *(byte *)(iVar4 + local_c);
    }
    if ((param_2 & 1) != 0) {
      param_1[(param_2 - iVar1) + -1] = *(byte *)(iVar4 + (param_2 - iVar1) + -1);
    }
    for (local_c = 0; local_c < iVar1; local_c = local_c + 1) {
      param_1[(param_2 - iVar1) + local_c] = ~param_1[(param_2 - iVar1) + local_c];
    }
    local_c = 0;
    local_10 = param_1;
    while( true ) {
      local_c = local_c + 1;
      local_10 = local_10 + local_c;
      if ((int)param_2 <= (int)local_10 - (int)param_1) break;
      *local_10 = ~*local_10;
    }
    iVar4 = FUN_00015f28(iVar4);
  }
  return iVar4;
}



// ===== FUN_00072974 =====

bool FUN_00072974(int param_1,uint param_2,int param_3)

{
  uint local_14;
  uint local_10;
  
  local_14 = 0;
  for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
    local_14 = local_14 + *(byte *)(param_1 + local_10);
  }
  return ~local_14 + 1 == param_3;
}



// ===== FUN_00074fd4 =====

undefined4 FUN_00074fd4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_00016070(DAT_0007516c,0,0x10000);
  puVar1 = DAT_0007516c;
  iVar2 = FUN_00018394(DAT_00075170,DAT_00075174);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    FUN_00018508(DAT_0007516c,1,0xac0,iVar2);
    FUN_00018704(iVar2);
    uVar3 = DAT_00075178;
    iVar2 = FUN_00072974(DAT_00075178,0xabc,*puVar1);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      FUN_00072584(uVar3,0xabc);
      uVar3 = FUN_001c0ea0(puVar1 + 0x2aa);
      iVar2 = FUN_00072974(puVar1 + 0x2ab,0x14,uVar3);
      if ((iVar2 == 0) || (puVar1[0x2ab] != 0x18)) {
        uVar3 = 0;
      }
      else {
        FUN_000cca94(puVar1 + 0x2ac);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}



// ===== FUN_00075ad4 =====

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



// ===== FUN_00076440 =====

undefined4 FUN_00076440(undefined4 param_1,byte param_2)

{
  short sVar1;
  
  sVar1 = (short)param_1;
  if (*(int *)(DAT_000765d8 + 4) != 1) {
    switch(param_2) {
    case 2:
      param_1 = FUN_001adbcc(param_2,(int)sVar1);
      break;
    case 3:
      param_1 = FUN_001adbcc(param_2,(int)sVar1);
      break;
    default:
      break;
    case 8:
      param_1 = FUN_001adbcc(param_2,(int)sVar1);
      break;
    case 9:
    case 10:
      param_1 = FUN_001adbcc(param_2,(int)sVar1);
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      *(char *)(DAT_000765dc + (param_2 - 0x10)) = (char)param_1;
      param_1 = FUN_001b1b54(DAT_000765dc);
      break;
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
      *(short *)(DAT_000765e0 + (param_2 - 0x20) * 2) = sVar1;
      param_1 = FUN_001adbcc(param_2,(int)sVar1);
    }
  }
  return param_1;
}



// ===== FUN_00076bbc =====

void FUN_00076bbc(byte param_1)

{
  undefined4 auStack_10 [3];
  
  auStack_10[0] = *DAT_00076c18;
  auStack_10[1] = DAT_00076c18[1];
  *(undefined1 *)(DAT_00076c1c + (uint)param_1) = *(undefined1 *)auStack_10[param_1];
  return;
}



// ===== FUN_00076c54 =====

void FUN_00076c54(byte param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 auStack_18 [3];
  
  auStack_18[0] = *DAT_00076d40;
  auStack_18[1] = DAT_00076d40[1];
  if ((*(char *)(DAT_00076d44 + (uint)param_1 * 0x10 + 5) == '\0') ||
     (*(float *)(DAT_00076d44 + (uint)param_1 * 0x10 + 8) < *(float *)(DAT_00076d48 + 4))) {
    *(undefined1 *)auStack_18[param_1] = 1;
  }
  else {
    puVar2 = (undefined1 *)auStack_18[param_1];
    uVar1 = FUN_00076c20(param_1);
    *puVar2 = uVar1;
  }
  return;
}



// ===== FUN_000796c0 =====

void FUN_000796c0(uint param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  int local_14;
  int local_10;
  byte local_9;
  
  uVar2 = DAT_0007a668;
                    /* WARNING: Could not recover jumptable at 0x000796e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (4 < *(byte *)(DAT_0007a660 + 0x40)) {
    if (local_10 < -300) {
      local_10 = DAT_0007a66c;
      if (*(byte *)(DAT_0007a660 + 0x40) < 3) {
        *(int *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c) = DAT_0007a66c;
        uVar2 = param_1;
      }
      else if (*(char *)(DAT_0007a660 + 0x40) == '\x03') {
        *(int *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c + 0x70) = DAT_0007a66c;
      }
      else if (*(char *)(DAT_0007a664 + (uint)local_9 * 0x3c + 8) == '\x03') {
        *(int *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x1c0) = DAT_0007a66c;
      }
      else {
        *(int *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x150) = DAT_0007a66c;
      }
      if (param_2 == '\x01') {
        iVar1 = FUN_001c15c8(uVar2);
        if (iVar1 == 4) {
          if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          else {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
        }
        else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        else {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        *DAT_0007a688 = 0xb;
        FUN_001ea260();
      }
    }
    else if (300 < local_10) {
      local_10 = 300;
      if (*(byte *)(DAT_0007a660 + 0x40) < 3) {
        *(undefined4 *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c) = 300;
        uVar2 = param_1;
      }
      else if (*(char *)(DAT_0007a660 + 0x40) == '\x03') {
        *(undefined4 *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c + 0x70) = 300;
      }
      else if (*(char *)(DAT_0007a664 + (uint)local_9 * 0x3c + 8) == '\x03') {
        *(undefined4 *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x1c0) = 300;
      }
      else {
        *(undefined4 *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x150) = 300;
      }
      if (param_2 == '\x01') {
        iVar1 = FUN_001c15c8(uVar2);
        if (iVar1 == 4) {
          if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          else {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
        }
        else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        else {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        *DAT_0007a688 = 0xb;
        FUN_001ea260();
      }
    }
    if (*(char *)(DAT_0007a660 + 0x40) == '\x03') {
      if (local_14 < 0x12d) {
        if (local_14 < -300) {
          local_14 = DAT_0007a66c;
          *(int *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c + 0xe0) = DAT_0007a66c
          ;
          if (param_2 == '\x01') {
            iVar1 = FUN_001c15c8();
            if (iVar1 == 4) {
              if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
                FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                             0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0
                             ,1,0);
              }
              else {
                FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                             0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),
                             0,1,0);
              }
            }
            else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
              FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1
                           ,0);
            }
            else {
              FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,
                           1,0);
            }
            *DAT_0007a688 = 0xb;
            FUN_001ea260();
          }
        }
      }
      else {
        local_14 = 300;
        *(undefined4 *)(DAT_0007a668 + (uint)*(byte *)(DAT_0007a654 + 0x20) * 0x1c + 0xe0) = 300;
        if (param_2 == '\x01') {
          iVar1 = FUN_001c15c8();
          if (iVar1 == 4) {
            if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
              FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1
                           ,0);
            }
            else {
              FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,
                           1,0);
            }
          }
          else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
            FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          else {
            FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          *DAT_0007a688 = 0xb;
          FUN_001ea260();
        }
      }
    }
    else if ((*(char *)(DAT_0007a660 + 0x40) == '\x04') &&
            (*(char *)(DAT_0007a664 + (uint)local_9 * 0x3c + 8) != '\x03')) {
      if (local_14 < 0x12d) {
        if (local_14 < -300) {
          local_14 = DAT_0007a66c;
          *(int *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x230) = DAT_0007a66c;
          if (param_2 == '\x01') {
            iVar1 = FUN_001c15c8();
            if (iVar1 == 4) {
              if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
                FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                             0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0
                             ,1,0);
              }
              else {
                FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                             0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),
                             0,1,0);
              }
            }
            else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
              FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1
                           ,0);
            }
            else {
              FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,
                           1,0);
            }
            *DAT_0007a688 = 0xb;
            FUN_001ea260();
          }
        }
      }
      else {
        local_14 = 300;
        *(undefined4 *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x230) = 300;
        if (param_2 == '\x01') {
          iVar1 = FUN_001c15c8();
          if (iVar1 == 4) {
            if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
              FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1
                           ,0);
            }
            else {
              FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,
                           0x140,0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,
                           1,0);
            }
          }
          else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
            FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          else {
            FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          *DAT_0007a688 = 0xb;
          FUN_001ea260();
        }
      }
    }
    else if ((*(char *)(DAT_0007a660 + 0x40) == '\x04') &&
            ((*(char *)(DAT_0007a664 + (uint)local_9 * 0x3c + 8) == '\x03' && (local_14 < -300)))) {
      local_14 = DAT_0007a66c;
      *(int *)(DAT_0007a668 + (uint)local_9 * 0x1c + 0x230) = DAT_0007a66c;
      if (param_2 == '\x01') {
        iVar1 = FUN_001c15c8();
        if (iVar1 == 4) {
          if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
          else {
            FUN_000ab830(*(undefined4 *)(DAT_0007a670 + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                         0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
          }
        }
        else if (*(char *)(DAT_0007a674 + 0x50) == '\0') {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0xdc,0x168,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        else {
          FUN_000ab830(*(undefined4 *)(DAT_0007a67c + (uint)*DAT_0007a678 * 4),DAT_0007a684,0x140,
                       0x110,0x100,0x19,0xffffff,1,*(undefined4 *)(DAT_0007a680 + 0x44),0,1,0);
        }
        *DAT_0007a688 = 0xb;
        FUN_001ea260();
      }
    }
    FUN_00075e8c(local_9,-(local_10 >> 1),-(local_14 >> 1));
    if (((param_1 & 0xff) == 1) || ((param_1 & 0xff) == 2)) {
      FUN_00077e00();
    }
    return;
  }
  (*(code *)(&switchD_000796e8::switchdataD_000796f0)[*(byte *)(DAT_0007a660 + 0x40)])();
  return;
}



// ===== FUN_000b5bf4 =====

void FUN_000b5bf4(void)

{
  int iVar1;
  void *pvVar2;
  int local_c;
  
  FUN_00017e34(DAT_000b5dc0);
  FUN_00017e34(DAT_000b5dc4);
  FUN_00017e34(DAT_000b5dc8);
  FUN_00017e34(DAT_000b5dcc);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    iVar1 = open(DAT_000b5dd0,2);
    *DAT_000b5dd4 = iVar1;
    if (-1 < *DAT_000b5dd4) break;
    if (local_c == 3) {
      FUN_00017e34(DAT_000b5dd8);
    }
    else {
      FUN_000156d8(1);
    }
  }
  iVar1 = ioctl(*DAT_000b5dd4,0x4600,DAT_000b5ddc);
  if (iVar1 != 0) {
    printf(DAT_000b5de0);
                    /* WARNING: Subroutine does not return */
    exit(2);
  }
  *DAT_000b5de4 = ((uint)DAT_000b5ddc[6] >> 3) * DAT_000b5ddc[1] * *DAT_000b5ddc;
  pvVar2 = mmap((void *)0x0,*DAT_000b5de4,3,1,*DAT_000b5dd4,0);
  *DAT_000b5de8 = (int)pvVar2;
  if (*DAT_000b5de8 != -1) {
    printf(DAT_000b5dec,*DAT_000b5ddc);
    printf(DAT_000b5df0,DAT_000b5ddc[1]);
    printf(DAT_000b5df4,DAT_000b5ddc[6]);
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(3);
}



// ===== FUN_000b5f34 =====

void FUN_000b5f24(void)

{
  puts(DAT_000b5f44);
  FUN_000b5bf4();
  return;
}



// ===== FUN_000b65b4 =====
// (no function)

// ===== FUN_000b65e4 =====

void FUN_000b65e4(void)

{
  int iVar1;
  __pid_t _Var2;
  uint uVar3;
  
  iVar1 = open(DAT_000b6690,2);
  *DAT_000b6694 = iVar1;
  if (*DAT_000b6694 < 0) {
    perror(DAT_000b6698);
  }
  signal(0x1d,DAT_000b669c);
  iVar1 = *DAT_000b6694;
  _Var2 = getpid();
  fcntl(iVar1,8,_Var2);
  uVar3 = fcntl(*DAT_000b6694,3);
  fcntl(*DAT_000b6694,4,uVar3 | 0x2000);
  return;
}



// ===== FUN_0000c898 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Could not recover jumptable at 0x0000c8a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_002b2298)(__status);
  return;
}



// ===== FUN_0000c8a4 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000c8ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_002b229c)(__format);
  return iVar1;
}



// ===== FUN_0000cb5c =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000cb64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_002b2384)(__fd);
  return iVar1;
}



// ===== FUN_000cbf04 =====

uint FUN_000cbf04(uint param_1,byte param_2)

{
  undefined1 local_1c [2];
  undefined2 local_1a;
  ushort local_18;
  undefined4 local_c;
  
  local_c = 0;
  if (-1 < *DAT_000cbf9c) {
    local_1c[0] = 3;
    local_1a = (undefined2)((param_1 & 0xffff) >> 1);
    local_18 = (ushort)param_2;
    param_1 = ioctl(*DAT_000cbf9c,DAT_000cbfa0,local_1c);
  }
  return param_1;
}



// ===== FUN_000cc184 =====

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



// ===== FUN_000cc224 =====

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



// ===== FUN_0000cc28 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000cc30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_002b23c8)(__file);
  return iVar1;
}



// ===== FUN_000cc628 =====

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



// ===== FUN_000cc80c =====

void FUN_000cc80c(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  
  uVar3 = 0;
  iVar1 = FUN_001c15c8();
  FUN_000b5920(DAT_000cc944);
  iVar2 = FUN_001c1544();
  local_10 = 0xffffff;
  if ((iVar1 != 1) && (iVar1 != 6)) {
    local_10 = 0xff0000;
  }
  if ((iVar1 != 0) && (iVar2 != 0)) {
    if (iVar1 == 4) {
      FUN_0008bf60(0x168,DAT_000cc94c,DAT_000cc948,local_10);
    }
    else if (iVar1 == 6) {
      FUN_0008c080(0x104,DAT_000cc94c,DAT_000cc948,local_10,6,uVar3);
    }
    else {
      FUN_0008c080(0x154,DAT_000cc94c,DAT_000cc948,local_10,iVar1,uVar3);
    }
  }
  if (iVar1 == 1) {
    FUN_0008bed0(0x1b8,0x164,DAT_000cc950,local_10);
  }
  FUN_000df11c();
  FUN_001ada64(0x80);
  return;
}



// ===== FUN_000cca94 =====

void * FUN_000cca94(void *param_1)

{
  void *pvVar1;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = memcpy(DAT_000ccad4,param_1,0x10);
  }
  return pvVar1;
}



// ===== FUN_000cde34 =====

void FUN_000cde34(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0x18;
  local_10 = 3;
  local_14 = DAT_000cdf24;
  iVar1 = open(DAT_000cdf28,2);
  *DAT_000cdf2c = iVar1;
  ioctl(*DAT_000cdf2c,DAT_000cdf30,&local_c);
  ioctl(*DAT_000cdf2c,DAT_000cdf34,&local_c);
  ioctl(*DAT_000cdf2c,DAT_000cdf38,&local_10);
  ioctl(*DAT_000cdf2c,DAT_000cdf3c,&local_10);
  ioctl(*DAT_000cdf2c,DAT_000cdf40,&local_14);
  ioctl(*DAT_000cdf2c,DAT_000cdf44,&local_14);
  return;
}



// ===== FUN_000ce170 =====

void FUN_000ce170(void)

{
  FUN_000cde34();
  FUN_000cdf48();
  return;
}



// ===== FUN_000ce18c =====

undefined4 FUN_000ce18c(undefined4 param_1)

{
  int *piVar1;
  undefined4 local_18;
  int local_14;
  
  local_14 = 0;
  *(undefined1 *)((int)DAT_000ce22c + 0x1a) = 0x18;
  DAT_000ce22c[4] = 4;
  piVar1 = DAT_000ce22c;
  *DAT_000ce22c = (int)&local_18;
  piVar1[1] = 0;
  piVar1 = DAT_000ce22c;
  DAT_000ce22c[2] = 0;
  piVar1[3] = 0;
  local_18 = param_1;
  local_14 = ioctl(*DAT_000ce230,DAT_000ce234,DAT_000ce22c);
  if (local_14 < 0) {
    puts(DAT_000ce238);
  }
  return 1;
}



// ===== FUN_000ce23c =====

undefined4 FUN_000ce23c(byte param_1)

{
  int *piVar1;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = (uint)param_1;
  *(undefined1 *)((int)DAT_000ce2e0 + 0x1a) = 8;
  DAT_000ce2e0[4] = 1;
  piVar1 = DAT_000ce2e0;
  *DAT_000ce2e0 = (int)&local_18;
  piVar1[1] = 0;
  piVar1 = DAT_000ce2e0;
  DAT_000ce2e0[2] = 0;
  piVar1[3] = 0;
  local_14 = ioctl(*DAT_000ce2e4,DAT_000ce2e8,DAT_000ce2e0);
  if (local_14 < 0) {
    puts(DAT_000ce2ec);
  }
  return 1;
}



// ===== FUN_000ce2f0 =====

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



// ===== FUN_000ce5e0 =====

void FUN_000ce5e0(void)

{
  FUN_00017e34(DAT_000ce608);
  return;
}



// ===== FUN_000ce60c =====

void FUN_000ce60c(void)

{
  FUN_00017e34(DAT_000ce634);
  return;
}



// ===== FUN_000cebac =====

undefined4 FUN_000cebac(void)

{
  undefined4 local_c;
  
  local_c = 0;
  FUN_000ceac0(&local_c);
  return local_c;
}



// ===== FUN_000cec40 =====

void FUN_000cec40(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(char *)(DAT_000ced7c + 0x10) != '\t') {
    if (*DAT_000ced80 == '\0') {
      *DAT_000ced80 = '\x01';
      uVar1 = FUN_000cebac();
      *DAT_000ced84 = uVar1;
    }
    uVar3 = *DAT_000ced84;
    uVar1 = FUN_000cebac();
    uVar2 = FUN_000cebe0(uVar3,uVar1);
    if (((uint)(*DAT_000ced88 * 100) <= uVar2) && (*DAT_000ced8c == '\0')) {
      *DAT_000ced90 = '\x01';
      *DAT_000ced8c = '\x01';
      FUN_001ada64(0x7f);
      *DAT_000ced94 = '\0';
    }
    if ((*DAT_000ced94 == '\x01') && (*DAT_000ced90 == '\x01')) {
      *DAT_000ced90 = '\0';
      *DAT_000ced80 = '\0';
      FUN_001ada64(0x80);
      uVar1 = FUN_000cebac();
      *DAT_000ced84 = uVar1;
      *DAT_000ced8c = '\0';
      FUN_000db640(0);
      FUN_00219098();
    }
  }
  return;
}



// ===== FUN_000d3148 =====

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



// ===== FUN_000df11c =====

void FUN_000df11c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  
  FUN_001986e8();
  iVar4 = FUN_000b5e54();
  iVar2 = DAT_000df258;
  iVar1 = DAT_000df254;
  *DAT_000df25c = 0;
  uVar3 = DAT_000df260;
  FUN_0023001c();
  if (*(char *)(DAT_000df264 + 0x20) == '\0') {
    for (uVar9 = 0; uVar9 < uVar3; uVar9 = uVar9 + 1) {
      puVar10 = (uint *)(iVar4 + uVar9 * 8);
      puVar6 = (uint *)(iVar1 + uVar9 * 8);
      uVar5 = puVar6[1];
      puVar7 = (uint *)(iVar2 + uVar9 * 8);
      uVar8 = puVar7[1];
      *puVar10 = *puVar7 | *puVar6;
      puVar10[1] = uVar8 | uVar5;
    }
  }
  else {
    for (uVar9 = 0; uVar9 < uVar3; uVar9 = uVar9 + 1) {
      puVar10 = (uint *)(iVar4 + uVar9 * 8);
      puVar6 = (uint *)(iVar1 + uVar9 * 8);
      uVar5 = puVar6[1];
      puVar7 = (uint *)(iVar2 + uVar9 * 8);
      uVar8 = puVar7[1];
      *puVar10 = *puVar7 & *puVar6;
      puVar10[1] = uVar8 & uVar5;
    }
  }
  FUN_0023003c();
  *DAT_000df25c = 1;
  return;
}



// ===== FUN_001597d4 =====

undefined1 FUN_001597d4(byte param_1,byte param_2)

{
  undefined4 auStack_3c [4];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 local_9;
  
  local_9 = 0xff;
  auStack_3c[0] = *DAT_00159884;
  auStack_3c[1] = DAT_00159884[1];
  auStack_3c[2] = DAT_00159884[2];
  auStack_3c[3] = DAT_00159884[3];
  uStack_2c = DAT_00159884[4];
  uStack_28 = DAT_00159884[5];
  uStack_24 = DAT_00159884[6];
  uStack_20 = DAT_00159884[7];
  uStack_1c = DAT_00159884[8];
  uStack_18 = DAT_00159884[9];
  uStack_14 = DAT_00159884[10];
  uStack_10 = DAT_00159884[0xb];
  if (param_1 < 2) {
    local_9 = *(undefined1 *)auStack_3c[(uint)param_1 * 6 + (uint)param_2];
  }
  else {
    local_9 = 0xff;
  }
  return local_9;
}



// ===== FUN_00159998 =====

int FUN_00159998(undefined1 param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float local_6c [16];
  float local_2c [7];
  byte local_d;
  float local_c;
  
  local_d = 0;
  local_2c[0] = *DAT_00159ad0;
  local_2c[1] = DAT_00159ad0[1];
  local_2c[2] = DAT_00159ad0[2];
  local_2c[3] = DAT_00159ad0[3];
  local_2c[4] = DAT_00159ad0[4];
  local_2c[5] = DAT_00159ad0[5];
  local_2c[6] = DAT_00159ad0[6];
  local_6c[0] = *DAT_00159ad4;
  local_6c[1] = DAT_00159ad4[1];
  local_6c[2] = DAT_00159ad4[2];
  local_6c[3] = DAT_00159ad4[3];
  local_6c[4] = DAT_00159ad4[4];
  local_6c[5] = DAT_00159ad4[5];
  local_6c[6] = DAT_00159ad4[6];
  local_6c[7] = DAT_00159ad4[7];
  local_6c[8] = DAT_00159ad4[8];
  local_6c[9] = DAT_00159ad4[9];
  local_6c[10] = DAT_00159ad4[10];
  local_6c[0xb] = DAT_00159ad4[0xb];
  local_6c[0xc] = DAT_00159ad4[0xc];
  local_6c[0xd] = DAT_00159ad4[0xd];
  local_6c[0xe] = DAT_00159ad4[0xe];
  local_6c[0xf] = DAT_00159ad4[0xf];
  local_c = (float)DAT_00159ad8;
  local_d = FUN_001597d4(param_1,3);
  iVar1 = FUN_001c15c8();
  iVar2 = 0;
  if ((iVar1 == 0) || (iVar2 = FUN_001c15c8(), iVar2 == 3)) {
    if (6 < local_d) {
      return iVar2;
    }
    local_c = local_2c[local_d];
  }
  else {
    if (0xf < local_d) {
      return iVar2;
    }
    local_c = local_6c[local_d];
  }
  *param_2 = *param_2 * local_c;
  return iVar2;
}



// ===== FUN_001986e8 =====

void FUN_001986e8(void)

{
  if (*DAT_00198724 == 0) {
    *DAT_00198724 = 1;
    FUN_000b5f24();
    FUN_001ad9f0();
    FUN_000b5f60();
  }
  return;
}



// ===== FUN_001ad9f0 =====

void FUN_001ad9f0(void)

{
  FUN_00017e34(DAT_001ada1c);
  FUN_00017e34(DAT_001ada20);
  FUN_00017e34(DAT_001ada24);
  return;
}



// ===== FUN_001ada28 =====

undefined1 FUN_001ada28(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_001adfb0(DAT_001ada60);
  return uVar1;
}



// ===== FUN_001ada64 =====

void FUN_001ada64(char param_1)

{
  if (param_1 == -0x80) {
    FUN_00017e34(DAT_001adaa4);
  }
  else {
    FUN_00017e34(DAT_001adaa8);
  }
  return;
}



// ===== FUN_001adbcc =====

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



// ===== FUN_001adfdc =====

void FUN_001adfdc(undefined4 param_1,undefined1 param_2)

{
  FUN_000cbf04(param_1,param_2);
  return;
}



// ===== FUN_001ae070 =====

void FUN_001ae070(void)

{
  FUN_001b3500(DAT_001ae0a8,0xc0);
  FUN_001b3500(DAT_001ae0ac,1);
  FUN_001b3500(DAT_001ae0ac,0);
  return;
}



// ===== FUN_001ae0b0 =====

void FUN_001ae0b0(void)

{
  FUN_001b3500(DAT_001ae0ec,1);
  FUN_001b3500(DAT_001ae0ec,0);
  FUN_002086f4();
  FUN_001b3500(DAT_001ae0f0,0xc3);
  return;
}



// ===== FUN_001ae0f4 =====

void FUN_001ae0f4(void)

{
  FUN_001b3500(DAT_001ae120,0);
  FUN_001b3500(DAT_001ae120,1);
  return;
}



// ===== FUN_001ae320 =====

void FUN_001ae320(void)

{
  FUN_001b3500(DAT_001ae340,1);
  return;
}



// ===== FUN_001ae344 =====

void FUN_001ae344(void)

{
  FUN_001b3500(DAT_001ae364,0);
  return;
}



// ===== FUN_001ae368 =====

void FUN_001ae368(uint param_1)

{
  FUN_001b3500(DAT_001ae3e0,param_1 & 0xff);
  FUN_001b3500(DAT_001ae3e4,param_1 >> 8 & 0xff);
  FUN_001b3500(DAT_001ae3e8,param_1 >> 0x10 & 0xff);
  FUN_001b3500(DAT_001ae3ec,param_1 >> 0x18);
  return;
}



// ===== FUN_001ae3f0 =====

void FUN_001ae3f0(undefined2 param_1,undefined2 param_2)

{
  FUN_001b3560(DAT_001ae438,param_2);
  FUN_001b3560(DAT_001ae43c,param_1);
  return;
}



// ===== FUN_001ae440 =====

void FUN_001ae440(undefined2 param_1,undefined2 param_2)

{
  FUN_001b3560(DAT_001ae488,param_2);
  FUN_001b3560(DAT_001ae48c,param_1);
  return;
}



// ===== FUN_001ae490 =====

void FUN_001ae490(undefined1 param_1,undefined1 param_2)

{
  FUN_001b3500(DAT_001ae4d8,param_2);
  FUN_001b3500(DAT_001ae4dc,param_1);
  return;
}



// ===== FUN_001ae4e0 =====

void FUN_001ae4e0(undefined1 param_1,undefined1 param_2)

{
  FUN_001b3500(DAT_001ae528,param_2);
  FUN_001b3500(DAT_001ae52c,param_1);
  return;
}



// ===== FUN_001ae530 =====

void FUN_001ae530(void)

{
  FUN_001b3500(DAT_001ae55c,1);
  FUN_001b3500(DAT_001ae55c,0);
  return;
}



// ===== FUN_001ae560 =====

void FUN_001ae560(undefined1 param_1)

{
  FUN_001b3500(DAT_001ae590,param_1);
  return;
}



// ===== FUN_001ae594 =====

undefined1 FUN_001ae594(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_001b34d4(DAT_001ae5c4);
  return uVar1;
}



// ===== FUN_001ae5fc =====

void FUN_001ae5fc(void)

{
  FUN_001b3500(DAT_001ae638,2);
  return;
}



// ===== FUN_001ae850 =====

void FUN_001ae850(byte param_1)

{
  FUN_001b3500(DAT_001ae88c,param_1 & 3);
  return;
}



// ===== FUN_001ae934 =====

void FUN_001ae934(uint param_1)

{
  FUN_001b3500(DAT_001ae984,param_1 & 0xff);
  FUN_001b3500(DAT_001ae988,(int)param_1 >> 8 & 0xff);
  FUN_001985a4(5);
  return;
}



// ===== FUN_001aef60 =====

void FUN_001aef60(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_001b3534(DAT_001aefb0);
  *param_1 = uVar1;
  uVar1 = FUN_001b3534(DAT_001aefb4);
  *param_2 = uVar1;
  return;
}



// ===== FUN_001af1fc =====

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



// ===== FUN_001afd60 =====

void FUN_001afd60(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20 [3];
  byte local_11;
  uint local_10;
  uint local_c;
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_c = 0;
  local_11 = 0;
  local_20[2] = 0;
  local_10 = (uint)*(byte *)((int)DAT_001b01b8 + 0x61);
  puVar1 = param_1;
  if (*(char *)(DAT_001b01bc + 0x40) == '\x04') {
    for (local_c = 0; (int)local_c < 2; local_c = local_c + 1) {
      if (*(byte *)(DAT_001b01c0 + 0x78) == local_c) {
        puVar1 = (undefined4 *)&stack0xfffffff8;
        local_20[local_c] = *(int *)param_1[local_c];
      }
      else {
        local_20[local_c] = *(int *)(param_1[local_c] + 8);
        puVar1 = memcpy((void *)(*(int *)param_1[local_c] + -1000),
                        (void *)(*(int *)(param_1[local_c] + 4) + -1000),DAT_001b01c4);
      }
    }
  }
  else if ((((local_10 == 8) || (local_10 == 0xb)) || (local_10 == 9)) || (local_10 == 10)) {
    for (local_c = 0; (int)local_c < 2; local_c = local_c + 1) {
      if (*(char *)(DAT_001b01c8 + local_c * 0x10 + 4) == '\x01') {
        puVar1 = (undefined4 *)&stack0xfffffff8;
        local_20[local_c] = *(int *)param_1[local_c];
      }
    }
  }
  else if (local_10 == 0) {
    local_20[0] = *(int *)*param_1;
  }
  else if (local_10 == 1) {
    local_20[1] = *(undefined4 *)param_1[1];
  }
  local_11 = FUN_001b3430(puVar1);
  if (((local_10 == 8) || (local_10 == 0xb)) || ((local_10 == 9 || (local_10 == 10)))) {
    iVar2 = FUN_0021b6a4();
    if (iVar2 == 1) {
      for (local_c = 0; (int)local_c < 2; local_c = local_c + 1) {
        if (local_20[local_c] != 0) {
          local_20[local_c] = local_20[local_c] + (uint)local_11;
        }
      }
    }
    local_20[2] = __aeabi_uidiv(*DAT_001b01b8,local_11);
    FUN_001af1fc(local_20,local_20[2]);
    FUN_0021df20(local_20,*DAT_001b01b8);
  }
  else {
    iVar2 = FUN_0021b6a4();
    if (iVar2 == 1) {
      for (local_c = 0; (int)local_c < 2; local_c = local_c + 1) {
        if (local_20[local_c] != 0) {
          local_20[local_c] = local_20[local_c] + (uint)local_11 * 2;
        }
      }
    }
    local_20[2] = __aeabi_uidiv(*DAT_001b01b8,(uint)local_11 << 1);
    FUN_001af03c(local_20,local_20[2]);
    FUN_0021df20(local_20,*DAT_001b01b8);
  }
  return;
}



// ===== FUN_001b035c =====

void FUN_001b035c(void)

{
  byte bVar1;
  
  bVar1 = FUN_001ae594();
  FUN_001ae560(bVar1 & 0xfd);
  return;
}



// ===== FUN_001b04e4 =====

bool FUN_001b04e4(void)

{
  byte bVar1;
  
  bVar1 = FUN_001ae5c8();
  return (bVar1 & 1) != 0;
}



// ===== FUN_001b0570 =====

void FUN_001b0570(undefined2 param_1)

{
  FUN_001b3560(DAT_001b05a0,param_1);
  return;
}



// ===== FUN_001b05a4 =====

void FUN_001b05a4(void)

{
  FUN_001b3560(DAT_001b05c4,0);
  return;
}



// ===== FUN_001b05c8 =====

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



// ===== FUN_001b06cc =====

bool FUN_001b06cc(void)

{
  byte bVar1;
  
  bVar1 = FUN_001b34d4(DAT_001b0714);
  return (bVar1 & 1) == 0;
}



// ===== FUN_001b0718 =====

void FUN_001b0718(undefined4 param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_001b06cc(param_1);
    param_1 = 0;
  } while (iVar1 == 0);
  return;
}



// ===== FUN_001b07dc =====

void FUN_001b07dc(void)

{
  FUN_001b3500(DAT_001b0814,0xc0);
  FUN_002086f4();
  FUN_001ae070();
  FUN_002086f4();
  FUN_001b3500(DAT_001b0814,0xc3);
  return;
}



// ===== FUN_001b0814 =====
// (no function)

// ===== FUN_001b083c =====

void FUN_001b083c(void)

{
  FUN_001b3500(DAT_001b085c,200);
  return;
}



// ===== FUN_001b0860 =====

void FUN_001b0860(void)

{
  FUN_001b3500(DAT_001b0880,0xcb);
  return;
}



// ===== FUN_001b0884 =====

void FUN_001b0884(void)

{
  FUN_001b3500(DAT_001b08a4,5);
  return;
}



// ===== FUN_001b0a40 =====

bool FUN_001b0a40(void)

{
  byte bVar1;
  
  bVar1 = FUN_001b34d4(DAT_001b0a88);
  return (bVar1 & 0x20) != 0;
}



// ===== FUN_001b0ba4 =====

short FUN_001b0ba4(void)

{
  short sVar1;
  short sVar2;
  
  sVar1 = FUN_001b34d4(DAT_001b0bfc);
  sVar2 = FUN_001b34d4(DAT_001b0c00);
  return sVar2 + sVar1 * 0x100;
}



// ===== FUN_001b0c04 =====

void FUN_001b0c04(undefined4 param_1)

{
  FUN_001ae320();
  FUN_001ae368(param_1);
  return;
}



// ===== FUN_001b0c0c =====

void FUN_001b0c04(undefined4 param_1)

{
  FUN_001ae320();
  FUN_001ae368(param_1);
  return;
}



// ===== FUN_001b0dc4 =====

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



// ===== FUN_001b107c =====

void FUN_001b107c(undefined2 param_1)

{
  FUN_001adfdc(DAT_001b10f8,0);
  FUN_001adfdc(DAT_001b10fc,(char)((ushort)param_1 >> 8));
  FUN_001adfdc(DAT_001b1100,(char)param_1);
  FUN_001adfdc(DAT_001b10f8,1);
  return;
}



// ===== FUN_001b1104 =====

uint FUN_001b1104(uint param_1)

{
  ushort local_a;
  
  if (*(int *)(DAT_001b12a4 + 4) != 1) {
    switch(param_1 & 0xff) {
    case 0:
      local_a = 0x4000;
      break;
    case 1:
      local_a = 2;
      break;
    case 2:
      local_a = 4;
      break;
    case 3:
      local_a = 8;
      break;
    case 4:
      local_a = 0x10;
      break;
    case 5:
      local_a = 0x20;
      break;
    case 6:
      local_a = 0x40;
      break;
    case 7:
      local_a = 0x80;
      break;
    case 8:
      local_a = 0x100;
      break;
    case 9:
      local_a = 0x200;
      break;
    case 10:
      local_a = 0x400;
      break;
    case 0xb:
      local_a = 0x800;
      break;
    case 0xc:
      local_a = 0x1000;
      break;
    case 0xd:
      local_a = 0x2000;
      break;
    case 0xe:
      local_a = 0x8000;
      break;
    case 0xf:
      local_a = 0;
      break;
    case 0x10:
      local_a = 0xffff;
    }
    *(ushort *)(DAT_001b12a8 + 0x6a) = *(ushort *)(DAT_001b12a8 + 0x6a) | local_a & 0xfffe;
    param_1 = FUN_001b107c(*(undefined2 *)(DAT_001b12a8 + 0x6a));
  }
  return param_1;
}



// ===== FUN_001b1460 =====

void FUN_001b1460(char param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_14;
  
  if (param_1 == '\x01') {
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      *(undefined4 *)(DAT_001b19dc + local_14 * 4) = 0xffffffff;
    }
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      DAT_001b19e0[local_14] = 0xffffffff;
    }
  }
  if (*DAT_001b19e4 == DAT_001b19e8) {
    FUN_001b1104(9);
  }
  else {
    FUN_001b12ac(9);
  }
  if ((((*DAT_001b19e4 == 0) || (*DAT_001b19e4 == DAT_001b19ec)) || (*DAT_001b19e4 == DAT_001b19f0))
     || ((*DAT_001b19e4 == DAT_001b19f4 || (*DAT_001b19e4 == DAT_001b19f8)))) {
LAB_001b1584:
    FUN_001b1104(8);
  }
  else {
    if (*DAT_001b19e4 == DAT_001b19fc) goto LAB_001b1584;
    FUN_001b12ac(8);
  }
  if (*DAT_001b19e4 == DAT_001b1a00) {
LAB_001b15e8:
    FUN_001b1104(0xb);
  }
  else {
    if (*DAT_001b19e4 == DAT_001b1a04) goto LAB_001b15e8;
    if (*DAT_001b19e4 == DAT_001b1a08) goto LAB_001b15e8;
    if (*DAT_001b19e4 == DAT_001b1a0c) goto LAB_001b15e8;
    FUN_001b12ac(0xb);
  }
  if (*DAT_001b19e4 == DAT_001b1a10) {
LAB_001b164c:
    FUN_001b1104(0xc);
  }
  else {
    if (*DAT_001b19e4 == DAT_001b1a14) goto LAB_001b164c;
    if (*DAT_001b19e4 == DAT_001b1a18) goto LAB_001b164c;
    if (*DAT_001b19e4 == DAT_001b1a1c) goto LAB_001b164c;
    FUN_001b12ac(0xc);
  }
  if (*DAT_001b19e4 == DAT_001b1a20) {
LAB_001b169c:
    FUN_001b1104(10);
  }
  else {
    if (*DAT_001b19e4 == DAT_001b1a24) goto LAB_001b169c;
    if (*DAT_001b19e4 == DAT_001b1a28) goto LAB_001b169c;
    FUN_001b12ac(10);
  }
  if (*(uint *)(DAT_001b19dc + 0x10) != (uint)*(byte *)(DAT_001b1a2c + 4)) {
    if (*(char *)(DAT_001b1a2c + 4) == '\x01') {
      FUN_001b1104(4);
    }
    else {
      FUN_001b12ac(4);
    }
    *(uint *)(DAT_001b19dc + 0x10) = (uint)*(byte *)(DAT_001b1a2c + 4);
  }
  if (*(uint *)(DAT_001b19dc + 0x18) != (uint)*(byte *)(DAT_001b1a2c + 0x14)) {
    if (*(char *)(DAT_001b1a2c + 0x14) == '\x01') {
      FUN_001b1104(6);
    }
    else {
      FUN_001b12ac(6);
    }
    *(uint *)(DAT_001b19dc + 0x18) = (uint)*(byte *)(DAT_001b1a2c + 0x14);
  }
  if (*(uint *)(DAT_001b19dc + 0x14) != (uint)*(byte *)(DAT_001b1a30 + 0x30)) {
    if (*(char *)(DAT_001b1a30 + 0x30) == '\x01') {
      FUN_001b1104(5);
    }
    else {
      FUN_001b12ac(5);
    }
    *(uint *)(DAT_001b19dc + 0x14) = (uint)*(byte *)(DAT_001b1a30 + 0x30);
  }
  bVar1 = FUN_001ab6a8(0);
  bVar2 = FUN_001ab6a8(1);
  if ((*DAT_001b19e0 != (uint)bVar1) || (DAT_001b19e0[1] != (uint)bVar2)) {
    if ((bVar1 == 1) || (bVar2 == 1)) {
      FUN_001b1104(7);
    }
    else {
      FUN_001b12ac(7);
    }
    *DAT_001b19e0 = (uint)bVar1;
    DAT_001b19e0[1] = (uint)bVar2;
  }
  if (*DAT_001b19e4 != DAT_001b1a34) {
    if (*DAT_001b19e4 != DAT_001b1a30) {
      if (*DAT_001b19e4 != DAT_001b1a38) {
        if ((*DAT_001b19e4 != DAT_001b1a3c) && (*(char *)(DAT_001b1a30 + 0x20) != '\0')) {
          FUN_001b12ac(1);
          goto LAB_001b18a8;
        }
      }
    }
  }
  FUN_001b1104(1);
LAB_001b18a8:
  if (*(uint *)(DAT_001b19dc + 0x38) != (uint)*(byte *)(DAT_001b1a40 + 0x40)) {
    if (*(char *)(DAT_001b1a40 + 0x40) == '\x02') {
      FUN_001b1104(0xe);
    }
    else {
      FUN_001b12ac(0xe);
    }
    *(uint *)(DAT_001b19dc + 0x38) = (uint)*(byte *)(DAT_001b1a40 + 0x40);
  }
  if (*(uint *)(DAT_001b19dc + 0x34) != (uint)*(byte *)(DAT_001b1a44 + 0x20)) {
    if (*(char *)(DAT_001b1a44 + 0x20) == '\0') {
      FUN_001b1104(0xd);
      FUN_001b12ac(0);
    }
    else {
      FUN_001b1104(0);
      FUN_001b12ac(0xd);
    }
    *(uint *)(DAT_001b19dc + 0x34) = (uint)*(byte *)(DAT_001b1a44 + 0x20);
  }
  iVar5 = *(int *)(DAT_001b19dc + 8);
  iVar3 = FUN_000d9538();
  if (iVar5 != iVar3) {
    iVar3 = FUN_000d9538();
    if (iVar3 == 0) {
      if (*DAT_001b19e4 != DAT_001b1a48) {
        if (*DAT_001b19e4 != DAT_001b1a4c) {
          FUN_001b12ac(2);
        }
      }
    }
    else {
      FUN_001b1104(2);
    }
    uVar4 = FUN_000d9538();
    *(undefined4 *)(DAT_001b19dc + 8) = uVar4;
  }
  return;
}



// ===== FUN_001b1a88 =====

uint FUN_001b1a7c(void)

{
  uint uVar1;
  
  uVar1 = FUN_001ada28();
  switch(uVar1 & 0xff) {
  case 0:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 3;
    break;
  case 1:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 2;
    break;
  case 2:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 1;
    break;
  case 3:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 0;
    break;
  case 4:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 4;
    break;
  case 5:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 5;
    break;
  default:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 3;
    break;
  case 7:
    *(undefined1 *)(DAT_001b1b50 + 0x72) = 9;
  }
  return uVar1;
}



// ===== FUN_001b1b54 =====

undefined4 FUN_001b1b54(int param_1)

{
  undefined4 uVar1;
  undefined1 local_9;
  
  for (local_9 = 1; uVar1 = FUN_000ce23c(*(undefined1 *)(param_1 + (uint)local_9)), local_9 != 0;
      local_9 = local_9 - 1) {
  }
  return uVar1;
}



// ===== FUN_001b1bb0 =====

void FUN_001b1bb0(void)

{
  FUN_000ce170();
  FUN_000cbe08();
  FUN_001b23ec();
  FUN_000b65e4();
  return;
}



// ===== FUN_001b1bc0 =====

void FUN_001b1bb0(void)

{
  FUN_000ce170();
  FUN_000cbe08();
  FUN_001b23ec();
  FUN_000b65e4();
  return;
}



// ===== FUN_001b1bd4 =====

void FUN_001b1bd4(void)

{
  int local_10;
  char local_9;
  
  DAT_001b2084[0x6e] = 5;
  DAT_001b2084[0x72] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x70) = DAT_001b208c;
  DAT_001b2084[0xe6] = 5;
  DAT_001b2084[0xea] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xe8) = DAT_001b208c;
  DAT_001b2084[100] = 0x10;
  DAT_001b2084[0x68] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x66) = DAT_001b2090;
  DAT_001b2084[0xdc] = 0x10;
  DAT_001b2084[0xe0] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xde) = DAT_001b2090;
  DAT_001b2084[0x5a] = 0x20;
  DAT_001b2084[0x5e] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x5c) = DAT_001b2094;
  DAT_001b2084[0xd2] = 0x20;
  DAT_001b2084[0xd6] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xd4) = DAT_001b2094;
  DAT_001b2084[0x50] = 0x45;
  DAT_001b2084[0x54] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x52) = DAT_001b2098;
  DAT_001b2084[200] = 0x45;
  DAT_001b2084[0xcc] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xca) = DAT_001b2098;
  DAT_001b2084[0x46] = 0x5e;
  DAT_001b2084[0x4a] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x48) = DAT_001b209c;
  DAT_001b2084[0xbe] = 0x5e;
  DAT_001b2084[0xc2] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xc0) = DAT_001b20a0;
  DAT_001b2084[0x3c] = 8;
  DAT_001b2084[0x40] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x3e) = DAT_001b20a4;
  DAT_001b2084[0xb4] = 8;
  DAT_001b2084[0xb8] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xb6) = DAT_001b20a4;
  DAT_001b2084[0x32] = 0xd;
  DAT_001b2084[0x36] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x34) = DAT_001b20a8;
  DAT_001b2084[0xaa] = 0xd;
  DAT_001b2084[0xae] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xac) = DAT_001b20ac;
  DAT_001b2084[0x28] = 0x1c;
  DAT_001b2084[0x2c] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x2a) = DAT_001b20b0;
  DAT_001b2084[0xa0] = 0x1c;
  DAT_001b2084[0xa4] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xa2) = DAT_001b20b4;
  DAT_001b2084[0x1e] = 0x48;
  DAT_001b2084[0x22] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x20) = DAT_001b20b8;
  DAT_001b2084[0x96] = 0x47;
  DAT_001b2084[0x9a] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x98) = DAT_001b20b8;
  DAT_001b2084[0x14] = 0x94;
  DAT_001b2084[0x18] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x16) = DAT_001b20bc;
  DAT_001b2084[0x8c] = 0x94;
  DAT_001b2084[0x90] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x8e) = DAT_001b20c0;
  DAT_001b2084[10] = 0xa8;
  DAT_001b2084[0xe] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0xc) = DAT_001b20c4;
  DAT_001b2084[0x82] = 0xa9;
  DAT_001b2084[0x86] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x84) = DAT_001b20c4;
  *DAT_001b2084 = 0xe6;
  DAT_001b2084[4] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 2) = DAT_001b20c8;
  DAT_001b2084[0x78] = 0xe5;
  DAT_001b2084[0x7c] = (short)DAT_001b2088;
  *(undefined4 *)(DAT_001b2084 + 0x7a) = DAT_001b20cc;
  for (local_9 = '\0'; local_9 < '\x02'; local_9 = local_9 + '\x01') {
    for (local_10 = 0; local_10 < 0xb; local_10 = local_10 + 1) {
      DAT_001b2084[local_9 * 0x78 + local_10 * 10 + 9] =
           DAT_001b2084[local_9 * 0x78 + local_10 * 10 + 4];
    }
  }
  return;
}



// ===== FUN_001b23ec =====

void FUN_001b23ec(void)

{
  FUN_00017e34(DAT_001b2418);
  FUN_00017e34(DAT_001b241c);
  FUN_00017e34(DAT_001b2420);
  return;
}



// ===== FUN_001b2424 =====

void FUN_001b2424(char param_1)

{
  int local_c;
  
  local_c = 100;
  if (param_1 == '\x01') {
    local_c = DAT_001b24c8;
  }
  FUN_00017e34(DAT_001b24cc);
  (DAT_001b24d0->it_value).tv_sec = 0;
  (DAT_001b24d0->it_value).tv_usec = local_c * 100;
  (DAT_001b24d0->it_interval).tv_sec = 0;
  (DAT_001b24d0->it_interval).tv_usec = 0;
  setitimer(ITIMER_REAL,DAT_001b24d0,(itimerval *)0x0);
  return;
}



// ===== FUN_001b2828 =====

void FUN_001b2828(uint3 *param_1)

{
  FUN_000ce18c((uint)*param_1);
  return;
}



// ===== FUN_001b2998 =====

undefined1 * FUN_001b2998(undefined4 param_1,char param_2,char param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  byte local_18 [6];
  undefined1 local_12;
  undefined1 local_11;
  undefined1 *local_10;
  uint local_c;
  
  puVar1 = (undefined1 *)FUN_00078d94();
  local_10 = puVar1;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    puVar1 = &stack0xfffffff8;
    local_18[local_c] = 0;
  }
  if (param_3 != '\x05') {
    *DAT_001b3380 = param_3;
  }
  if (*(int *)(DAT_001b3384 + 4) != 1) {
    local_18[1] = 0xa0;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      local_18[local_c] = local_18[local_c] | 0x20;
      if (*(char *)(*(int *)(DAT_001b3388 + local_c * 4) + 0x20) == '\0') {
        local_18[local_c] = local_18[local_c] | 1;
        FUN_001add80(local_c & 0xff,0);
      }
      else {
        local_18[local_c] = local_18[local_c] & 0xfe;
        FUN_001add80(local_c & 0xff,1);
      }
      if (*(char *)(*(int *)(DAT_001b3388 + (local_c + 2) * 4) + 0x20) == '\0') {
        local_18[local_c] = local_18[local_c] & 0xfd;
      }
      else {
        local_18[local_c] = local_18[local_c] | 2;
      }
      iVar2 = FUN_000cba50(local_c & 0xff);
      if (iVar2 == 0) {
        puVar1 = (undefined1 *)0x0;
        if (*(char *)(*(int *)(DAT_001b3388 + local_c * 4) + 0x10) == '\0') {
          puVar1 = &stack0xfffffff8;
          local_18[local_c] = local_18[local_c] | 8;
        }
      }
      else {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] & 0xf7;
      }
    }
    local_18[2] = 0x70;
                    /* WARNING: Could not recover jumptable at 0x001b2c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (*(byte *)(DAT_001b338c + 0x40) < 5) {
      puVar1 = (undefined1 *)
               (*(code *)(&switchD_001b2c90::switchdataD_001b2c98)[*(byte *)(DAT_001b338c + 0x40)])
                         ();
      return puVar1;
    }
    if ((((*(char *)(DAT_001b338c + 0x40) == '\0') || (*(char *)(DAT_001b338c + 0x40) == '\x01')) ||
        (*(char *)(DAT_001b338c + 0x40) == '\x03')) || (*(char *)(DAT_001b338c + 0x40) == '\x04')) {
      switch(local_11) {
      case 0:
        local_18[2] = 0x70;
        break;
      case 1:
        local_18[2] = 0x50;
        break;
      case 2:
        local_18[2] = 0xf0;
        break;
      case 3:
        local_18[2] = 0x40;
      }
    }
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      puVar1 = (undefined1 *)
               FUN_00076440((int)*(short *)(DAT_001b33a4 +
                                           *(char *)(DAT_001b33a0 + local_c * 0x10 + 5) * 0x14 +
                                           local_c * 0xf0),(local_c & 0xff) + 0x10 & 0xff);
    }
    local_12 = 7;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      if (*(char *)(DAT_001b33a0 + local_c * 0x10 + 5) < '\a') {
        local_18[local_c] = local_18[local_c] & 0xfb;
      }
      else {
        local_18[local_c] = local_18[local_c] | 4;
      }
      puVar1 = &stack0xfffffff8;
    }
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      if (*DAT_001b3380 == '\x01') {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] | 4;
      }
      else if (*DAT_001b3380 == '\x03') {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] & 0xfb;
      }
    }
    if (param_2 == '\x01') {
      uVar3 = FUN_001b3430(puVar1);
      if (uVar3 == *DAT_001b33a8) {
        local_10 = (undefined1 *)0x0;
      }
    }
    else if ((param_2 == '\x02') && (uVar3 = FUN_001b3430(puVar1), uVar3 == *DAT_001b33a8)) {
      local_10 = (undefined1 *)0x1;
    }
    switch(local_10) {
    case (undefined1 *)0x0:
      local_18[0] = ~((byte)~(byte)(((uint)local_18[0] << 0x19) >> 0x18) >> 1);
      break;
    case (undefined1 *)0x1:
      local_18[1] = local_18[1] & 0x7f;
      break;
    default:
      break;
    case (undefined1 *)0x8:
    case (undefined1 *)0x9:
    case (undefined1 *)0xa:
    case (undefined1 *)0xb:
      local_18[0] = local_18[0] & 0x7f;
      local_18[1] = ~((byte)~(byte)(((uint)local_18[1] << 0x19) >> 0x18) >> 1);
    }
    puVar1 = (undefined1 *)FUN_001b2828(local_18);
  }
  return puVar1;
}



// ===== FUN_001b32c0 =====

undefined1 * FUN_001b2998(undefined4 param_1,char param_2,char param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  byte local_18 [6];
  undefined1 local_12;
  undefined1 local_11;
  undefined1 *local_10;
  uint local_c;
  
  puVar1 = (undefined1 *)FUN_00078d94();
  local_10 = puVar1;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    puVar1 = &stack0xfffffff8;
    local_18[local_c] = 0;
  }
  if (param_3 != '\x05') {
    *DAT_001b3380 = param_3;
  }
  if (*(int *)(DAT_001b3384 + 4) != 1) {
    local_18[1] = 0xa0;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      local_18[local_c] = local_18[local_c] | 0x20;
      if (*(char *)(*(int *)(DAT_001b3388 + local_c * 4) + 0x20) == '\0') {
        local_18[local_c] = local_18[local_c] | 1;
        FUN_001add80(local_c & 0xff,0);
      }
      else {
        local_18[local_c] = local_18[local_c] & 0xfe;
        FUN_001add80(local_c & 0xff,1);
      }
      if (*(char *)(*(int *)(DAT_001b3388 + (local_c + 2) * 4) + 0x20) == '\0') {
        local_18[local_c] = local_18[local_c] & 0xfd;
      }
      else {
        local_18[local_c] = local_18[local_c] | 2;
      }
      iVar2 = FUN_000cba50(local_c & 0xff);
      if (iVar2 == 0) {
        puVar1 = (undefined1 *)0x0;
        if (*(char *)(*(int *)(DAT_001b3388 + local_c * 4) + 0x10) == '\0') {
          puVar1 = &stack0xfffffff8;
          local_18[local_c] = local_18[local_c] | 8;
        }
      }
      else {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] & 0xf7;
      }
    }
    local_18[2] = 0x70;
                    /* WARNING: Could not recover jumptable at 0x001b2c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (*(byte *)(DAT_001b338c + 0x40) < 5) {
      puVar1 = (undefined1 *)
               (*(code *)(&switchD_001b2c90::switchdataD_001b2c98)[*(byte *)(DAT_001b338c + 0x40)])
                         ();
      return puVar1;
    }
    if ((((*(char *)(DAT_001b338c + 0x40) == '\0') || (*(char *)(DAT_001b338c + 0x40) == '\x01')) ||
        (*(char *)(DAT_001b338c + 0x40) == '\x03')) || (*(char *)(DAT_001b338c + 0x40) == '\x04')) {
      switch(local_11) {
      case 0:
        local_18[2] = 0x70;
        break;
      case 1:
        local_18[2] = 0x50;
        break;
      case 2:
        local_18[2] = 0xf0;
        break;
      case 3:
        local_18[2] = 0x40;
      }
    }
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      puVar1 = (undefined1 *)
               FUN_00076440((int)*(short *)(DAT_001b33a4 +
                                           *(char *)(DAT_001b33a0 + local_c * 0x10 + 5) * 0x14 +
                                           local_c * 0xf0),(local_c & 0xff) + 0x10 & 0xff);
    }
    local_12 = 7;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      if (*(char *)(DAT_001b33a0 + local_c * 0x10 + 5) < '\a') {
        local_18[local_c] = local_18[local_c] & 0xfb;
      }
      else {
        local_18[local_c] = local_18[local_c] | 4;
      }
      puVar1 = &stack0xfffffff8;
    }
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      if (*DAT_001b3380 == '\x01') {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] | 4;
      }
      else if (*DAT_001b3380 == '\x03') {
        puVar1 = &stack0xfffffff8;
        local_18[local_c] = local_18[local_c] & 0xfb;
      }
    }
    if (param_2 == '\x01') {
      uVar3 = FUN_001b3430(puVar1);
      if (uVar3 == *DAT_001b33a8) {
        local_10 = (undefined1 *)0x0;
      }
    }
    else if ((param_2 == '\x02') && (uVar3 = FUN_001b3430(puVar1), uVar3 == *DAT_001b33a8)) {
      local_10 = (undefined1 *)0x1;
    }
    switch(local_10) {
    case (undefined1 *)0x0:
      local_18[0] = ~((byte)~(byte)(((uint)local_18[0] << 0x19) >> 0x18) >> 1);
      break;
    case (undefined1 *)0x1:
      local_18[1] = local_18[1] & 0x7f;
      break;
    default:
      break;
    case (undefined1 *)0x8:
    case (undefined1 *)0x9:
    case (undefined1 *)0xa:
    case (undefined1 *)0xb:
      local_18[0] = local_18[0] & 0x7f;
      local_18[1] = ~((byte)~(byte)(((uint)local_18[1] << 0x19) >> 0x18) >> 1);
    }
    puVar1 = (undefined1 *)FUN_001b2828(local_18);
  }
  return puVar1;
}



// ===== FUN_001b3430 =====

undefined1 FUN_001b3430(void)

{
  return *DAT_001b3450;
}



// ===== FUN_001b3500 =====

void FUN_001b3500(undefined4 param_1,undefined1 param_2)

{
  FUN_000cc184(param_1,param_2);
  return;
}



// ===== FUN_001b3534 =====

undefined4 FUN_001b3534(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000cc224(param_1);
  return uVar1;
}



// ===== FUN_001bb4b0 =====

undefined4 FUN_001bb4b0(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_000db670();
  iVar3 = FUN_00018394(DAT_001bb5f0,DAT_001bb5f4);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_00018508(DAT_001bb5f8,1,0x10000,iVar3);
    if (iVar2 == 0x14) {
      uVar4 = FUN_00018704(iVar3);
    }
    else if (*DAT_001bb5fc + 2U < 0x10001) {
      FUN_00018704(iVar3);
      iVar2 = FUN_00018394(DAT_001bb5f0,DAT_001bb600);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        iVar3 = *DAT_001bb5fc;
        uVar1 = FUN_000db670();
        *(undefined1 *)(DAT_001bb5f8 + iVar3) = uVar1;
        *DAT_001bb5fc = iVar3 + 1;
        iVar3 = *DAT_001bb5fc;
        uVar1 = FUN_000db7b8();
        *(undefined1 *)(DAT_001bb5f8 + iVar3) = uVar1;
        *DAT_001bb5fc = iVar3 + 1;
        FUN_000185b8(DAT_001bb5f8,1,0x10000,iVar2);
        uVar4 = FUN_00018704(iVar2);
      }
    }
    else {
      FUN_001bb3f4();
      uVar4 = FUN_00018704(iVar3);
    }
  }
  return uVar4;
}



// ===== FUN_001bb604 =====

void FUN_001bb604(void)

{
  if ((*DAT_001bb670 != 0) && (*DAT_001bb670 != *DAT_001bb674)) {
    FUN_0003e640(DAT_001bb678,DAT_001bb67c,DAT_001bb680);
    FUN_0003e82c(DAT_001bb678,DAT_001bb67c,DAT_001bb684);
    *DAT_001bb674 = *DAT_001bb670;
  }
  return;
}



// ===== FUN_001bb688 =====

undefined4 FUN_001bb688(void)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_78 [100];
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = 0;
  memset(acStack_78,0,100);
  sprintf(acStack_78,DAT_001bb7bc,0x10000);
  FUN_0003eac0(DAT_001bb7c0,DAT_001bb7c4,acStack_78,DAT_001bb7c8);
  local_c = FUN_00018394(DAT_001bb7c8,DAT_001bb7cc);
  if (local_c == 0) {
    uVar2 = 0;
  }
  else {
    FUN_00018508(DAT_001bb7d0,1,0x10000,local_c);
    FUN_00018704(local_c);
    do {
      local_10 = (uint)*(byte *)(DAT_001bb7d0 + *DAT_001bb7d4);
      FUN_000db640(local_10);
      *DAT_001bb7d4 = *DAT_001bb7d4 + 1;
      local_14 = (uint)*(byte *)(DAT_001bb7d0 + *DAT_001bb7d4);
      FUN_000db830(local_14);
      *DAT_001bb7d4 = *DAT_001bb7d4 + 1;
      FUN_000da724();
      iVar1 = FUN_000db670();
    } while (iVar1 != 0xff);
    uVar2 = 0xff;
  }
  return uVar2;
}



// ===== FUN_001bba20 =====

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



// ===== FUN_001cd730 =====

undefined4 FUN_001cd730(undefined4 param_1)

{
  if (*(int *)(DAT_001cd76c + 4) != 1) {
    FUN_000ce5e0(0x40);
    param_1 = FUN_000ce60c(0x40);
  }
  return param_1;
}



// ===== FUN_001cd770 =====

void FUN_001cd770(void)

{
  int iVar1;
  undefined1 local_9;
  
  if ((*(char *)(DAT_001cd858 + 0x10) == '\x01') && (*(char *)(DAT_001cd858 + 0x20) == '\x02')) {
    FUN_001d1ff4(1);
  }
  FUN_001cd730();
  if (*(char *)(DAT_001cd85c + 0x10) == '\0') {
    FUN_001ea124(0);
  }
  if (*(char *)(DAT_001cd85c + 0x20) == '\x01') {
    *(undefined1 *)(DAT_001cd860 + 0x20) = 1;
    iVar1 = FUN_002135f4();
    if (iVar1 == 1) {
      FUN_000dd6b4(0x10);
    }
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      iVar1 = FUN_001ad5dc(local_9);
      if (iVar1 != 0) {
        *(undefined4 *)(DAT_001cd864 + (uint)local_9 * 4) = 1;
      }
    }
    FUN_000d9e8c();
  }
  return;
}



// ===== FUN_001d3cd8 =====

void FUN_001d3cd8(void)

{
  undefined4 uVar1;
  int aiStack_14 [2];
  byte local_9;
  
  for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
    aiStack_14[local_9] = DAT_001d3d88 + (uint)local_9 * 0x500a;
  }
  FUN_001b07dc();
  FUN_001b0718();
  FUN_001b083c();
  uVar1 = FUN_001b3430();
  uVar1 = __aeabi_idiv(0x5000,uVar1);
  FUN_001af1fc(aiStack_14,uVar1);
  return;
}



// ===== FUN_001ea124 =====

uint FUN_001ea124(uint param_1)

{
  if (*(int *)(DAT_001ea168 + 4) != 1) {
    param_1 = FUN_001b2424(param_1 & 0xff);
  }
  return param_1;
}



// ===== FUN_001ea214 =====

undefined1 FUN_001ea214(void)

{
  return *(undefined1 *)(DAT_001ea234 + 0x6d);
}



// ===== FUN_001ee760 =====

undefined4 FUN_001ee760(byte param_1)

{
  return *(undefined4 *)(DAT_001ee7a0 + (uint)param_1 * 0x10 + 4);
}



// ===== FUN_001fe7d0 =====

void FUN_001fe7d0(void)

{
  int iVar1;
  
  FUN_001ae070();
  iVar1 = FUN_002169c8();
  if (iVar1 < 0x1f) {
    FUN_001ae0b0();
  }
  else {
    FUN_001ae0f4();
  }
  *DAT_001fe848 = 1;
  FUN_000a20c0();
  *DAT_001fe84c = 0x1b;
  *(undefined4 *)(DAT_001fe850 + 0x44) = 0;
  *(undefined1 *)(DAT_001fe854 + 0x44) = 1;
  FUN_0020cd00();
  return;
}



// ===== FUN_001fe858 =====

void FUN_001fe858(void)

{
  int iVar1;
  
  iVar1 = FUN_002169c8();
  if (iVar1 < 0x1f) {
    FUN_001ae070();
    FUN_001ae0b0();
  }
  else {
    FUN_001ae070();
    FUN_001ae0f4();
    FUN_00216a34();
  }
  *DAT_001fe8c8 = 1;
  FUN_000a20c0();
  *(undefined4 *)(DAT_001fe8cc + 0x44) = 0;
  *(undefined1 *)(DAT_001fe8d0 + 0x44) = 1;
  return;
}



// ===== FUN_002081a4 =====

float FUN_002081a4(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  byte local_11;
  float local_c;
  
  iVar1 = FUN_00219abc();
  if (iVar1 == 2) {
    local_11 = param_1;
    if (param_1 < 0x18) {
      local_11 = 0x18;
    }
    local_c = *(float *)(DAT_002082dc + (local_11 - 0x18) * 4);
  }
  else if ((*(char *)(DAT_002082e0 + 0x40) == '\0') && (param_1 < 6)) {
    local_c = *(float *)(DAT_002082e4 + (uint)param_1 * 4);
  }
  else {
    uVar2 = FUN_00078d94();
    switch(uVar2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      fVar3 = *(float *)(DAT_002082e8 + (uint)param_1 * 4);
      local_c = fVar3 + fVar3;
      break;
    case 8:
      local_c = *(float *)(DAT_002082e8 + (uint)param_1 * 4);
      break;
    case 9:
    case 10:
      local_c = *(float *)(DAT_002082ec + (uint)param_1 * 4);
      break;
    case 0xb:
      local_c = *(float *)(DAT_002082f0 + (uint)param_1 * 4);
    }
  }
  return local_c;
}



// ===== FUN_002086f4 =====

void FUN_002086f4(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint in_fpscr;
  float local_24;
  char local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  float local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = (float)DAT_00208818;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_1c = FUN_000cebac();
  local_c = FUN_002129c4();
  local_18 = FUN_002152dc();
  local_24 = (float)FUN_002081a4(local_c & 0xff);
  local_20 = '\x0e' - *(char *)(DAT_00208820 + (uint)(*(byte *)(DAT_0020881c + 0x10) >> 1) * 0x10 +
                               0xc);
  uVar1 = FUN_0009a604(&local_24,10);
  local_10 = (float)VectorSignedToFloat(local_18,(byte)(in_fpscr >> 0x16) & 3);
  local_10 = local_10 / local_24;
  local_14 = (int)(local_10 * DAT_00208814) + 2;
  do {
    uVar2 = FUN_000cebac(uVar1);
    uVar1 = FUN_000cebe0(local_1c,uVar2);
  } while (uVar1 < local_14);
  return;
}



// ===== FUN_0020af00 =====

int FUN_0020af00(void)

{
  int iVar1;
  uint in_fpscr;
  double dVar2;
  float fVar3;
  double dVar4;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  float fStack_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_1c = 2;
  local_20 = DAT_0020b330;
  local_24 = DAT_0020b334;
  local_28 = *(uint *)(DAT_0020b338 + 0x28);
  FUN_0021813c(local_28 & 0xff,&local_48,&local_4c);
  local_4c = local_4c + 0x4b;
  dVar2 = (double)VectorUnsignedToFloat(local_48,(byte)(in_fpscr >> 0x16) & 3);
  local_2c = (uint)(0.0 < dVar2 * DAT_0020b328) * (int)(longlong)(dVar2 * DAT_0020b328);
  local_30 = FUN_00209b68(*(undefined1 *)(DAT_0020b338 + 0x60));
  for (local_14 = 0; local_14 < local_48; local_14 = local_14 + 1) {
    *(undefined1 *)(local_20 + local_14) = 0;
  }
  local_14 = 0;
  local_18 = 0;
  while( true ) {
    if ((DAT_0020b350 < local_14) || (iVar1 = FUN_002088e0(), iVar1 != 1)) goto LAB_0020b2cc;
    FUN_001b07dc();
    local_c = local_48;
    local_34 = FUN_00218098();
    if (local_34 == 0xffffffff) break;
    if (local_34 < *(uint *)(DAT_0020b33c + local_30 * 0x10 + 4)) {
      local_10 = 0;
    }
    else {
      dVar2 = (double)VectorUnsignedToFloat
                                (local_34 - *(int *)(DAT_0020b33c + local_30 * 0x10 + 4),
                                 (byte)(in_fpscr >> 0x16) & 3);
      dVar4 = (double)VectorUnsignedToFloat
                                (*(int *)(DAT_0020b33c + local_30 * 0x10 + 8) -
                                 *(int *)(DAT_0020b33c + local_30 * 0x10 + 4),
                                 (byte)(in_fpscr >> 0x16) & 3);
      fStack_38 = (float)(dVar2 / dVar4);
      fVar3 = (float)VectorUnsignedToFloat(local_48,(byte)(in_fpscr >> 0x16) & 3);
      local_10 = (uint)(fVar3 * fStack_38);
    }
    iVar1 = DAT_0020b33c;
    if (local_48 < local_10) {
      if (local_10 < local_48 + local_2c) {
        local_c = (local_10 - local_48) - 1;
      }
    }
    else {
      local_c = local_10;
    }
    while (iVar1 = FUN_001b06cc(iVar1), iVar1 == 0) {
      iVar1 = FUN_000db46c(0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = 0;
    }
    FUN_001b083c();
    if ((local_c < local_48) && (*(char *)(local_24 + local_c) == '\0')) {
      *(undefined1 *)(local_24 + local_c) = 1;
      *DAT_0020b340 = *DAT_0020b340 + 1;
    }
    if ((local_c < local_48) && (*(char *)(local_20 + local_c) == '\0')) {
      local_3c = 0;
      *(undefined1 *)(local_20 + local_c) = 1;
      local_18 = local_18 + 1;
      local_40 = DAT_0020b344 + 1000;
      local_44 = DAT_0020b344 + DAT_0020b348;
      FUN_001b083c();
      FUN_0022feec();
      FUN_0022a838(local_c,local_48,local_4c,0);
      FUN_0022ff28();
      FUN_0021e090(1);
    }
    if (local_18 == local_48) goto LAB_0020b2cc;
    if (*DAT_0020b340 == local_48) {
      *DAT_0020b34c = 1;
    }
    local_14 = local_14 + 1;
    iVar1 = FUN_000db46c(0);
    if (iVar1 != 0) {
LAB_0020b2cc:
      local_40 = DAT_0020b344 + 1000;
      local_44 = DAT_0020b344 + DAT_0020b348;
      FUN_00218268(local_40,local_48,local_4c);
      iVar1 = FUN_00218268(local_44,local_48,local_4c);
      *DAT_0020b34c = 1;
      return iVar1;
    }
  }
  FUN_001b07dc();
  local_14 = local_14 + 1;
  goto LAB_0020b2cc;
}



// ===== FUN_0020dc04 =====

void FUN_0020dc04(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_002129c4();
  iVar1 = FUN_002135f4();
  FUN_00078d94();
  uVar2 = FUN_001d40c8();
  if (iVar1 == 0) {
    FUN_001b0570(0);
    uVar2 = FUN_0020d730();
  }
  else if (iVar1 == 1) {
    FUN_001ae530();
    uVar2 = FUN_0020db80();
  }
  FUN_002167c8(uVar2);
  return;
}



// ===== FUN_0020dcb8 =====

void FUN_0020dcb8(void)

{
                    /* WARNING: Could not recover jumptable at 0x0020dccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (*(byte *)(DAT_0020dd78 + 0x65) < 10) {
    (*(code *)(&switchD_0020dccc::switchdataD_0020dcd4)[*(byte *)(DAT_0020dd78 + 0x65)])();
    return;
  }
  return;
}



// ===== FUN_0020dea0 =====

void FUN_0020dea0(void)

{
  undefined4 local_c;
  
  if (*(char *)(DAT_0020e0a0 + 0x40) == '\x04') {
    if (*(char *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 8) == '\0') {
      local_c = *(undefined4 *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 0xc);
    }
    else if (*(char *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 8) == '\x01') {
      local_c = *(undefined4 *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 0x1c);
    }
    else if (*(char *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 8) == '\x02') {
      local_c = *(undefined4 *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 0x38);
    }
    else if (*(char *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 8) == '\x03') {
      local_c = *(undefined4 *)(DAT_0020e0a4 + (uint)*(byte *)(DAT_0020e0a4 + 0x78) * 0x3c + 0x24);
    }
  }
  else {
    local_c = *DAT_0020e0a8;
  }
  FUN_001ae368(local_c);
  return;
}



// ===== FUN_0020e0ac =====

int FUN_0020e0ac(float param_1,char param_2)

{
  undefined4 local_c;
  
  local_c = (int)param_1;
  if (('\t' < param_2) && (1 < local_c)) {
    local_c = local_c + -1;
  }
  return local_c;
}



// ===== FUN_002135f4 =====

uint FUN_002135f4(void)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_001b3430();
  if (iVar1 == 2) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_001c1518();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_00219abc();
      uVar2 = FUN_0021b670();
      if (uVar2 < 2) {
        local_c = FUN_002129c4();
      }
      else {
        local_c = *(int *)(DAT_00213700 + 4);
      }
      if (*(char *)(DAT_00213704 + 0x20) == '\0') {
        if (*(char *)(DAT_00213708 + 0x40) == '\x02') {
          uVar2 = (uint)*(byte *)(DAT_0021370c + 0x50);
        }
        else if ((((local_c < 6) && (*(char *)(DAT_00213710 + 0x40) == '\0')) ||
                 (*(char *)(DAT_00213714 + 0x40) == '\x04')) || (iVar1 == 2)) {
          uVar2 = 0;
        }
        else {
          uVar2 = (uint)*(byte *)(DAT_0021370c + 0x50);
        }
      }
      else {
        uVar2 = *DAT_00213718;
      }
    }
  }
  return uVar2;
}



// ===== FUN_0021371c =====

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



// ===== FUN_00214370 =====

void FUN_00214228(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = FUN_00078d94();
  local_10 = 2;
  if (iVar1 != 0xb) {
    local_10 = 4;
  }
  __aeabi_idivmod(param_1,param_2);
  *DAT_00214380 = param_2 - extraout_r1;
  iVar1 = __aeabi_idiv(param_1,param_2);
  iVar1 = iVar1 + 1;
  __aeabi_idivmod(iVar1,local_10);
  if (extraout_r1_00 == 0) {
    local_c = __aeabi_idiv(iVar1,local_10);
  }
  else {
    iVar2 = __aeabi_idiv(iVar1,local_10);
    local_c = iVar2 + 1;
    __aeabi_idivmod(iVar1,local_10);
    *DAT_00214380 = (local_10 - extraout_r1_01) * param_2 + *DAT_00214380;
  }
  FUN_001ae4e0(0,0);
  FUN_001ae440(0,0);
  FUN_001ae3f0((ushort)(local_c >> 0x10) & 0x1f,local_c & 0xffff);
  return;
}



// ===== FUN_002169c8 =====

int FUN_002169c8(void)

{
  byte bVar1;
  
  bVar1 = FUN_001b0b10();
  return (char)(bVar1 >> 4) * 10 + (int)(char)(bVar1 & 0xf);
}



// ===== FUN_00216b34 =====

undefined4 FUN_00216b34(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00216e0c();
  iVar1 = FUN_00216870();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_002169c8();
    if (0x1e < iVar1) {
      FUN_00216a34();
    }
    FUN_0022a628(param_1);
    FUN_001b0790();
    uVar2 = FUN_001b0860();
  }
  return uVar2;
}



// ===== FUN_00216c60 =====

void FUN_00216c60(void)

{
  FUN_001ae850(2);
  FUN_001ae490(0,0);
  FUN_001ae4e0(0,0);
  FUN_002088a0(0);
  return;
}



// ===== FUN_00218098 =====

undefined4 FUN_00218098(void)

{
  int iVar1;
  int local_10;
  undefined4 local_c;
  
  local_10 = 0;
  do {
    iVar1 = FUN_001b0a40();
    if ((iVar1 != 0) || (iVar1 = FUN_001b04e4(), iVar1 != 0)) break;
    local_10 = local_10 + 1;
  } while (local_10 <= DAT_00218138);
  iVar1 = FUN_001b04e4(iVar1);
  if (iVar1 == 0) {
    local_c = FUN_001b0ba4();
  }
  else {
    local_c = 0xffffffff;
  }
  return local_c;
}



// ===== FUN_0021a01c =====

undefined4 FUN_0021a01c(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*DAT_0021aaf4 != '\x01') {
    param_1 = FUN_002129c4();
                    /* WARNING: Could not recover jumptable at 0x0021a054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (*(byte *)(DAT_0021aaf8 + 0x40) < 5) {
      uVar1 = (*(code *)(&switchD_0021a054::switchdataD_0021a05c)[*(byte *)(DAT_0021aaf8 + 0x40)])()
      ;
      return uVar1;
    }
    *DAT_0021aaf4 = '\x01';
  }
  return param_1;
}



// ===== FUN_0021eb08 =====

int FUN_0021eb08(void)

{
  void *__s;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  void *local_18;
  void *local_14;
  uint local_10;
  uint local_c;
  
  iVar1 = FUN_002129c4();
  iVar2 = FUN_00078d94();
  __s = DAT_0021ee58;
  local_14 = DAT_0021ee54;
  local_18 = DAT_0021ee58;
  memset(DAT_0021ee54,0,0x200000);
  memset(__s,0,0x200000);
  FUN_001b3430();
  FUN_001b07dc();
  if (*(char *)(DAT_0021ee5c + 0x40) != '\0') {
    if (iVar1 < 0x1a) {
      local_10 = DAT_0021ee60;
    }
    else {
      local_10 = DAT_0021ee64;
    }
  }
  uVar3 = FUN_000cebac();
  do {
    uVar5 = FUN_001b06cc();
    if (uVar5 != 0) break;
    iVar1 = FUN_000db46c(0);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar4 = FUN_000cebac();
    uVar5 = FUN_000cebe0(uVar3,uVar4);
  } while (uVar5 < local_10);
  iVar1 = FUN_001b083c(uVar5);
  if (iVar2 == 0x11) {
    for (local_c = 0; local_c < 0x80000; local_c = local_c + 1) {
      iVar1 = FUN_001aef60(local_18,local_14);
      local_18 = (void *)((int)local_18 + 2);
      local_14 = (void *)((int)local_14 + 2);
    }
  }
  else if ((*(char *)(DAT_0021ee68 + 4) == '\x01') && (*(char *)(DAT_0021ee68 + 0x14) == '\0')) {
    for (local_c = 0; local_c < 0x80000; local_c = local_c + 1) {
      iVar1 = FUN_001aef60(local_14,(int)local_14 + 2);
      local_14 = (void *)((int)local_14 + 4);
    }
  }
  else if ((*(char *)(DAT_0021ee68 + 4) == '\0') && (*(char *)(DAT_0021ee68 + 0x14) == '\x01')) {
    for (local_c = 0; local_c < 0x80000; local_c = local_c + 1) {
      iVar1 = FUN_001aef60(local_18,(int)local_18 + 2);
      local_18 = (void *)((int)local_18 + 4);
    }
  }
  return iVar1;
}



// ===== FUN_0022a838 =====

int FUN_0022a838(uint param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int local_1b0 [2];
  __jmp_buf_tag a_Stack_1a8 [2];
  undefined4 local_20;
  undefined4 local_1c;
  char local_18;
  int local_10;
  uint local_c;
  
  local_c = 0;
  local_1b0[0] = *DAT_0022aa44;
  *DAT_0022aa44 = (int)local_1b0;
  iVar1 = _setjmp(a_Stack_1a8);
  local_10 = iVar1;
  if (iVar1 == 0) {
    if ((0x32000 < (uint)(param_2 * param_3)) || (2000 < param_1)) {
      iVar1 = FUN_000c7864(3,DAT_0022aa48,0x80);
      return iVar1;
    }
    if (*DAT_0022aa4c == DAT_0022aa50) {
      iVar1 = FUN_001afb88(DAT_0022aa54,param_3,param_2,param_1,param_4);
    }
    else {
      iVar1 = FUN_001af918(DAT_0022aa54,param_3,param_2,param_1,param_4);
    }
    if (param_4 == '\x01') {
      return iVar1;
    }
    for (local_c = 0; (int)local_c < 2; local_c = local_c + 1) {
      *(undefined1 *)(*(int *)(DAT_0022aa54 + local_c * 4) + 0xc) = 1;
      *(undefined4 *)(*(int *)(DAT_0022aa54 + local_c * 4) + 4) =
           **(undefined4 **)(DAT_0022aa54 + local_c * 4);
      iVar1 = FUN_0022acd8(DAT_0022aa54,local_c & 0xff);
    }
    if (local_10 == 0) {
      *DAT_0022aa44 = *(int *)*DAT_0022aa44;
    }
  }
  else if (local_18 == '\x03') {
    local_10 = 2;
    iVar1 = FUN_000c7964(3,local_20,local_1c);
    if (local_10 == 0) {
      *DAT_0022aa44 = *(int *)*DAT_0022aa44;
    }
  }
  if (local_10 == 1) {
    iVar1 = FUN_000c7864(local_18,local_20,local_1c);
  }
  return iVar1;
}



// ===== FUN_0023005c =====

void FUN_0023005c(void)

{
  FUN_00017e34(DAT_00230080);
  return;
}



// ===== FUN_0023330c =====

undefined4 FUN_0023330c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 local_24 [2];
  int aiStack_20 [4];
  char local_e;
  char local_d;
  undefined4 local_c;
  
  aiStack_20[3] = 0;
  aiStack_20[0] = *DAT_00233544;
  aiStack_20[1] = DAT_00233544[1];
  local_24[0] = *DAT_00233548;
  uStack_34 = *DAT_0023354c;
  uStack_30 = DAT_0023354c[1];
  uStack_2c = DAT_0023354c[2];
  uStack_28 = DAT_0023354c[3];
  FUN_00238540(param_1,aiStack_20 + 3);
  local_e = FUN_00252ad4((int)(char)aiStack_20[3]);
  local_d = FUN_00252b5c((int)(char)aiStack_20[3]);
  iVar1 = FUN_0001d638(param_1,&uStack_34,aiStack_20 + 2,0);
  uVar2 = DAT_00233554;
  if (iVar1 != 0) {
    if (aiStack_20[2] == 0) {
      local_d = '\0';
      local_c = 0;
    }
    else if (aiStack_20[2] == 1) {
      local_d = '\0';
      local_c = 1;
    }
    else if (aiStack_20[2] == 2) {
      local_d = '\x01';
      local_c = 2;
    }
    local_e = (char)local_c;
    FUN_00252b18((int)(char)aiStack_20[3],(int)local_e);
    FUN_00252ba0((int)(char)aiStack_20[3],(int)local_d);
    *(undefined1 *)(DAT_00233558 + aiStack_20[3] * 0x10 + 4) = 0;
    *(undefined1 *)aiStack_20[aiStack_20[3]] = 0;
    FUN_000dc6ac(*(undefined1 *)((int)local_24 + aiStack_20[3]),0);
    FUN_000dd6b4(0x11);
    while (iVar1 = FUN_000dd704(), iVar1 != 0) {
      FUN_00015700(1000);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_00233a78 =====

undefined4 FUN_00233a78(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_8c [68];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int aiStack_18 [4];
  
  aiStack_18[3] = 0;
  aiStack_18[2] = 0;
  aiStack_18[0] = *DAT_00233c38;
  aiStack_18[1] = DAT_00233c38[1];
  uStack_28 = *DAT_00233c3c;
  uStack_24 = DAT_00233c3c[1];
  uStack_20 = DAT_00233c3c[2];
  uStack_1c = DAT_00233c3c[3];
  uStack_48 = *DAT_00233c40;
  uStack_44 = DAT_00233c40[1];
  uStack_40 = DAT_00233c40[2];
  uStack_3c = DAT_00233c40[3];
  uStack_38 = DAT_00233c40[4];
  uStack_34 = DAT_00233c40[5];
  uStack_30 = DAT_00233c40[6];
  uStack_2c = DAT_00233c40[7];
  memcpy(auStack_8c,DAT_00233c44,0x44);
  FUN_00238540(param_1,aiStack_18 + 2);
  iVar2 = FUN_001c15c8();
  if ((iVar2 == 0) || (iVar2 = FUN_001c15c8(), iVar2 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = FUN_0001d638(param_1,&uStack_48,aiStack_18 + 3,0);
    uVar3 = DAT_00233c48;
  }
  else {
    iVar2 = FUN_0001d638(param_1,auStack_8c,aiStack_18 + 3,0);
    uVar3 = DAT_00233c48;
  }
  DAT_00233c48 = uVar3;
  if (iVar2 != 0) {
    FUN_002536b4((int)(char)aiStack_18[2],1);
    FUN_00252c28((int)(char)aiStack_18[2],(int)(char)aiStack_18[3]);
    FUN_00251080(aiStack_18[aiStack_18[2]]);
    uVar3 = 1;
  }
  return uVar3;
}



// ===== FUN_00233f20 =====

undefined4 FUN_00233f20(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_50 [2];
  undefined4 auStack_4c [4];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined1 local_18 [4];
  uint local_14;
  int local_10;
  undefined1 local_b;
  char local_a;
  byte local_9;
  
  local_14 = 0;
  local_9 = 0;
  local_a = 0;
  local_b = 0;
  local_24 = 0;
  local_20 = 0;
  local_10 = 0;
  uStack_38 = *DAT_002342dc;
  uStack_34 = DAT_002342dc[1];
  uStack_30 = DAT_002342dc[2];
  uStack_2c = DAT_002342dc[3];
  local_28 = DAT_002342dc[4];
  auStack_4c[2] = *DAT_002342e0;
  auStack_4c[3] = DAT_002342e0[1];
  uStack_3c = DAT_002342e0[2];
  auStack_4c[0] = *DAT_002342e4;
  auStack_4c[1] = DAT_002342e4[1];
  local_50[0] = *DAT_002342e8;
  iVar1 = FUN_001ea630();
  uVar2 = DAT_002342ec;
  if (iVar1 != 0) {
    local_a = FUN_00252cf4();
    if (local_a == '\x01') {
      iVar1 = FUN_0001d638(param_1,auStack_4c + 2,local_18,0);
      if (iVar1 == 0) {
        return DAT_002342ec;
      }
      for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
        *(undefined1 *)(DAT_002342f0 + (uint)local_9 * 0x10 + 4) = 0;
        *(undefined1 *)auStack_4c[local_9] = 0;
        FUN_000dc6ac(*(undefined1 *)((int)local_50 + (uint)local_9),0);
        FUN_00252cb0((int)(char)local_9,(int)local_18[0]);
        FUN_00076bbc(local_9);
      }
    }
    else {
      local_10 = FUN_0023888c(param_1);
      local_10 = local_10 / 2;
      for (local_9 = 0; (int)(uint)local_9 < local_10; local_9 = local_9 + 1) {
        iVar1 = FUN_0001d638(param_1,&uStack_38,&local_14,0);
        if (iVar1 == 0) {
          return DAT_002342ec;
        }
        local_24 = local_14;
        iVar1 = FUN_0001d638(param_1,auStack_4c + 2,local_18,0);
        if (iVar1 == 0) {
          return DAT_002342ec;
        }
        *(undefined1 *)(DAT_002342f0 + local_14 * 0x10 + 4) = 0;
        *(undefined1 *)auStack_4c[local_14] = 0;
        FUN_000dc6ac(*(undefined1 *)((int)local_50 + local_14),0);
        FUN_00252cb0((int)(char)local_14,(int)local_18[0]);
        FUN_00076bbc(local_14 & 0xff);
      }
    }
    FUN_000dd6b4(0x12);
    while (iVar1 = FUN_000dd704(), iVar1 != 0) {
      FUN_00015700(1000);
    }
    FUN_002510d4();
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_002344a4 =====

undefined4 FUN_002344a4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_28 [2];
  undefined4 auStack_24 [4];
  undefined4 uStack_14;
  char local_10 [4];
  uint local_c;
  
  local_c = 0;
  auStack_24[2] = *DAT_00234678;
  auStack_24[3] = DAT_00234678[1];
  uStack_14 = DAT_00234678[2];
  auStack_24[0] = *DAT_0023467c;
  auStack_24[1] = DAT_0023467c[1];
  local_28[0] = *DAT_00234680;
  iVar1 = FUN_00238540(param_1,&local_c);
  if (iVar1 == 0) {
    local_c = FUN_00253eac();
  }
  iVar1 = FUN_001ea630();
  uVar2 = DAT_00234684;
  if ((iVar1 != 0) &&
     (iVar1 = FUN_0001d638(param_1,auStack_24 + 2,local_10,0), uVar2 = DAT_00234684, iVar1 != 0)) {
    *(undefined1 *)(DAT_00234688 + local_c * 0x10 + 4) = 0;
    *(undefined1 *)auStack_24[local_c] = 0;
    FUN_000dc6ac(*(undefined1 *)((int)local_28 + local_c),0);
    FUN_00252cb0((int)(char)local_c,(int)local_10[0]);
    FUN_00076bbc(local_c & 0xff);
    FUN_000dd6b4(0x12);
    while (iVar1 = FUN_000dd704(), iVar1 != 0) {
      FUN_00015700(1000);
    }
    FUN_002510d4();
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_002347a0 =====

undefined4 FUN_002347a0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  local_c = 0;
  uStack_18 = *DAT_0023485c;
  uStack_14 = DAT_0023485c[1];
  uStack_10 = DAT_0023485c[2];
  iVar1 = FUN_001ea630();
  uVar2 = DAT_00234860;
  if ((iVar1 != 0) &&
     (iVar1 = FUN_0001d638(param_1,&uStack_18,&local_c,0), uVar2 = DAT_00234860, iVar1 != 0)) {
    FUN_00252d24((int)(char)local_c);
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_00234a1c =====

undefined4 FUN_00234a1c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 local_2c [2];
  undefined4 auStack_28 [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  auStack_28[2] = *DAT_00234b70;
  auStack_28[3] = DAT_00234b70[1];
  uStack_18 = DAT_00234b70[2];
  uStack_14 = DAT_00234b70[3];
  auStack_28[0] = *DAT_00234b74;
  auStack_28[1] = DAT_00234b74[1];
  local_2c[0] = *DAT_00234b78;
  uStack_38 = *DAT_00234b7c;
  uStack_34 = DAT_00234b7c[1];
  uStack_30 = DAT_00234b7c[2];
  FUN_00238540(param_1,&local_c);
  *(undefined1 *)(DAT_00234b80 + local_c * 0x10 + 4) = 0;
  *(undefined1 *)auStack_28[local_c] = 1;
  FUN_000dc6ac(*(undefined1 *)((int)local_2c + local_c),0);
  iVar1 = FUN_0001d638(param_1,&uStack_38,&local_10,0);
  uVar2 = DAT_00234b84;
  if (iVar1 != 0) {
    FUN_00252ba0((int)(char)local_c,(int)(char)local_10);
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_00236f18 =====

float FUN_00236f18(char *param_1)

{
  char cVar1;
  undefined4 extraout_r0;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined8 uVar3;
  float local_58;
  char local_54;
  float fStack_50;
  char local_4c;
  char local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  char local_2c [4];
  float local_28;
  byte local_21;
  undefined4 local_20;
  char local_19;
  float fStack_18;
  int local_14;
  byte local_d;
  float local_c;
  
  local_19 = 0;
  local_c = (float)DAT_00237370;
  local_20 = DAT_00237370;
  local_d = 0;
  local_21 = 0;
  local_2c[0] = '\0';
  local_2c[1] = '\0';
  local_2c[2] = '\0';
  local_2c[3] = '\0';
  uStack_40 = *DAT_00237374;
  uStack_3c = DAT_00237374[1];
  uStack_38 = DAT_00237374[2];
  uStack_34 = DAT_00237374[3];
  local_30 = DAT_00237374[4];
  atof(param_1);
  local_c = (float)(double)CONCAT44(extraout_r1,extraout_r0);
  cVar1 = FUN_00016fec(param_1);
  local_21 = cVar1 - 1;
  if (((param_1[local_21 - 2] == 'K') || (param_1[local_21 - 2] == 'M')) ||
     (param_1[local_21 - 2] == 'G')) {
    local_2c[local_d] = param_1[local_21 - 2];
    local_d = local_d + 1;
  }
  local_2c[local_d] = param_1[local_21 - 1];
  local_2c[local_d + 1] = param_1[local_21];
  local_2c[local_d + 2] = '\0';
  local_19 = FUN_0024f460(local_2c,&uStack_40,5);
  local_19 = local_19 + '\n';
  local_58 = *(float *)(DAT_0023737c + *DAT_00237378 * 4);
  local_54 = '\x02';
  FUN_0020ec10(&local_58);
  uVar3 = FUN_001ad5a4(0);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  if ((int)uVar3 == 0x70) {
    if (*(char *)(DAT_00237380 + 0x40) == '\x04') {
      fStack_18 = DAT_00237364 / local_58;
    }
    else {
      FUN_0020f954(&fStack_50,0);
      fStack_18 = DAT_00237364 / fStack_50;
      uVar2 = extraout_r1_00;
    }
  }
  else if (*(char *)(DAT_00237380 + 0x40) == '\x04') {
    uVar3 = FUN_001ad55c(0);
    uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    fStack_18 = ((float)uVar3 * DAT_00237360) / local_58;
  }
  else {
    FUN_0020f954(&fStack_50,0);
    uVar3 = FUN_001ad55c(0);
    uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    fStack_18 = ((float)uVar3 * DAT_00237360) / fStack_50;
  }
  local_44 = local_54;
  if (*(char *)(DAT_00237380 + 0x40) != '\x04') {
    local_44 = local_4c;
  }
  local_44 = '\x0e' - local_44;
  local_14 = (int)local_19 - (int)local_44;
  if (local_14 < 1) {
    if (local_14 < 0) {
      if (local_14 < 0) {
        local_14 = -local_14;
      }
      for (; 0 < local_14; local_14 = local_14 + -1) {
        local_c = (float)((double)local_c * DAT_00237358);
      }
    }
  }
  else {
    for (; 0 < local_14; local_14 = local_14 + -1) {
      local_c = local_c * DAT_00237368;
    }
  }
  local_28 = (local_c * DAT_0023736c) / fStack_18;
  printf(DAT_00237384,uVar2,SUB84((double)local_28,0),(int)((ulonglong)(double)local_28 >> 0x20),
         (double)local_c,(double)fStack_18);
  return local_28;
}



// ===== FUN_00237f78 =====

void FUN_00237f78(void)

{
  FUN_00238958(DAT_0023831c,DAT_00238320,DAT_00238324);
  FUN_00238958(DAT_00238328,DAT_0023832c,DAT_00238330);
  FUN_00238958(DAT_00238334,DAT_00238338,DAT_00238324);
  FUN_00238958(DAT_0023833c,DAT_00238340,DAT_00238330);
  FUN_00238958(DAT_00238344,DAT_00238348,DAT_0023834c);
  FUN_00238958(DAT_00238350,DAT_00238354,DAT_00238358);
  FUN_00238958(DAT_0023835c,DAT_00238360,DAT_0023834c);
  FUN_00238958(DAT_00238364,DAT_00238368,DAT_00238358);
  FUN_00238958(DAT_0023836c,DAT_00238370,DAT_00238374);
  FUN_00238958(DAT_00238378,DAT_0023837c,DAT_00238380);
  FUN_00238958(DAT_00238384,DAT_00238388,DAT_00238374);
  FUN_00238958(DAT_0023838c,DAT_00238390,DAT_00238380);
  FUN_00238958(DAT_00238394,DAT_00238398,DAT_0023839c);
  FUN_00238958(DAT_002383a0,DAT_002383a4,DAT_002383a8);
  FUN_00238958(DAT_002383ac,DAT_002383b0,DAT_002383b4);
  FUN_00238958(DAT_002383b8,DAT_002383bc,DAT_002383c0);
  FUN_00238958(DAT_002383c4,DAT_002383c8,DAT_002383b4);
  FUN_00238958(DAT_002383cc,DAT_002383d0,DAT_002383c0);
  FUN_00238958(DAT_002383d4,DAT_002383d8,DAT_002383dc);
  FUN_00238958(DAT_002383e0,DAT_002383e4,DAT_002383e8);
  FUN_00238958(DAT_002383ec,DAT_002383f0,DAT_002383f4);
  FUN_00238958(DAT_002383f8,DAT_002383fc,DAT_00238400);
  FUN_00238958(DAT_00238404,DAT_00238408,DAT_002383f4);
  FUN_00238958(DAT_0023840c,DAT_00238410,DAT_00238400);
  FUN_00238958(DAT_00238414,DAT_00238418,DAT_0023841c);
  FUN_00238958(DAT_00238420,DAT_00238424,DAT_00238428);
  FUN_00238958(DAT_0023842c,DAT_00238430,DAT_0023841c);
  FUN_00238958(DAT_00238434,DAT_00238438,DAT_00238428);
  FUN_00238958(DAT_0023843c,DAT_00238440,DAT_00238444);
  FUN_00238958(DAT_00238448,DAT_0023844c,DAT_00238450);
  FUN_00238958(DAT_00238454,DAT_00238458,DAT_00238444);
  FUN_00238958(DAT_0023845c,DAT_00238460,DAT_00238450);
  FUN_00238958(DAT_00238464,DAT_00238464,DAT_00238468);
  FUN_00238958(DAT_0023846c,DAT_0023846c,DAT_00238470);
  FUN_00238958(DAT_00238474,DAT_00238474,DAT_00238468);
  FUN_00238958(DAT_00238478,DAT_00238478,DAT_00238470);
  FUN_00238958(DAT_0023847c,DAT_0023847c,DAT_00238480);
  FUN_00238958(DAT_00238484,DAT_00238484,DAT_00238488);
  FUN_00238958(DAT_0023848c,DAT_0023848c,DAT_00238480);
  FUN_00238958(DAT_00238490,DAT_00238490,DAT_00238488);
  FUN_00238958(DAT_00238494,DAT_00238494,DAT_00238498);
  FUN_00238958(DAT_0023849c,DAT_0023849c,DAT_00238498);
  FUN_00238958(DAT_002384a0,DAT_002384a4,DAT_002384a8);
  FUN_00238958(DAT_002384ac,DAT_002384b0,DAT_002384b4);
  FUN_00238958(DAT_002384b8,DAT_002384bc,DAT_002384c0);
  FUN_00238958(DAT_002384c4,DAT_002384c8,DAT_002384b4);
  FUN_00238958(DAT_002384cc,DAT_002384d0,DAT_002384c0);
  FUN_00238958(DAT_002384d4,DAT_002384d8,DAT_002384dc);
  FUN_00238958(DAT_002384e0,DAT_002384e4,DAT_002384e8);
  FUN_00238958(DAT_002384ec,DAT_002384f0,DAT_002384f4);
  FUN_00238958(DAT_002384f8,DAT_002384fc,DAT_00238500);
  FUN_00238958(DAT_00238504,DAT_00238508,DAT_002384f4);
  FUN_00238958(DAT_0023850c,DAT_00238510,DAT_00238500);
  FUN_00238958(DAT_00238514,DAT_00238518,DAT_0023851c);
  FUN_00238958(DAT_00238520,DAT_00238524,DAT_00238528);
  FUN_00238958(DAT_0023852c,DAT_00238530,DAT_0023851c);
  FUN_00238958(DAT_00238534,DAT_00238538,DAT_00238528);
  return;
}



// ===== FUN_00251080 =====

void FUN_00251080(int param_1)

{
  if (*DAT_002510cc != param_1) {
    *DAT_002510cc = param_1;
  }
  *DAT_002510d0 = 1;
  FUN_00199310();
  return;
}



// ===== FUN_00252b18 =====

void FUN_00252b18(char param_1,undefined1 param_2)

{
  **(undefined1 **)(DAT_00252b58 + (param_1 + 6) * 4) = param_2;
  return;
}



// ===== FUN_00252ba0 =====

void FUN_00252ba0(char param_1,undefined1 param_2)

{
  **(undefined1 **)(DAT_00252be0 + (param_1 + 0x10) * 4) = param_2;
  return;
}



// ===== FUN_00252c28 =====

void FUN_00252c28(char param_1,undefined1 param_2)

{
  **(undefined1 **)(DAT_00252c68 + (param_1 + 0xc) * 4) = param_2;
  return;
}



// ===== FUN_00252cb0 =====

void FUN_00252cb0(char param_1,undefined1 param_2)

{
  **(undefined1 **)(DAT_00252cf0 + (param_1 + 8) * 4) = param_2;
  return;
}



// ===== FUN_002536b4 =====

void FUN_002536b4(char param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(char *)(DAT_002537d4 + param_1 * 0x10 + 4) == '\0') {
    FUN_0022ac90((int)param_1);
  }
  else {
    *DAT_002537d8 = 1;
  }
  if (param_1 == '\0') {
    if (param_2 != *(char *)(DAT_002537d4 + 4)) {
      *(char *)(DAT_002537d4 + 4) = param_2;
      bVar1 = true;
    }
  }
  else if (param_1 == '\x01') {
    if (param_2 != *(char *)(DAT_002537d4 + 0x14)) {
      *(char *)(DAT_002537d4 + 0x14) = param_2;
      bVar1 = true;
    }
  }
  else if (param_2 != *(char *)(DAT_002537dc + 0x30)) {
    *(char *)(DAT_002537dc + 0x30) = param_2;
  }
  FUN_00253ed0(param_1);
  if (bVar1) {
    FUN_000dd6b4(1);
  }
  return;
}



// ===== FUN_0025d1f8 =====

float FUN_0025d1f8(void)

{
  undefined1 uVar1;
  float fVar2;
  
  uVar1 = FUN_002129c4();
  fVar2 = (float)FUN_002081a4(uVar1);
  return DAT_0025d254 / fVar2;
}



// ===== FUN_0025f540 =====

void FUN_0025f540(int param_1,int param_2,byte param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint in_fpscr;
  float fVar7;
  double dVar8;
  undefined1 auStack_d8 [23];
  byte local_c1;
  int local_c0;
  int local_bc;
  undefined4 local_b8 [4];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78 [4];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  float local_5c;
  float local_58 [5];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  int local_1c;
  undefined4 local_18;
  int local_14;
  
  local_c1 = param_3;
  local_c0 = param_2;
  local_bc = param_1;
  local_14 = param_1;
  FUN_00017124(param_1,DAT_0025f5ac);
  iVar4 = FUN_001c15c8();
  if (iVar4 == 0) {
    FUN_00017124(local_14 + 0x10,DAT_0025f5b0);
  }
  else {
    FUN_00017124(local_14 + 0x10,DAT_0025f5b4);
  }
  uVar3 = FUN_0025c9d4();
  *(undefined2 *)(local_14 + 0x20) = uVar3;
  *(undefined2 *)(local_14 + 0x22) = 1;
  *(undefined2 *)(local_14 + 0x24) = 0x15a;
  *(undefined2 *)(local_14 + 0x26) = 0;
  *(undefined2 *)(local_14 + 0x28) = 0;
  *(undefined2 *)(local_14 + 0x2a) = 0;
  *(undefined2 *)(local_14 + 0x2c) = 0;
  *(undefined2 *)(local_14 + 0x2e) = 0;
  *(undefined2 *)(local_14 + 0x30) = 0;
  *(undefined2 *)(local_14 + 0x32) = 0;
  *(undefined2 *)(local_14 + 0x34) = 0;
  *(undefined2 *)(local_14 + 0x36) = 0;
  *(undefined2 *)(local_14 + 0x38) = 0;
  *(undefined2 *)(local_14 + 0x3a) = 0;
  local_1c = *(int *)(local_c0 + 0xc);
  local_18 = local_1c;
  iVar5 = FUN_0025c668();
  iVar4 = local_14;
  *(short *)(local_14 + 0x3c) = (short)((uint)(local_18 * iVar5 * 0x10000) >> 0x10);
  *(short *)(local_14 + 0x3e) = (short)((uint)(local_18 * iVar5) >> 0x10);
  *(undefined2 *)(local_14 + 0x40) = 0;
  *(undefined2 *)(local_14 + 0x42) = 0;
  *(undefined2 *)(local_14 + 0x44) = 0;
  *(undefined2 *)(local_14 + 0x46) = 0;
  *(undefined2 *)(local_14 + 0x48) = 0;
  *(undefined2 *)(local_14 + 0x4a) = 0;
  FUN_0025ca24(auStack_d8);
  memcpy((void *)(iVar4 + 0x4c),auStack_d8,0x10);
  uVar6 = FUN_0025ca8c();
  *(short *)(local_14 + 0x5c) = (short)uVar6;
  *(short *)(local_14 + 0x5e) = (short)((uint)uVar6 >> 0x10);
  *(undefined2 *)(local_14 + 0x70) = (undefined2)local_18;
  *(undefined2 *)(local_14 + 0x72) = local_18._2_2_;
  *(undefined2 *)(local_14 + 0x74) = (undefined2)local_18;
  *(undefined2 *)(local_14 + 0x76) = local_18._2_2_;
  *(short *)(local_14 + 0x78) = (short)((uint)((local_18 + -2) * 0x10000) >> 0x10);
  *(short *)(local_14 + 0x7a) = (short)((uint)(local_18 + -2) >> 0x10);
  local_28 = (double)CONCAT44(DAT_0025faf4,DAT_0025faf0);
  local_30 = (double)CONCAT44(DAT_0025fafc,DAT_0025faf8);
  local_38 = DAT_0025faf0;
  local_34 = DAT_0025faf4;
  local_40 = DAT_0025faf8;
  local_3c = DAT_0025fafc;
  *(undefined2 *)(local_14 + 0x7c) = 0;
  *(undefined2 *)(local_14 + 0x7e) = 0;
  *(short *)(local_14 + 0x80) = (short)((uint)((local_18 + -1) * 0x10000) >> 0x10);
  *(short *)(local_14 + 0x82) = (short)((uint)(local_18 + -1) >> 0x10);
  uVar6 = FUN_0025c6f0();
  *(short *)(local_14 + 0x84) = (short)uVar6;
  *(short *)(local_14 + 0x86) = (short)((uint)uVar6 >> 0x10);
  uVar6 = FUN_0025c804();
  *(short *)(local_14 + 0x88) = (short)uVar6;
  *(short *)(local_14 + 0x8a) = (short)((uint)uVar6 >> 0x10);
  uVar6 = FUN_0025c790();
  *(short *)(local_14 + 0x8c) = (short)uVar6;
  *(short *)(local_14 + 0x8e) = (short)((uint)uVar6 >> 0x10);
  uVar6 = FUN_0025c7e0();
  *(short *)(local_14 + 0x90) = (short)uVar6;
  *(short *)(local_14 + 0x92) = (short)((uint)uVar6 >> 0x10);
  *(undefined2 *)(local_14 + 0x94) = 1;
  *(undefined2 *)(local_14 + 0x96) = 0;
  *(undefined2 *)(local_14 + 0x98) = 0;
  *(undefined2 *)(local_14 + 0x9a) = 0;
  local_58[0] = (float)(((double)*(float *)(DAT_0025fb20 + (uint)local_c1 * 0x10 + 8) * DAT_0025fb00
                        ) / DAT_0025fb08);
  FUN_00159998(local_c1,local_58);
  *(short *)(local_14 + 0x9c) = SUB42(local_58[0],0);
  *(short *)(local_14 + 0x9e) = (short)((uint)local_58[0] >> 0x10);
  local_5c = DAT_0025fb1c;
  local_58[4] = (float)DAT_0025fb10;
  local_44 = DAT_0025fb14;
  FUN_0025c9d4();
  fVar7 = (float)VectorSignedToFloat((*(int *)(local_c0 + 0x30) + -0x80) * 2,
                                     (byte)(in_fpscr >> 0x16) & 3);
  local_5c = (float)((double)((*(float *)(local_c0 + 0x34) / DAT_0025fb18) * fVar7) * DAT_0025fb00);
  FUN_00159998(local_c1,&local_5c);
  *(short *)(local_14 + 0xa0) = SUB42(local_5c,0);
  *(short *)(local_14 + 0xa2) = (short)((uint)local_5c >> 0x10);
  iVar4 = FUN_0025c9d4();
  uVar2 = DAT_0025fb2c;
  uVar6 = DAT_0025fb24;
  if (iVar4 == 0) {
    *(short *)(local_14 + 0xa4) = (short)DAT_0025fb24;
    *(short *)(local_14 + 0xa6) = (short)((uint)uVar6 >> 0x10);
    uVar6 = DAT_0025fb28;
    *(short *)(local_14 + 0xa8) = (short)DAT_0025fb28;
    *(short *)(local_14 + 0xaa) = (short)((uint)uVar6 >> 0x10);
  }
  else {
    *(short *)(local_14 + 0xa4) = (short)DAT_0025fb2c;
    *(short *)(local_14 + 0xa6) = (short)((uint)uVar2 >> 0x10);
    uVar6 = DAT_0025fb30;
    *(short *)(local_14 + 0xa8) = (short)DAT_0025fb30;
    *(short *)(local_14 + 0xaa) = (short)((uint)uVar6 >> 0x10);
  }
  *(undefined2 *)(local_14 + 0xac) = 8;
  uVar3 = FUN_0025c7e0();
  *(undefined2 *)(local_14 + 0xae) = uVar3;
  fVar7 = (float)FUN_0025d1f8();
  local_28 = (double)fVar7 * DAT_0025ff00;
  *(float *)(local_14 + 0xb0) = (float)local_28;
  dVar8 = (double)FUN_0025f350(local_c0,local_c1);
  dVar8 = -dVar8 * DAT_0025ff08;
  local_30._0_2_ = SUB82(dVar8,0);
  *(undefined2 *)(local_14 + 0xb4) = (undefined2)local_30;
  local_30._2_2_ = (undefined2)((ulonglong)dVar8 >> 0x10);
  *(undefined2 *)(local_14 + 0xb6) = local_30._2_2_;
  local_30._4_2_ = (undefined2)((ulonglong)dVar8 >> 0x20);
  *(undefined2 *)(local_14 + 0xb8) = local_30._4_2_;
  local_30._6_2_ = (undefined2)((ulonglong)dVar8 >> 0x30);
  *(undefined2 *)(local_14 + 0xba) = local_30._6_2_;
  *(undefined2 *)(local_14 + 0xbc) = (undefined2)local_30;
  *(undefined2 *)(local_14 + 0xbe) = local_30._2_2_;
  *(undefined2 *)(local_14 + 0xc0) = local_30._4_2_;
  *(undefined2 *)(local_14 + 0xc2) = local_30._6_2_;
  local_30 = dVar8;
  FUN_00017124(local_14 + 0xc4,DAT_0025ff10);
  FUN_00017124(local_14 + 0xf4,DAT_0025ff14);
  uVar6 = DAT_0025ff18;
  *(short *)(local_14 + 0x124) = (short)DAT_0025ff18;
  *(short *)(local_14 + DAT_0025ff1c) = (short)((uint)uVar6 >> 0x10);
  local_58[3] = 0.0;
  local_58[2] = 0.0;
  local_58[1] = 0.0;
  FUN_00016070(local_14 + 0x128,0,0x10);
  uVar6 = DAT_0025ff20;
  *(short *)(local_14 + 0x138) = (short)DAT_0025ff20;
  *(short *)(local_14 + DAT_0025ff24) = (short)((uint)uVar6 >> 0x10);
  *(undefined2 *)(local_14 + 0x13c) = 0;
  *(undefined2 *)(local_14 + DAT_0025ff28) = 0;
  *(undefined2 *)(local_14 + 0x140) = 0;
  *(undefined2 *)(local_14 + DAT_0025ff2c) = 1;
  *(short *)(local_14 + 0x144) = (short)*(undefined4 *)(local_c0 + 0x2c);
  uVar3 = FUN_0025d7e0(local_c1);
  *(undefined2 *)(local_14 + DAT_0025ff30) = uVar3;
  local_78[0] = *DAT_0025ff34;
  local_78[1] = DAT_0025ff34[1];
  local_78[2] = DAT_0025ff34[2];
  local_78[3] = DAT_0025ff34[3];
  local_68 = DAT_0025ff34[4];
  uStack_64 = DAT_0025ff34[5];
  uStack_60 = DAT_0025ff34[6];
  local_b8[0] = *DAT_0025ff38;
  local_b8[1] = DAT_0025ff38[1];
  local_b8[2] = DAT_0025ff38[2];
  local_b8[3] = DAT_0025ff38[3];
  local_a8 = DAT_0025ff38[4];
  uStack_a4 = DAT_0025ff38[5];
  uStack_a0 = DAT_0025ff38[6];
  uStack_9c = DAT_0025ff38[7];
  local_98 = DAT_0025ff38[8];
  uStack_94 = DAT_0025ff38[9];
  uStack_90 = DAT_0025ff38[10];
  uStack_8c = DAT_0025ff38[0xb];
  local_88 = DAT_0025ff38[0xc];
  uStack_84 = DAT_0025ff38[0xd];
  uStack_80 = DAT_0025ff38[0xe];
  uStack_7c = DAT_0025ff38[0xf];
  iVar4 = FUN_001c15c8();
  if ((iVar4 == 0) || (iVar4 = FUN_001c15c8(), iVar4 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uVar6 = local_78[**(char **)(DAT_0025ff3c + (local_c1 + 0xc) * 4)];
    *(short *)(local_14 + 0x148) = (short)uVar6;
    *(short *)(local_14 + DAT_0025ff40) = (short)((uint)uVar6 >> 0x10);
  }
  else {
    uVar6 = local_b8[**(char **)(DAT_0025ff3c + (local_c1 + 0xc) * 4)];
    *(short *)(local_14 + 0x148) = (short)uVar6;
    *(short *)(local_14 + DAT_0025ff40) = (short)((uint)uVar6 >> 0x10);
  }
  uVar3 = FUN_0025d85c(local_c1,*(undefined4 *)(local_c0 + 0x34));
  *(undefined2 *)(local_14 + 0x14c) = uVar3;
  uVar3 = FUN_0025d97c(local_c1);
  *(undefined2 *)(local_14 + DAT_0025ff44) = uVar3;
  uVar6 = DAT_0025ff48;
  *(short *)(local_14 + 0x150) = (short)DAT_0025ff48;
  *(short *)(local_14 + DAT_0025ff4c) = (short)((uint)uVar6 >> 0x10);
  *(short *)(local_14 + 0x154) = (short)*(undefined4 *)(local_14 + 0xa0);
  *(short *)(local_14 + DAT_0025ff50) = (short)((uint)*(undefined4 *)(local_14 + 0xa0) >> 0x10);
  *(ushort *)(local_14 + 0x158) = (ushort)local_c1;
  return;
}



// ===== FUN_002462d8 =====

undefined4 FUN_002462d8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int local_10;
  undefined1 local_a;
  undefined1 local_9;
  
  local_10 = 0;
  local_9 = 0;
  local_a = FUN_0023c304();
  uStack_1c = *DAT_002463c4;
  uStack_18 = DAT_002463c4[1];
  uStack_14 = DAT_002463c4[2];
  iVar1 = FUN_00253524(1,1,0);
  uVar2 = DAT_002463c8;
  if ((iVar1 != 0) &&
     (iVar1 = FUN_0001d638(param_1,&uStack_1c,&local_10,0), uVar2 = DAT_002463c8, iVar1 != 0)) {
    if (local_10 == 0) {
      FUN_0023c328(0);
    }
    else {
      FUN_0023c328(1);
      FUN_000db694(0);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_002463cc =====

undefined4 FUN_002463cc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  int local_c;
  
  local_10 = *(char **)(DAT_00246858 + 0xf4);
  local_14 = DAT_0024685c;
  local_c = 0;
  local_20 = 0;
  local_24 = 0;
  iVar1 = FUN_0001d2e8(param_1,&local_20,&local_24,0);
  if (iVar1 != 0) {
    return DAT_00246860;
  }
  FUN_0021b714(0);
  if (*local_10 != '\x02') {
    iVar1 = FUN_00219abc();
    if (iVar1 == 2) {
      *DAT_00246864 = '\0';
      FUN_000db6c4(0x23);
      while (*DAT_00246864 != '\x01') {
        FUN_00015700(1000);
      }
      return 1;
    }
    FUN_00254294(0);
    FUN_002546b8(1);
    FUN_000dc6ac(0x23,0);
    iVar1 = FUN_00254708(1);
    goto LAB_00246680;
  }
  if (*(char *)(DAT_00246868 + 0x20) == '\0') {
    while (iVar1 = FUN_00208bb8(), iVar1 == 0) {
      FUN_00015700(1000);
    }
  }
  iVar1 = FUN_000cebac();
  local_18 = iVar1;
  if (*(char *)(DAT_00246868 + 0x20) == '\0') {
    if (*local_14 != '\x01') {
      iVar2 = FUN_00254330();
      iVar1 = 1;
      if ((iVar2 != 1) && (iVar1 = FUN_00208904(), iVar1 != 1)) goto LAB_00246588;
    }
    bVar3 = true;
  }
  else {
LAB_00246588:
    bVar3 = false;
  }
  if (bVar3) {
    while ((*(char *)(DAT_00246868 + 0x20) == '\0' &&
           (iVar1 = FUN_000cebac(), local_1c = iVar1, (uint)(iVar1 - local_18) <= DAT_0024686c))) {
      iVar1 = FUN_00015700(1000);
    }
  }
  if (*(char *)(DAT_00246868 + 0x20) == '\0') {
    local_c = 1;
  }
  else {
    local_18 = FUN_000cebac(iVar1);
    while ((iVar1 = FUN_001ff7b0(), iVar1 == 1 &&
           (local_1c = FUN_000cebac(), (uint)(local_1c - local_18) <= DAT_0024686c))) {
      FUN_00015700(1000);
    }
    FUN_000dc6ac(0x28,0);
    iVar1 = FUN_00254708(1);
  }
LAB_00246680:
  local_18 = FUN_000cebac(iVar1);
  while( true ) {
    iVar2 = FUN_00254694();
    iVar1 = 1;
    if ((iVar2 == 1) || (iVar1 = FUN_002546e4(), iVar1 == 1)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (((!bVar3) || (local_c == 1)) ||
       (iVar1 = FUN_000cebac(), local_1c = iVar1, DAT_0024686c < (uint)(iVar1 - local_18))) break;
    FUN_00015700(1000);
  }
  iVar1 = FUN_000cebac(iVar1);
  local_18 = iVar1;
  while( true ) {
    if ((*local_10 == '\x02') && (iVar1 = FUN_00254734(), iVar1 != 1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if ((!bVar3) ||
       (iVar1 = FUN_000cebac(), local_1c = iVar1, DAT_0024686c < (uint)(iVar1 - local_18))) break;
    iVar1 = FUN_00015700(1000);
  }
  if ((*local_14 == '\x01') ||
     (((iVar1 = FUN_00254330(iVar1), iVar1 == 1 || (iVar1 = FUN_00208904(), iVar1 == 1)) ||
      (iVar1 = FUN_0021b6ec(), iVar1 == 1)))) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    local_18 = FUN_000cebac();
    while ((*(char *)(DAT_00246868 + 0x20) == '\0' &&
           (local_1c = FUN_000cebac(), (uint)(local_1c - local_18) <= DAT_0024686c))) {
      FUN_00015700(1000);
    }
  }
  return 1;
}



// ===== FUN_00246870 =====

undefined4 FUN_00246870(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  int local_c;
  
  local_10 = *(char **)(DAT_00246cfc + 0xf4);
  local_14 = DAT_00246d00;
  local_c = 0;
  local_20 = 0;
  local_24 = 0;
  iVar1 = FUN_0001d2e8(param_1,&local_20,&local_24,0);
  if (iVar1 != 0) {
    return DAT_00246d04;
  }
  FUN_0021b714(0);
  if (*local_10 != '\x02') {
    iVar1 = FUN_00219abc();
    if (iVar1 == 2) {
      *DAT_00246d08 = '\0';
      FUN_000db6c4(0x23);
      while (*DAT_00246d08 != '\x01') {
        FUN_00015700(1000);
      }
      return 1;
    }
    FUN_00254294(0);
    FUN_002546b8(1);
    FUN_000dc6ac(0x23,0);
    iVar1 = FUN_00254708(1);
    goto LAB_00246b24;
  }
  if (*(char *)(DAT_00246d0c + 0x20) == '\0') {
    while (iVar1 = FUN_00208bb8(), iVar1 == 0) {
      FUN_00015700(1000);
    }
  }
  iVar1 = FUN_000cebac();
  local_18 = iVar1;
  if (*(char *)(DAT_00246d0c + 0x20) == '\0') {
    if (*local_14 != '\x01') {
      iVar2 = FUN_00254330();
      iVar1 = 1;
      if ((iVar2 != 1) && (iVar1 = FUN_00208904(), iVar1 != 1)) goto LAB_00246a2c;
    }
    bVar3 = true;
  }
  else {
LAB_00246a2c:
    bVar3 = false;
  }
  if (bVar3) {
    while ((*(char *)(DAT_00246d0c + 0x20) == '\0' &&
           (iVar1 = FUN_000cebac(), local_1c = iVar1, (uint)(iVar1 - local_18) <= DAT_00246d10))) {
      iVar1 = FUN_00015700(1000);
    }
  }
  if (*(char *)(DAT_00246d0c + 0x20) == '\0') {
    local_c = 1;
  }
  else {
    local_18 = FUN_000cebac(iVar1);
    while ((iVar1 = FUN_001ff7b0(), iVar1 == 1 &&
           (local_1c = FUN_000cebac(), (uint)(local_1c - local_18) <= DAT_00246d10))) {
      FUN_00015700(1000);
    }
    FUN_000dc6ac(0x28,0);
    iVar1 = FUN_00254708(1);
  }
LAB_00246b24:
  local_18 = FUN_000cebac(iVar1);
  while( true ) {
    iVar2 = FUN_00254694();
    iVar1 = 1;
    if ((iVar2 == 1) || (iVar1 = FUN_002546e4(), iVar1 == 1)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (((!bVar3) || (local_c == 1)) ||
       (iVar1 = FUN_000cebac(), local_1c = iVar1, DAT_00246d10 < (uint)(iVar1 - local_18))) break;
    FUN_00015700(1000);
  }
  iVar1 = FUN_000cebac(iVar1);
  local_18 = iVar1;
  while( true ) {
    if ((*local_10 == '\x02') && (iVar1 = FUN_00254734(), iVar1 != 1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if ((!bVar3) ||
       (iVar1 = FUN_000cebac(), local_1c = iVar1, DAT_00246d10 < (uint)(iVar1 - local_18))) break;
    iVar1 = FUN_00015700(1000);
  }
  if ((*local_14 == '\x01') ||
     (((iVar1 = FUN_00254330(iVar1), iVar1 == 1 || (iVar1 = FUN_00208904(), iVar1 == 1)) ||
      (iVar1 = FUN_0021b6ec(), iVar1 == 1)))) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    local_18 = FUN_000cebac();
    while ((*(char *)(DAT_00246d0c + 0x20) == '\0' &&
           (local_1c = FUN_000cebac(), (uint)(local_1c - local_18) <= DAT_00246d10))) {
      FUN_00015700(1000);
    }
  }
  return 1;
}



// ===== FUN_00246d14 =====

undefined4 FUN_00246d14(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0;
  iVar1 = FUN_0001d2e8(param_1,&local_c,&local_10,0);
  uVar2 = DAT_00246da0;
  if (iVar1 == 0) {
    *(undefined1 *)(DAT_00246da4 + 0x20) = 1;
    FUN_000dc6ac(0x28,0);
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_0024728c =====

undefined4 FUN_0024728c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_2c;
  undefined4 local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_20 = *DAT_00247394;
  uStack_1c = DAT_00247394[1];
  uStack_18 = DAT_00247394[2];
  uStack_14 = DAT_00247394[3];
  uStack_10 = DAT_00247394[4];
  uStack_c = DAT_00247394[5];
  local_28 = *DAT_00247398;
  local_24 = (undefined1)DAT_00247398[1];
  iVar1 = FUN_00253524(1,1,0);
  uVar2 = DAT_0024739c;
  if ((iVar1 != 0) &&
     (iVar1 = FUN_0001d638(param_1,&uStack_20,&local_2c,0), uVar2 = DAT_0024739c, iVar1 != 0)) {
    FUN_00251080(DAT_002473a0);
    *(char *)(DAT_002473a0 + 0x10) = (char)local_2c;
    FUN_000db6c4(*(undefined1 *)((int)&local_28 + local_2c));
    uVar2 = 1;
  }
  return uVar2;
}



// ===== FUN_00255f1c =====

undefined4 FUN_00255f1c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  int local_24;
  uint local_20;
  char *local_1c;
  char local_16;
  undefined1 local_15;
  int local_14;
  
  local_24 = 0;
  local_15 = 0;
  local_16 = 0;
  local_1c = DAT_00256718;
  local_14 = 0;
  local_20 = 0;
  uStack_38 = *DAT_0025671c;
  uStack_34 = DAT_0025671c[1];
  uStack_30 = DAT_0025671c[2];
  uStack_2c = DAT_0025671c[3];
  local_28 = DAT_0025671c[4];
  uVar3 = DAT_00256724;
  if (((*(char *)(DAT_00256720 + 0x40) != '\x04') &&
      (iVar1 = FUN_00253524(1,1,0), uVar3 = DAT_00256724, iVar1 != 0)) &&
     (iVar1 = FUN_0001d638(param_1,&uStack_38,&local_24,0), uVar3 = DAT_00256724, iVar1 != 0)) {
    local_16 = FUN_002532f4();
    FUN_00254294(0);
    if (local_24 == 3) {
      if (*(char *)(DAT_00256728 + 0x20) == '\0') {
        FUN_000dc6ac(0x28,0);
        FUN_0024f3b0();
      }
      uVar3 = 1;
    }
    else {
      if (local_24 == 2) {
        if ((local_16 != '\x02') && (*(char *)(DAT_00256728 + 0x20) == '\x01')) {
          FUN_000dc6ac(0x28,0);
          FUN_0024f3b0();
        }
      }
      else {
        if (local_16 == '\x02') {
          if (*(char *)(DAT_00256728 + 0x20) == '\0') {
            while (iVar1 = FUN_00208bb8(), iVar1 == 0) {
              FUN_00015700(1000);
            }
          }
          local_20 = FUN_000cebac();
          if ((*(char *)(DAT_00256728 + 0x20) == '\0') &&
             ((*local_1c == '\x01' || (iVar1 = FUN_00254330(), iVar1 == 1)))) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if (bVar4) {
            while (*(char *)(DAT_00256728 + 0x20) == '\0') {
              uVar3 = FUN_000cebac();
              uVar2 = FUN_000cebe0(local_20,uVar3);
              if (DAT_0025672c < uVar2) break;
              FUN_00015700(1000);
            }
          }
        }
        if (*(char *)(DAT_00256728 + 0x20) == '\x01') {
          FUN_000dc6ac(0x28,0);
          FUN_0024f3b0();
        }
      }
      FUN_000dc6ac(0x1c,0);
      if (local_24 == 2) {
        if (local_16 == '\x02') {
          if (*(char *)(DAT_00256728 + 0x20) == '\0') {
            while (iVar1 = FUN_00208bb8(), iVar1 == 0) {
              FUN_00015700(1000);
            }
          }
          local_20 = FUN_000cebac();
          if ((*(char *)(DAT_00256728 + 0x20) == '\0') &&
             ((*local_1c == '\x01' || (iVar1 = FUN_00254330(), iVar1 == 1)))) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if (bVar4) {
            while (*(char *)(DAT_00256728 + 0x20) == '\0') {
              uVar3 = FUN_000cebac();
              uVar2 = FUN_000cebe0(local_20,uVar3);
              if (DAT_0025672c < uVar2) break;
              FUN_00015700(1000);
            }
          }
          if (*(char *)(DAT_00256728 + 0x20) == '\0') {
            FUN_0020ce90(0xb);
            local_14 = 1;
          }
          else {
            FUN_000dc6ac(0x28,0);
            FUN_0024f3b0();
            FUN_00254708(1);
          }
        }
        else {
          iVar1 = FUN_00219abc();
          if (iVar1 == 2) {
            *DAT_00256730 = '\0';
            FUN_000db6c4(0x23);
            while (*DAT_00256730 != '\x01') {
              FUN_00015700(1000);
            }
            return 1;
          }
          FUN_00254294(0);
          FUN_002546b8(1);
          *DAT_00256730 = '\0';
          FUN_000db6c4(0x23);
          FUN_00199310();
          while (*DAT_00256730 != '\x01') {
            FUN_00015700(1000);
          }
          FUN_00254708(1);
        }
        local_20 = FUN_000cebac();
        while( true ) {
          iVar1 = FUN_00254694();
          uVar2 = 1;
          if ((iVar1 == 1) || (uVar2 = FUN_002546e4(), uVar2 == 1)) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if ((!bVar4) || (local_14 == 1)) break;
          uVar3 = FUN_000cebac();
          uVar2 = FUN_000cebe0(local_20,uVar3);
          if (DAT_0025672c < uVar2) break;
          FUN_00015700(1000);
        }
        uVar2 = FUN_000cebac(uVar2);
        local_20 = uVar2;
        while( true ) {
          if ((local_16 == '\x02') && (uVar2 = FUN_00254734(), uVar2 != 1)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (!bVar4) break;
          uVar3 = FUN_000cebac();
          uVar2 = FUN_000cebe0(local_20,uVar3);
          if (DAT_0025672c < uVar2) break;
          uVar2 = FUN_00015700(1000);
        }
        if ((((*local_1c == '\x01') || (iVar1 = FUN_00254330(uVar2), iVar1 == 1)) ||
            (iVar1 = FUN_00208904(), iVar1 == 1)) || (iVar1 = FUN_0021b6ec(), iVar1 == 1)) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
        if (bVar4) {
          local_20 = FUN_000cebac();
          while (*(char *)(DAT_00256728 + 0x20) == '\0') {
            uVar3 = FUN_000cebac();
            uVar2 = FUN_000cebe0(local_20,uVar3);
            if (DAT_0025672c < uVar2) break;
            FUN_00015700(1000);
          }
        }
      }
      else {
                    /* WARNING: Could not recover jumptable at 0x002565c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        if (*(byte *)(DAT_00256720 + 0x40) < 4) {
          uVar3 = (*(code *)(&switchD_002565c8::switchdataD_002565d0)
                            [*(byte *)(DAT_00256720 + 0x40)])();
          return uVar3;
        }
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}



