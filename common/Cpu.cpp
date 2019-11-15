#include <string.h>
#include "Cpu.h"

UInt32 orders1[] = {
  0x05000,       /* [00] 00101 0 0000000000 0  T    S */
  0x15004,       /* [01] 10101 0 0000000010 0  H  2 S */
  0x05000,       /* [02] 00101 0 0000000000 0  T    S */
  0x0300c,       /* [03] 00011 0 0000000110 0  E  6 S */
  0x00002,       /* [04] 00000 0 0000000001 0  P  1 S */
  0x0000a,       /* [05] 00000 0 0000000101 0  P  5 S */
  0x05000,       /* [06] 00101 0 0000000000 0  T    S */
  0x08000,       /* [07] 01000 0 0000000000 0  I    S */
  0x1c000,       /* [08] 11100 0 0000000000 0  A    S */
  0x04020,       /* [09] 00100 0 0000010000 0  R 16 S */
  0x05001,       /* [10] 00101 0 0000000000 1  T    L */
  0x08004,       /* [11] 01000 0 0000000010 0  I  2 S */
  0x1c004,       /* [12] 11100 0 0000000010 0  A  2 S */
  0x0c00a,       /* [13] 01100 0 0000000101 0  S  5 S */
  0x0302a,       /* [14] 00011 0 0000010101 0  E 21 S */
  0x05006,       /* [15] 00101 0 0000000011 0  T  3 S */
  0x1f002,       /* [16] 11111 0 0000000001 0  V  1 S */
  0x19010,       /* [17] 11001 0 0000001000 0  L  8 S */
  0x1c004,       /* [18] 11100 0 0000000010 0  A  2 S */
  0x05002,       /* [19] 00101 0 0000000001 0  T  1 S */
  0x03016,       /* [20] 00011 0 0000001011 0  E 11 S */
  0x04008,       /* [21] 00100 0 0000000100 0  R  4 S */
  0x1c002,       /* [22] 11100 0 0000000001 0  A  1 S */
  0x19001,       /* [23] 11001 0 0000000000 1  L    L */
  0x1c000,       /* [24] 11100 0 0000000000 0  A    S */
  0x0503e,       /* [25] 00101 0 0000011111 0  T 31 S */
  0x1c032,       /* [26] 11100 0 0000011001 0  A 25 S */
  0x1c008,       /* [27] 11100 0 0000000100 0  A  4 S */
  0x07032,       /* [28] 00111 0 0000011001 0  U 25 S */
  0x0c03e,       /* [29] 01100 0 0000011111 0  S 31 S */
  0x1b00c,       /* [30] 11011 0 0000000110 0  G  6 S */
  0xfffff
  };

UInt32 orders2[] = {
  0x05000,     /* 00101 0 0000000000 0  [ 0]   T    F */
  0x03028,     /* 00011 0 0000010100 0  [ 1]   E 20 F */
  0x00002,     /* 00000 0 0000000001 0  [ 2]   P  1 F */
  0x07004,     /* 00111 0 0000000010 0  [ 3]   U  2 F */
  0x1c04e,     /* 11100 0 0000100111 0  [ 4]   A 39 F */
  0x04008,     /* 00100 0 0000000100 0  [ 5]   R  4 F */
  0x1f000,     /* 11111 0 0000000000 0  [ 6]   V    F */
  0x19010,     /* 11001 0 0000001000 0  [ 7]   L  8 F */
  0x05000,     /* 00101 0 0000000000 0  [ 8]   T    F */
  0x08002,     /* 01000 0 0000000001 0  [ 9]   I  1 F */
  0x1c002,     /* 11100 0 0000000001 0  [10]   A  1 F */
  0x0c04e,     /* 01100 0 0000100111 0  [11]   S 39 F */
  0x1b008,     /* 11011 0 0000000100 0  [12]   G  4 F */
  0x19001,     /* 11001 0 0000000000 1  [13]   L    D */
  0x0c04e,     /* 01100 0 0000100111 0  [14]   S 39 F */
  0x03022,     /* 00011 0 0000010001 0  [15]   E 17 F */
  0x0c00e,     /* 01100 0 0000000111 0  [16]   S  7 F */
  0x1c046,     /* 11100 0 0000100011 0  [17]   A 35 F */
  0x05028,     /* 00101 0 0000010100 0  [18]   T 20 F */
  0x1c000,     /* 11100 0 0000000000 0  [19]   A    F */
  0x15010,     /* 10101 0 0000001000 0  [20]   H  8 F */
  0x1c050,     /* 11100 0 0000101000 0  [21]   A 40 F */
  0x05056,     /* 00101 0 0000101011 0  [22]   T 43 F */
  0x1c02c,     /* 11100 0 0000010110 0  [23]   A 22 F */
  0x1c004,     /* 11100 0 0000000010 0  [24]   A  2 F */
  0x0502c,     /* 00101 0 0000010110 0  [25]   T 22 F */
  0x03044,     /* 00011 0 0000100010 0  [26]   E 34 F */
  0x1c056,     /* 11100 0 0000101011 0  [27]   A 43 F */
  0x03010,     /* 00011 0 0000001000 0  [28]   E  8 F */
  0x1c054,     /* 11100 0 0000101010 0  [29]   A 42 F */
  0x1c050,     /* 11100 0 0000101000 0  [30]   A 40 F */
  0x03032,     /* 00011 0 0000011001 0  [31]   E 25 F */
  0x1c02c,     /* 11100 0 0000010110 0  [32]   A 22 F */
  0x05054,     /* 00101 0 0000101010 0  [33]   T 42 F */
  0x08051,     /* 01000 0 0000101000 1  [34]   I 40 D */
  0x1c051,     /* 11100 0 0000101000 1  [35]   A 40 D */
  0x04020,     /* 00100 0 0000010000 0  [36]   R 16 F */
  0x05051,     /* 00101 0 0000101000 1  [37]   T 40 D */
  0x03010,     /* 00011 0 0000001000 0  [38]   E  8 F */
  0x0000b,     /* 00000 0 0000000101 1  [39]   P  5 D */
  0x00001,     /* 00000 0 0000000000 1  [40]   P    D */
  0xfffff
  };

Cpu::Cpu() {
  stopCommand = true;
  printer = NULL;
  reader = NULL;
  trace = 'N';
  changes = 0;
  breg = 0;
  only1949 = false;
  overflow = false;
  cycles[0] = 0;
  cycles[1] = 0;
  Reset();
  }

Cpu::~Cpu() {
  }

/* ******************************* */
/* ***** Protected functions ***** */
/* ******************************* */

void Cpu::doAnd() {
  UInt32 tmp[2];
  tmp[0] = multiplier[0] & multiplicand[0];
  tmp[1] = multiplier[1] & multiplicand[1];
  mbAdd(tmp,2);
  }

void Cpu::doMul(char mode) {
  Byte sign;
  UInt32 tmp[4];
  UInt32 a[4];
  a[3] = multiplicand[1];
  a[2] = multiplicand[0];
  a[1] = 0;
  a[0] = 0;
  tmp[3] = multiplier[1];
  tmp[2] = multiplier[0];
  tmp[1] = 0;
  tmp[0] = 0;
  sign = 0;
  sign ^= prepForMul(tmp);
  sign ^= prepForMul(a);
  lShift(tmp,4);
  lShift(tmp,4);
  if (sign == 1) mode = (mode == 'A') ? 'S' : 'A';
  while ((a[0] | a[1] | a[2] | a[3]) != 0) {
    if (a[3] & 1) {
      if (mode == 'A') mbAdd(tmp,4); else mbSub(tmp,4);
      }
    lShift(tmp,4);
    rShift(a,4);
    }
  }

UInt32 Cpu::fetchB(UInt32 address, Boolean indexed) {
  if (!indexed) return mem[address];
  return mem[(address+breg) & 0x3ff];
  }

void Cpu::storeB(UInt32 address, Boolean indexed, UInt32 value) {
  if (!indexed) {
    mem[address] = value;
    return;
    }
  mem[(address + breg) & 0x3ff] = value;
  }

Byte Cpu::getShiftCount(UInt32 a) {
  Byte r;
  r = 1;
  while (r < 17 && ((a & 1) != 1)) {
    r++;
    a >>= 1;
    }
  return r;
  }

void Cpu::lMul(UInt32 hi,UInt32 lo,char mode) {
  Int32 i;
  UInt32 c,t;
  multiplicand[1] = hi;
  multiplicand[0] = lo;
  doMul(mode);
  }

void Cpu::lShift(UInt32* number,UInt32 num) {
  UInt32 c;
  Int32 i;
  c = 0;
  for (i=num-1; i>=0; i--) {
    number[i] = (number[i] << 1) + c;
    c = (number[i] & 0x40000) ? 1 : 0;
    number[i] &= 0x3ffff;
    }
  number[0] &= 0x1ffff;
  }

void Cpu::mbAdd(UInt32* value,Int32 words) {
  Byte c;
  Int32  i;
  Boolean signCheck;
  UInt32 sign;
  signCheck = ((value[0] & 0x10000) == (acc[0] & 0x10000));
  if (signCheck) sign = acc[0] & 0x10000;
  c = 0;
  for (i=words-1; i>= 0; i--) {
    acc[i] += (value[i] + c);
    c = (acc[i] & 0x40000) ? 1 : 0;
    acc[i] &= 0x3ffff;
    }
  if (signCheck) {
    if (acc[0] >= 0x20000) {
      overflow = true;
      }
    if (sign != (acc[0] & 0x10000)) {
      overflow = true;
      }
    }
  acc[0] &= 0x1ffff;
  }

void Cpu::mbSub(UInt32* value,Int32 words) {
  UInt32 tmp[8];
  Int32  i;
  for (i=0; i<words; i++) tmp[i] = value[i];
  twosComp(tmp,words);
  mbAdd(tmp,words);
  }

Int32 Cpu::prepForMul(UInt32* number) {
  if (number[2] & 0x10000) {
    number[0] = 0xffffffff;
    number[1] = 0xffffffff;
    number[2] |= 0xffff0000;
    twosComp(number,4);
    return 1;
    }
  return 0;
  }

void Cpu::roundAcc() {
  UInt32 tmp[4];
  tmp[0] = 0;
  tmp[1] = 0;
  tmp[2] = 0x20000;
  tmp[3] = 0;
  mbAdd(tmp,4);
  }

void Cpu::rShift(UInt32* number,UInt32 num) {
  UInt32 c;
  UInt32 tc;
  UInt32 i;
  c = 0;
  if (number[0] & 0x10000) number[0] |= 0x20000;
  for (i=0; i<num; i++) {
    tc = (number[i] & 1) ? 0x20000 : 0;
    number[i] = (number[i] >> 1) + c;
    c = tc;
    number[i] &= 0x3ffff;
    }
  number[0] &= 0x1ffff;
  }

void Cpu::sMul(UInt32 a,char mode) {
  int i;
  UInt32 tmp[2];
  multiplicand[0] = a;
  multiplicand[1] = 0;
  doMul(mode);
  }

/* ********************************************************* */
/* ***** Convert number in byte array to 2s compliment ***** */
/* ***** Array is in big-endian order                  ***** */
/* ***** High byte is considered 17 bits               ***** */
/* ***** All others are 18 bits                        ***** */
/* ********************************************************* */
void Cpu::twosComp(UInt32* number,UInt32 num) {
  Int32 i;
  for (i=0; i<num; i++) number[i] = (~number[i] & 0x3ffff);
  number[num-1]++;
  for (i=num-2; i>= 0; i--) {
    if (number[i+1] & 0x40000) {
      number[i]++;
      number[i+1] &= 0x3ffff;
      }
    }
  number[0] &= 0x1ffff;
  }

/* **************************** */
/* ***** Public functions ***** */
/* **************************** */

UInt32* Cpu::Acc() {
  return acc;
  }

UInt32 Cpu::Address1() {
  return address1;
  }

UInt32 Cpu::Address2() {
  return address2;
  }

void Cpu::AttachPrinter(Printer* p) {
  printer = p;
  }

void Cpu::AttachReader(Reader* r) {
  reader = r;
  }

UInt32 Cpu::Changes() {
  UInt32 ret;
  ret = changes;
  changes = 0;
  return ret;
  }

UInt32* Cpu::Cycles() {
  return cycles;
  }

String* Cpu::Disassem(UInt32 address, UInt32 order) {
  char buffer[256];
  char temp[64];
  sprintf(buffer,"[%3d] ",address);
  switch ((order >> 12) & 0x1ff) {
    case  0: sprintf(temp,"P"); break;
    case  1: sprintf(temp,"Q"); break;
    case  2: sprintf(temp,"W"); break;
    case  3: sprintf(temp,"E"); break;
    case  4: sprintf(temp,"R"); break;
    case  5: sprintf(temp,"T"); break;
    case  6: sprintf(temp,"Y"); break;
    case  7: sprintf(temp,"U"); break;
    case  8: sprintf(temp,"I"); break;
    case  9: sprintf(temp,"O"); break;
    case 10: sprintf(temp,"J"); break;
    case 11: sprintf(temp,"#"); break;
    case 12: sprintf(temp,"S"); break;
    case 13: sprintf(temp,"Z"); break;
    case 14: sprintf(temp,"K"); break;
    case 15: sprintf(temp,"*"); break;
    case 16: sprintf(temp,"."); break;
    case 17: sprintf(temp,"F"); break;
    case 18: sprintf(temp,"@"); break;
    case 19: sprintf(temp,"D"); break;
    case 20: sprintf(temp,"!"); break;
    case 21: sprintf(temp,"H"); break;
    case 22: sprintf(temp,"N"); break;
    case 23: sprintf(temp,"M"); break;
    case 24: sprintf(temp,"&"); break;
    case 25: sprintf(temp,"L"); break;
    case 26: sprintf(temp,"X"); break;
    case 27: sprintf(temp,"G"); break;
    case 28: sprintf(temp,"A"); break;
    case 29: sprintf(temp,"B"); break;
    case 30: sprintf(temp,"C"); break;
    case 31: sprintf(temp,"V"); break;
    default: sprintf(temp,"-");
    }
  strcat(buffer, temp);
  if (((order >> 1) & 0x7ff) > 0) sprintf(temp,"%5d",(order >> 1) & 0x7ff);
    else sprintf(temp,"     ");
  strcat(buffer, temp);
  if (initialOrders == 1) { if (order & 1) sprintf(temp," L"); else sprintf(temp," S"); }
  if (initialOrders == 2) { if (order & 1) sprintf(temp," D"); else sprintf(temp," F"); }
  strcat(buffer, temp);
  return new String(buffer);
  }

UInt32 Cpu::Fetch(UInt32 addr) {
  if (addr > 1023) return 0xffffffff;
  return mem[addr];
  }

Reader* Cpu::GetReader() {
  return reader;
  }

Printer* Cpu::GetPrinter() {
  return printer;
  }

Int32 Cpu::InitialOrders() {
  return initialOrders;
  }

Int32 Cpu::InitialOrders(Int32 i) {
  initialOrders = i;
  return initialOrders;
  }

void Cpu::LoadOrders1() {
  UInt32 i;
  i = 0;
  initialOrders = 1;
  while (orders1[i] != 0xfffff) {
    mem[i] = orders1[i];
    i++;
    }
  }

void Cpu::LoadOrders2() {
  UInt32 i;
  i = 0;
  initialOrders = 2;
  while (orders2[i] != 0xfffff) {
    mem[i] = orders2[i];
    i++;
    }
  }

UInt32* Cpu::Memory() {
  return mem;
  }

UInt32* Cpu::Multiplicand() {
  return multiplicand;
  }

UInt32* Cpu::Multiplier() {
  return multiplier;
  }

Boolean Cpu::Only1949() {
  return only1949;
  }

Boolean Cpu::Only1949(Boolean b) {
  only1949 = b;
  return only1949;
  }

UInt32 Cpu::Order() {
  return order;
  }

void Cpu::Reset() {
  UInt32 i;
  for (i=0; i<1024; i++) mem[i] = 0;
  for (i=0; i<4; i++) acc[i] = 0;
  scr = 0;
  breg = 0;
  cycles[0] = 0;
  cycles[1] = 0;
  stopCommand = true;
  }

UInt32 Cpu::Scr() {
  return scr;
  }

UInt32 Cpu::Scr(UInt32 i) {
  scr = i;
  return scr;
  }

void Cpu::Start() {
  if (initialOrders == 1) LoadOrders1();
  if (initialOrders == 2) LoadOrders2();
  scr = 0;
  breg = 0;
  stopCommand = false;
  cycles[0] = 0;
  cycles[1] = 0;
  }

void Cpu::Step() {
  Int32  i;
  UInt32 c;
  Byte   b;
  UInt32 address;
  UInt32 tmp[2];
  String *line;
  char    buffer1[128];
  char    buffer2[128];
  Boolean indexed;
  if (stopCommand) return;
  cycles[0]++;
  if (cycles[0] == 0x40000) {
    cycles[0] = 0;
    cycles[1]++;
    }
  order = Fetch(scr);
  if (trace == 'Y') {
    line = Disassem(scr, order);
    sprintf(buffer1,"%s  ",line->AsCharArray());
    delete(line);
    }
  scr++;
  indexed = (order & 0x800) ? true : false;
  address = (order >> 1) & 0x3ff;
  switch (order >> 12) {
    case 28:                                     /* A - Add */
         if (order & 1) {
           address &= 0x1fffe;
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x + %05x %05x =",acc[0],acc[1],
                    fetchB(address+1,indexed),fetchB(address,indexed));
             strcat(buffer1,buffer2);
             }
           tmp[0] = fetchB(address+1,indexed);
           tmp[1] = fetchB(address,indexed);
           mbAdd(tmp,2);
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x\r\n",acc[0],acc[1]);
             strcat(buffer1,buffer2);
             printer->Print(buffer1);
             }
           }
         else  {
           if (trace == 'Y') {
             sprintf(buffer2,"%x+%x",acc[0],fetchB(address,indexed));
             strcat(buffer1,buffer2);
             }
           tmp[0] = fetchB(address,indexed);
           mbAdd(tmp,1);
           if (trace == 'Y') {
             sprintf(buffer2,"=%x\r\n",acc[0]);
             strcat(buffer1,buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_ACC;
         break;

    case 12:                                     /* S - Subtract */
         if (order & 1) {
           address &= 0x1fffe;
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x - %05x %05x =",acc[0],acc[1],
                    fetchB(address+1,indexed),fetchB(address,indexed));
             strcpy(buffer1, buffer2);
             }
           tmp[0] = fetchB(address+1,indexed);
           tmp[1] = fetchB(address,indexed);
           mbSub(tmp,2);
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x\r\n",acc[0],acc[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         else {
           if (trace == 'Y') {
             sprintf(buffer2,"%x-%x",acc[0],fetchB(address,indexed));
             strcat(buffer1, buffer2);
             }
           tmp[0] = fetchB(address,indexed);
           mbSub(tmp,1);
           if (trace == 'Y') {
             sprintf(buffer2,"=%x\r\n",acc[0]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_ACC;
         break;

    case 21:                                     /* H - Load multiplier */
         if (order & 1) {
           address &= 0x1fffe;
           multiplier[0] = fetchB(address+1,indexed);
           multiplier[1] = fetchB(address,indexed);
           if (trace == 'Y') {
             sprintf(buffer2,"R = %05x %05x\r\n",multiplier[0],multiplier[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         else {
           multiplier[0] = fetchB(address,indexed);
           multiplier[1] = 0;
           if (trace == 'Y') {
             sprintf(buffer2,"R = %05x\r\n",multiplier[0]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_IER;
         break;

    case 31:                                     /* V - Multiply */
         if (order & 1) {
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x*%05x %05x=",multiplier[0],
                    multiplier[1],fetchB(address+1,indexed),fetchB(address,indexed));
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           lMul(fetchB(address,indexed),fetchB(address+1,indexed),'A');
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x %05x%05x\r\n",acc[0],acc[1],acc[2], acc[3]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           } else {
           if (trace == 'Y') {
             sprintf(buffer2,"%05x*%05x=",multiplier[0],fetchB(address,indexed));
             strcat(buffer1, buffer2);
             }
           sMul(fetchB(address,indexed),'A');
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x\r\n",acc[0],acc[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_IER | CH_ICAND | CH_ACC;
         break;

    case 22:                                     /* N - Multiply */
         if (order & 1) {
           if (trace == 'Y') { 
             sprintf(buffer2,"%05x %05x * %05x %05x = ",
               multiplier[0],multiplier[1],fetchB(address+1,indexed),
               fetchB(address,indexed));
             strcat(buffer1, buffer2);
             }
           lMul(fetchB(address,indexed),fetchB(address+1,indexed),'S');
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x %05x%05x\r\n",acc[0],acc[1],acc[2],acc[3]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         else {
           if (trace == 'Y') {
             sprintf(buffer2,"%05x * %05x = ",multiplier[0],fetchB(address,indexed));
             strcat(buffer1, buffer2);
             }
           sMul(fetchB(address,indexed),'S');
           if (trace == 'Y') {
             sprintf(buffer2,"%05x %05x\r\n",acc[0],acc[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_IER | CH_ICAND | CH_ACC;
         break;

    case  5:                                     /* T - Transfer/clear */
         if (order & 1) {
           address &= 0x1fffe;
           storeB(address,indexed,acc[1]);
           storeB(address+1,indexed,acc[0]);
           changes |= CH_MEM_1 | CH_MEM_2;
           address1 = address;
           address2 = address+1;
           if (trace == 'Y') {
             sprintf(buffer2,"[%d]=%5x [%d]=%5x\r\n",address+1,acc[0],address,acc[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         else {
           storeB(address,indexed,acc[0]);
           changes |= CH_MEM_1;
           address1 = address;
           if (trace == 'Y') {
             sprintf(buffer2,"[%d]=%x\r\n",address,acc[0]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         for (i=0; i<4; i++) acc[i] = 0;
         changes |= CH_ACC;
         break;

    case  7:                                     /* U - Transfer */
         if (order & 1) {
           address &= 0x1fffe;
           storeB(address,indexed,acc[1]);
           storeB(address+1,indexed,acc[0]);
           if (trace == 'Y') {
             sprintf(buffer2,"[%d]=%5x [%d]=%5x\r\n",address+1,acc[0],address,acc[1]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           changes |= CH_MEM_1 | CH_MEM_2;
           address1 = address;
           address2 = address+1;
           }
         else {
           if (trace == 'Y') {
             sprintf(buffer2,"[%d]=%x\r\n",address,acc[0]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           storeB(address,indexed,acc[0]);
           changes |= CH_MEM_1;
           address1 = address;
           }
         break;

    case 30:                                     /* C - Collate */
         if (order & 1) {
           multiplicand[0] = fetchB(address+1,indexed);
           multiplicand[1] = fetchB(address,indexed);
           doAnd();
           }
         else {
           multiplicand[0] = fetchB(address,indexed);
           multiplicand[1] = 0;
           if (trace == 'Y')  {
             sprintf(buffer2,"%05x + (%05x & %05x) =",acc[0],multiplier[0],multiplicand[0]);
             strcat(buffer1, buffer2);
             }
           doAnd();
           if (trace == 'Y') {
             sprintf(buffer2," %05x\r\n",acc[0]);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           }
         changes |= CH_ICAND | CH_ACC;
         break;

    case  4:                                     /* R - Shift right */
         b=getShiftCount(order);
         if (trace == 'Y') {
           sprintf(buffer2,"%05x %05x %05x%05x >> %d = ",acc[0],acc[1],acc[2],acc[3],b);
           strcat(buffer1, buffer2);
           }
         for (i=0; i<b; i++) {
           rShift(acc,4);
           }
         if (trace == 'Y') {
           sprintf(buffer2,"%05x %05x\r\n %05x%05x",acc[0],acc[1],acc[2],acc[3]);
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         changes |= CH_ACC;
         break;

    case 25:                                     /* L - Shift left */
         b=getShiftCount(order);
         if (trace == 'Y') {
           sprintf(buffer2,"%05x %05x %05x%05x << %d = ",acc[0],acc[1],acc[2],acc[3],b);
           strcat(buffer1, buffer2);
           }
         for (i=0; i<b; i++) {
           lShift(acc,4);
           }
         if (trace == 'Y')  {
           sprintf(buffer2,"%05x %05x %05x%05x\r\n",acc[0],acc[1],acc[2],acc[3]);
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         changes |= CH_ACC;
         break;

    case  3:                                     /* E - Branch positive */
         if ((acc[0] & 0x10000) == 0) {
           if (trace == 'Y') {
             sprintf(buffer2,"Positive, jumping %d\r\n",address);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           scr = address;
           if (order & 1 && !only1949) {
             acc[0] = 0;
             acc[1] = 0;
             acc[2] = 0;
             acc[3] = 0;
             }
           }
         else if (trace == 'Y') {
           sprintf(buffer2,"Negative, No jump\r\n");
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         break;

    case 27:                                     /* G - Branch negative */
         if ((acc[0] & 0x10000) != 0) {
           if (trace == 'Y') {
             sprintf(buffer2,"Negative, jumping %d\r\n",address);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           scr = address;
           if (order & 1 && !only1949) {
             acc[0] = 0;
             acc[1] = 0;
             acc[2] = 0;
             acc[3] = 0;
             }
           }
         else if (trace == 'Y') {
           sprintf(buffer2,"Positive, No jump\r\n");
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         break;

    case  8:                                     /* I - Input */
         if (reader != NULL) b = reader->Read();
           else b = 0xff;
         if (b != 255) {
           if (order & 1) address &= 0x1fffe;
           if (trace == 'Y') {
             sprintf(buffer2,"[%d]=%x\r\n",address+(order & 1),b);
             strcat(buffer1, buffer2);
             printer->Print(buffer1);
             }
           storeB(address + (order & 1),indexed,b);
           changes |= CH_MEM_1;
           address1 = address + (order & 1);
           if (order & 1) {
             changes |= CH_MEM_2;
             address2 = address;
             storeB(address,indexed,0);
             }
           }
         break;

    case  9:                                     /* O - Output */
         b = (fetchB(address,indexed) >> 12) & 0x1ff;
         if (printer != NULL) printer->Print(b);
         lastOutput = b;
         if (trace == 'Y') {
           sprintf(buffer2,"print %02x\r\n",b);
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         break;

    case 26:                                     /* X - Nop */
         if (trace == 'Y') printer->Print(buffer1);
         break;

    case  6:                                     /* Y */
         if (order & 1) {                        /* Y - Jump on overflow */
           if (overflow) {
             if (trace == 'Y') {
               sprintf(buffer2,"Overflow, jumping %d\r\n",address);
               strcat(buffer1, buffer2);
               printer->Print(buffer1);
               }
             scr = address;
             overflow = false;
             }
           else {
             if (trace == 'Y') {
               sprintf(buffer2,"No Overflow, no jump\r\n");
               strcat(buffer1, buffer2);
               printer->Print(buffer1);
               }
             }
           }
         else {                                  /* Y - Extend ABC */
           roundAcc();
           changes |= CH_ACC;
           }
         break;

    case 13:                                     /* Z - Stop */
         stopCommand = true;
         if (trace == 'Y') {
           sprintf(buffer2,"Stopping\r\n");
           strcat(buffer1, buffer2);
           printer->Print(buffer1);
           }
         break;

    case 23:                                     /* M - Mix */
         if (!only1949) {
           acc[0] &= 0xfff;
           if (order & 1) {
             address &= 0x1fffe;
             if (trace == 'Y') {
               sprintf(buffer2,"%05x %05x + %05x %05x =",acc[0],acc[1],
                      fetchB(address+1,indexed),fetchB(address,indexed));
               strcat(buffer1, buffer2);
               }
             tmp[0] = fetchB(address+1,indexed);
             tmp[1] = fetchB(address,indexed);
             mbAdd(tmp,2);
             if (trace == 'Y') {
               sprintf(buffer2,"%05x %05x\r\n",acc[0],acc[1]);
               strcat(buffer1, buffer2);
               printer->Print(buffer1);
               }
             }
           else  {
             if (trace == 'Y') {
               sprintf(buffer2,"%x+%x",acc[0],fetchB(address,indexed));
               strcat(buffer1, buffer2);
               }
             tmp[0] = fetchB(address, indexed);
             mbAdd(tmp,1);
             if (trace == 'Y') {
               sprintf(buffer2,"=%x\r\n",acc[0]);
               strcat(buffer1, buffer2);
               printer->Print(buffer1);
               }
             }
           changes |= CH_ACC;
           }
         else {
           printf("Bad instruction\n");
           stopCommand = true;
           }
         break;

    case 17:                                     /* F - Unconditional jump */
         if (!only1949) {
           if (order & 1) {
             if (acc[0] | acc[1] | acc[2] | acc[3] != 0) {
               if (trace == 'Y') {
                 sprintf(buffer2,"Acc not zero, Jumping %d\r\n",address);
                 strcat(buffer1, buffer2);
                 printer->Print(buffer1);
                 }
               scr = address;
               }
             else {
               if (trace == 'Y') {
                 sprintf(buffer2,"Acc zero, No jump\r\n");
                 strcat(buffer1, buffer2);
                 printer->Print(buffer1);
                 }
               }
             }
           else {
             if (trace == 'Y') {
               sprintf(buffer2,"Jumping %d\r\n",address);
               strcat(buffer1, buffer2);
               printer->Print(buffer1);
               }
             scr = address;
             }
           }
         else {
            mem[address] = lastOutput << 12;
            if (trace == 'Y') {
              sprintf(buffer2,"[%d]=%x\r\n",address,lastOutput << 12);
              strcat(buffer1, buffer2);
              printer->Print(buffer1);
              }
           }
         break;

    case 29:                                     /* B - Load b register */
         if (!only1949) {
           if (order & 0x800) {
             if (order & 1) {
               breg -= address;
               if (trace == 'Y') printf("b+=%x = %x",address,breg);
               }
             else {
               breg += address;
               if (trace == 'Y') printf("b+=%x = %x",address,breg);
               }
             }
           else {
             if (order & 1) {
               breg = -address;
               if (trace == 'Y') printf("b=%x",breg);
               }
             else {
               breg = address;
               if (trace == 'Y') printf("b=%x",breg);
               }
             }
           }
         else {
           printf("Bad instruction\n");
           stopCommand = true;
           }
         break;

    case 10:                                     /* J - Jump if B != 0 */
         if (!only1949) {
           if (breg != 0) {
             scr = address;
             if (trace == 'Y') printf("Jumping --> %d",address);
             }
           }
         else {
           printf("Bad instruction\n");
           stopCommand = true;
           }
         break;

    default:
         printf("Bad instruction\n");
         stopCommand = true;
    }
  if (trace == 'Y') {
    printf("\n");
    }
  }

Boolean Cpu::StopCommand() {
  return stopCommand;
  }

Boolean Cpu::StopCommand(Boolean b) {
  stopCommand = b;
  return stopCommand;
  }

char Cpu::Trace() {
  return trace;
  }

char Cpu::Trace(char c) {
  trace = c;
  return trace;
  }

