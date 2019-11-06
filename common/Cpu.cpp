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
  printer = NULL;
  reader = NULL;
  trace = 'N';
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

Byte Cpu::getShiftCount(UInt32 a) {
  Byte r;
  r = 1;
  while (r < 17 && ((a & 1) != 1)) {
    r++;
    a >>= 1;
    }
  return r;
  }

void Cpu::lMul(UInt32 address,char mode) {
  Int32 i;
  UInt32 c,t;
  multiplicand[1] = mem[address];
  multiplicand[0] = mem[address+1];
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
  c = 0;
  for (i=words-1; i>= 0; i--) {
    acc[i] += (value[i] + c);
    c = (acc[i] & 0x40000) ? 1 : 0;
    acc[i] &= 0x3ffff;
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

void Cpu::AttachPrinter(Printer* p) {
  printer = p;
  }

void Cpu::AttachReader(Reader* r) {
  reader = r;
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
  strcat(buffer,"     ");
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

void Cpu::InitialOrders(Int32 i) {
  initialOrders = i;
  }

void Cpu::LoadOrders1() {
  UInt32 i;
  i = 0;
  initialOrders = 1;
printf("Loading orders 1\n"); fflush(stdout);
  while (orders1[i] != 0xfffff) {
    mem[i] = orders1[i];
printf("[%d] = %08x\n",i,mem[i]);
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

UInt32 Cpu::Order() {
  return order;
  }

void Cpu::Reset() {
  UInt32 i;
  for (i=0; i<1024; i++) mem[i] = 0;
  for (i=0; i<4; i++) acc[i] = 0;
  scr = 0;
  }

UInt32 Cpu::Scr() {
  return scr;
  }

UInt32 Cpu::Scr(UInt32 i) {
  scr = i;
  return scr;
  }

void Cpu::Step() {
  Int32  i;
  UInt32 c;
  Byte   b;
  UInt32 address;
  UInt32 tmp[2];
  String *line;
  order = Fetch(scr);
  if (trace == 'Y') {
    line = Disassem(scr, order);
    printf("%s\n",line->AsCharArray());
fflush(stdout);
    delete(line);
    }
  scr++;
  address = (order >> 1) & 0x3ff;
  switch (order >> 12) {
    case 28:                                     /* A - Add */
         if (order & 1) {
           address &= 0x1fffe;
           if (trace == 'Y')
             printf("%05x %05x + %05x %05x =",acc[0],acc[1],
                    mem[address+1],mem[address]);
           tmp[0] = mem[address+1];
           tmp[1] = mem[address];
           mbAdd(tmp,2);
           if (trace == 'Y') printf("%05x %05x",acc[0],acc[1]);
           }
         else  {
           if (trace == 'Y') printf("%x+%x",acc[0],mem[address]);
           mbAdd(&mem[address],1);
           if (trace == 'Y') printf("=%x",acc[0]);
           }
#ifdef TEXT
         showAcc();
#endif
         break;

    case 12:                                     /* S - Subtract */
         if (order & 1) {
           address &= 0x1fffe;
           if (trace == 'Y')
             printf("%05x %05x - %05x %05x =",acc[0],acc[1],
                    mem[address+1],mem[address]);
           tmp[0] = mem[address+1];
           tmp[1] = mem[address];
           mbSub(tmp,2);
           if (trace == 'Y') printf("%05x %05x",acc[0],acc[1]);
           }
         else {
           if (trace == 'Y') printf("%x-%x",acc[0],mem[address]);
           mbSub(&mem[address],1);
           if (trace == 'Y') printf("=%x",acc[0]);
           }
#ifdef TEXT
         showAcc();
#endif
         break;

    case 21:                                     /* H - Load multiplier */
         if (order & 1) {
           address &= 0x1fffe;
           multiplier[0] = mem[address+1];
           multiplier[1] = mem[address];
           if (trace == 'Y')
             printf("R = %05x %05x",multiplier[0],multiplier[1]);
           }
         else {
           multiplier[0] = mem[address];
           multiplier[1] = 0;
           if (trace == 'Y') printf("R = %05x",multiplier[0]);
           }
#ifdef TEXT
         showMult();
#endif
         break;

    case 31:                                     /* V - Multiply */
         if (order & 1) {
           if (trace == 'Y')
             printf("%05x %05x * %05x %05x = ",multiplier[0],
                    multiplier[1],mem[address+1],mem[address]);
           lMul(address,'A');
           if (trace == 'Y')
             printf("%05x %05x %05x%05x",acc[0],acc[1],acc[2],
                    acc[3]);
           } else {
           if (trace == 'Y') printf("%05x * %05x = ",multiplier[0],mem[address]);
           sMul(mem[address],'A');
           if (trace == 'Y') printf("%05x %05x",acc[0],acc[1]);
           }
#ifdef TEXT
         showMult();
         showMultiplicand();
         showAcc();
#endif
         break;

    case 22:                                     /* N - Multiply */
         if (order & 1) {
           if (trace == 'Y') printf("%05x %05x * %05x %05x = ",multiplier[0],multiplier[1],mem[address+1],mem[address]);
           lMul(address,'S');
           if (trace == 'Y') printf("%05x %05x %05x%05x",acc[0],acc[1],acc[2],acc[3]);
           }
         else {
           if (trace == 'Y') printf("%05x * %05x = ",multiplier[0],mem[address]);
           sMul(mem[address],'S');
           if (trace == 'Y') printf("%05x %05x",acc[0],acc[1]);
           }
#ifdef TEXT
         showMult();
         showMultiplicand();
         showAcc();
#endif
         break;

    case  5:                                     /* T - Transfer/clear */
         if (order & 1) {
           address &= 0x1fffe;
           mem[address] = acc[1];
           mem[address+1] = acc[0];
#ifdef TEXT
           showMemory(address);
           showMemory(address+1);
#endif
           if (trace == 'Y') printf("[%d]=%5x [%d]=%5x",address+1,acc[0],address,acc[1]);
           }
         else {
           mem[address] = acc[0];
#ifdef TEXT
           showMemory(address);
#endif
           if (trace == 'Y') printf("[%d]=%x",address,acc[0]);
           }
         for (i=0; i<4; i++) acc[i] = 0;
#ifdef TEXT
         showAcc();
#endif
         break;

    case  7:                                     /* U - Transfer */
         if (order & 1) {
           address &= 0x1fffe;
           mem[address] = acc[1];
           mem[address+1] = acc[0];
           if (trace == 'Y') printf("[%d]=%5x [%d]=%5x",address+1,acc[0],address,acc[1]);
#ifdef TEXT
           showMemory(address);
           showMemory(address+1);
#endif
           }
         else {
           if (trace == 'Y') printf("[%d]=%x",address,acc[0]);
           mem[address] = acc[0];
#ifdef TEXT
           showMemory(address);
#endif
           }
         break;

    case 30:                                     /* C - Collate */
         if (order & 1) {
           multiplicand[0] = mem[address+1];
           multiplicand[1] = mem[address];
           doAnd();
           }
         else {
           multiplicand[0] = mem[address];
           multiplicand[1] = 0;
           if (trace == 'Y') printf("%05x + (%05x & %05x) =",acc[0],multiplier[0],multiplicand[0]);
           doAnd();
           if (trace == 'Y') printf(" %05x",acc[0]);
           }
#ifdef TEXT
           showMultiplicand(cpu);
           showAcc(cpu);
#endif
         break;

    case  4:                                     /* R - Shift right */
         b=getShiftCount(order);
         if (trace == 'Y') 
           printf("%05x %05x %05x%05x >> %d = ",acc[0],acc[1],acc[2],acc[3],b);
         for (i=0; i<b; i++) {
           rShift(acc,4);
           }
         if (trace == 'Y') 
           printf("%05x %05x %05x%05x",acc[0],acc[1],acc[2],acc[3]);
#ifdef TEXT
         showAcc(cpu);
#endif
         break;

    case 25:                                     /* L - Shift left */
         b=getShiftCount(order);
         if (trace == 'Y') 
           printf("%05x %05x %05x%05x << %d = ",acc[0],acc[1],acc[2],acc[3],b);
         for (i=0; i<b; i++) {
           lShift(acc,4);
           }
         if (trace == 'Y') 
           printf("%05x %05x %05x%05x",acc[0],acc[1],acc[2],acc[3]);
#ifdef TEXT
         showAcc(cpu);
#endif
         break;

    case  3:                                     /* E - Branch positive */
         if ((acc[0] & 0x10000) == 0) {
           if (trace == 'Y') printf("Positive, jumping --> %d",address);
           scr = address;
           }
         else if (trace == 'Y') printf("Negative, No jump");
         break;

    case 27:                                     /* G - Branch negative */
         if ((acc[0] & 0x10000) != 0) {
           if (trace == 'Y') printf("Negative, jumping --> %d",address);
           scr = address;
           }
         else if (trace == 'Y') printf("Positive, No jump");
         break;

    case  8:                                     /* I - Input */
         if (reader != NULL) b = reader->Read();
           else b = 0xff;
         if (b != 255) {
           if (order & 1) address &= 0x1fffe;
           if (trace == 'Y') printf("[%d]=%x",address+(order & 1),b);
           mem[address + (order & 1)] = b;
           if (order & 1) mem[address] = 0;
           }
         break;

    case  9:                                     /* O - Output */
         b = (mem[address] >> 12) & 0x1ff;
         if (printer != NULL) printer->Print(b);
         lastOutput = b;
         break;

    case 17:                                     /* F - Verify */
         mem[address] = lastOutput << 12;
         if (trace == 'Y') printf("[%d]=%x",address,lastOutput << 12);
         break;

    case 26:                                     /* X - Nop */
         break;

    case  6:                                     /* Y - Extend ABC */
         roundAcc();
#ifdef TEXT
         showAcc();
#endif
         break;

    case 13:                                     /* Z - Stop */
         stopCommand = true;
         if (trace == 'Y') printf("Stopping");
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

