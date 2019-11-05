#include "header.h"

#ifdef TEXT
#include "terminal.h"
#endif

uint32_t orders1[] = {
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
  };

uint32_t orders2[] = {
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
  };

void dumpX(uint32_t* value,int num) {
  uint32_t mask;
  int      i;
  for (i=0; i<num; i++) {
    mask = 0x20000;
    if (value[i] > 0x3ffff) printf("BAD!!!!!!!");
    while (mask != 0) {
      if (value[i] & mask) printf("*"); else printf("0");
      mask >>= 1;
      }
    printf(" ");
    }
  printf("\n");
  }

void reset(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<1024; i++) cpu->mem[i] = 0;
  for (i=0; i<4; i++) cpu->acc[i] = 0;
  cpu->scr = 0;
  }

void loadOrders1(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<31; i++) cpu->mem[i] = orders1[i];
  }

void loadOrders2(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<41; i++) cpu->mem[i] = orders2[i];
  }

uint32_t fetch(EDSAC_CPU* cpu,uint32_t addr) {
  return cpu->mem[addr];
  }

byte getShiftCount(uint32_t a) {
  byte r;
  r = 1;
  while (r < 17 && ((a & 1) != 1)) {
    r++;
    a >>= 1;
    }
  return r;
  }

/* ********************************************************* */
/* ***** Convert number in byte array to 2s compliment ***** */
/* ***** Array is in big-endian order                  ***** */
/* ***** High byte is considered 17 bits               ***** */
/* ***** All others are 18 bits                        ***** */
/* ********************************************************* */
void twosComp(uint32_t* number,int num) {
  int i;
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

void lShift(uint32_t* number,int num) {
  int c;
  int i;
  c = 0;
  for (i=num-1; i>=0; i--) {
    number[i] = (number[i] << 1) + c;
    c = (number[i] & 0x40000) ? 1 : 0;
    number[i] &= 0x3ffff;
    }
  number[0] &= 0x1ffff;
  }

void rShift(uint32_t* number,int num) {
  int c;
  int tc;
  int i;
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

void mbAdd(EDSAC_CPU* cpu,uint32_t* value,int words) {
  byte c;
  int  i;
  c = 0;
  for (i=words-1; i>= 0; i--) {
    cpu->acc[i] += (value[i] + c);
    c = (cpu->acc[i] & 0x40000) ? 1 : 0;
    cpu->acc[i] &= 0x3ffff;
    }
  cpu->acc[0] &= 0x1ffff;
  }

void mbSub(EDSAC_CPU* cpu,uint32_t* value,int words) {
  uint32_t tmp[8];
  int      i;
  for (i=0; i<words; i++) tmp[i] = value[i];
  twosComp(tmp,words);
  mbAdd(cpu,tmp,words);
  }

int prepForMul(uint32_t* number) {
  if (number[2] & 0x10000) {
    number[0] = 0xffffffff;
    number[1] = 0xffffffff;
    number[2] |= 0xffff0000;
    twosComp(number,4);
    return 1;
    }
  return 0;
  }

void doMul(EDSAC_CPU* cpu,char mode) {
  byte sign;
  uint32_t tmp[4];
  uint32_t a[4];
  a[3] = cpu->multiplicand[1];
  a[2] = cpu->multiplicand[0];
  a[1] = 0;
  a[0] = 0;
  tmp[3] = cpu->multiplier[1];
  tmp[2] = cpu->multiplier[0];
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
      if (mode == 'A') mbAdd(cpu,tmp,4); else mbSub(cpu,tmp,4);
      }
    lShift(tmp,4);
    rShift(a,4);
    }
  }

void sMul(EDSAC_CPU* cpu,uint32_t a,char mode) {
  int i;
  uint32_t tmp[2];
  cpu->multiplicand[0] = a;
  cpu->multiplicand[1] = 0;
  doMul(cpu,mode);
  }

void lMul(EDSAC_CPU* cpu,uint32_t address,char mode) {
  int i;
  uint32_t c,t;
  cpu->multiplicand[1] = cpu->mem[address];
  cpu->multiplicand[0] = cpu->mem[address+1];
  doMul(cpu,mode);
  }

void and(EDSAC_CPU* cpu) {
  uint32_t tmp[2];
  tmp[0] = cpu->multiplier[0] & cpu->multiplicand[0];
  tmp[1] = cpu->multiplier[1] & cpu->multiplicand[1];
  mbAdd(cpu,tmp,2);
  }

void roundAcc(EDSAC_CPU* cpu) {
  uint32_t tmp[4];
  tmp[0] = 0;
  tmp[1] = 0;
  tmp[2] = 0x20000;
  tmp[3] = 0;
  mbAdd(cpu,tmp,4);
  }

void step(EDSAC_CPU* cpu) {
  int      i;
  uint32_t c;
  byte     b;
  uint32_t address;
  uint32_t tmp[2];
  cpu->order = fetch(cpu,cpu->scr);
  if (trace == 'Y') {
    disassem(cpu,cpu->scr,cpu->order);
    }
  cpu->scr++;
  address = (cpu->order >> 1) & 0x3ff;
  switch (cpu->order >> 12) {
    case 28: if (cpu->order & 1) {                    /* A - Add */
               address &= 0x1fffe;
               if (trace == 'Y')
                 printf("%05x %05x + %05x %05x =",cpu->acc[0],cpu->acc[1],
                        cpu->mem[address+1],cpu->mem[address]);
               tmp[0] = cpu->mem[address+1];
               tmp[1] = cpu->mem[address];
               mbAdd(cpu,tmp,2);
               if (trace == 'Y') printf("%05x %05x",cpu->acc[0],cpu->acc[1]);
               }
             else  {
               if (trace == 'Y') printf("%x+%x",cpu->acc[0],cpu->mem[address]);
               mbAdd(cpu,&cpu->mem[address],1);
               if (trace == 'Y') printf("=%x",cpu->acc[0]);
               }
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case 12: if (cpu->order & 1) {                    /* S - Subtract */
               address &= 0x1fffe;
               if (trace == 'Y')
                 printf("%05x %05x - %05x %05x =",cpu->acc[0],cpu->acc[1],
                        cpu->mem[address+1],cpu->mem[address]);
               tmp[0] = cpu->mem[address+1];
               tmp[1] = cpu->mem[address];
               mbSub(cpu,tmp,2);
               if (trace == 'Y') printf("%05x %05x",cpu->acc[0],cpu->acc[1]);
               }
             else {
               if (trace == 'Y') printf("%x-%x",cpu->acc[0],cpu->mem[address]);
               mbSub(cpu,&cpu->mem[address],1);
               if (trace == 'Y') printf("=%x",cpu->acc[0]);
               }
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case 21: if (cpu->order & 1) {                   /* H - Load multiplier */
               address &= 0x1fffe;
               cpu->multiplier[0] = cpu->mem[address+1];
               cpu->multiplier[1] = cpu->mem[address];
               if (trace == 'Y')
                 printf("R = %05x %05x",cpu->multiplier[0],cpu->multiplier[1]);
               } else {
               cpu->multiplier[0] = cpu->mem[address];
               cpu->multiplier[1] = 0;
               if (trace == 'Y') printf("R = %05x",cpu->multiplier[0]);
               }
#ifdef TEXT
             showMult(cpu);
#endif
             break;
    case 31: if (cpu->order & 1) {                    /* V - Multiply + */
               if (trace == 'Y')
                 printf("%05x %05x * %05x %05x = ",cpu->multiplier[0],
                        cpu->multiplier[1],cpu->mem[address+1],cpu->mem[address]);
               lMul(cpu,address,'A');
               if (trace == 'Y')
                 printf("%05x %05x %05x%05x",cpu->acc[0],cpu->acc[1],cpu->acc[2],
                        cpu->acc[3]);
               } else {
               if (trace == 'Y') printf("%05x * %05x = ",cpu->multiplier[0],cpu->mem[address]);
               sMul(cpu,cpu->mem[address],'A');
               if (trace == 'Y') printf("%05x %05x",cpu->acc[0],cpu->acc[1]);
               }
#ifdef TEXT
             showMult(cpu);
             showMultiplicand(cpu);
             showAcc(cpu);
#endif
             break;
    case 22: if (cpu->order & 1) {                    /* N - Multiply - */
               if (trace == 'Y') printf("%05x %05x * %05x %05x = ",cpu->multiplier[0],cpu->multiplier[1],cpu->mem[address+1],cpu->mem[address]);
               lMul(cpu,address,'S');
               if (trace == 'Y') printf("%05x %05x %05x%05x",cpu->acc[0],cpu->acc[1],cpu->acc[2],cpu->acc[3]);
               } else {
               if (trace == 'Y') printf("%05x * %05x = ",cpu->multiplier[0],cpu->mem[address]);
               sMul(cpu,cpu->mem[address],'S');
               if (trace == 'Y') printf("%05x %05x",cpu->acc[0],cpu->acc[1]);
               }
#ifdef TEXT
             showMult(cpu);
             showMultiplicand(cpu);
             showAcc(cpu);
#endif
             break;
    case  5: if (cpu->order & 1) {                    /* T - Transfer/clear */
               address &= 0x1fffe;
               cpu->mem[address] = cpu->acc[1];
               cpu->mem[address+1] = cpu->acc[0];
#ifdef TEXT
               showMemory(cpu, address);
               showMemory(cpu, address+1);
#endif
               if (trace == 'Y') printf("[%d]=%5x [%d]=%5x",address+1,cpu->acc[0],address,cpu->acc[1]);
               } else {
               cpu->mem[address] = cpu->acc[0];
#ifdef TEXT
               showMemory(cpu, address);
#endif
               if (trace == 'Y') printf("[%d]=%x",address,cpu->acc[0]);
               }
             for (i=0; i<4; i++) cpu->acc[i] = 0;
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case  7: if (cpu->order & 1) {                    /* U - Transfer */
               address &= 0x1fffe;
               cpu->mem[address] = cpu->acc[1];
               cpu->mem[address+1] = cpu->acc[0];
               if (trace == 'Y') printf("[%d]=%5x [%d]=%5x",address+1,cpu->acc[0],address,cpu->acc[1]);
#ifdef TEXT
               showMemory(cpu, address);
               showMemory(cpu, address+1);
#endif
               } else {
               if (trace == 'Y') printf("[%d]=%x",address,cpu->acc[0]);
               cpu->mem[address] = cpu->acc[0];
#ifdef TEXT
               showMemory(cpu, address);
#endif
               }
             break;
    case 30: if (cpu->order & 1) {                    /* C - Collate */
               cpu->multiplicand[0] = cpu->mem[address+1];
               cpu->multiplicand[1] = cpu->mem[address];
               and(cpu);
               } else {
               cpu->multiplicand[0] = cpu->mem[address];
               cpu->multiplicand[1] = 0;
               if (trace == 'Y') printf("%05x + (%05x & %05x) =",cpu->acc[0],cpu->multiplier[0],cpu->multiplicand[0]);
               and(cpu);
               if (trace == 'Y') printf(" %05x",cpu->acc[0]);
               }
#ifdef TEXT
               showMultiplicand(cpu);
               showAcc(cpu);
#endif
             break;
    case  4: b=getShiftCount(cpu->order);             /* R - Shift right */
             if (trace == 'Y') 
               printf("%05x %05x %05x%05x >> %d = ",cpu->acc[0],cpu->acc[1],cpu->acc[2],cpu->acc[3],b);
             for (i=0; i<b; i++) {
               rShift(cpu->acc,4);
               }
             if (trace == 'Y') 
               printf("%05x %05x %05x%05x",cpu->acc[0],cpu->acc[1],cpu->acc[2],cpu->acc[3]);
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case 25: b=getShiftCount(cpu->order);             /* L - Shift left */
             if (trace == 'Y') 
               printf("%05x %05x %05x%05x << %d = ",cpu->acc[0],cpu->acc[1],cpu->acc[2],cpu->acc[3],b);
             for (i=0; i<b; i++) {
               lShift(cpu->acc,4);
               }
             if (trace == 'Y') 
               printf("%05x %05x %05x%05x",cpu->acc[0],cpu->acc[1],cpu->acc[2],cpu->acc[3]);
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case  3: if ((cpu->acc[0] & 0x10000) == 0) {      /* E - Branch Positive */
               if (trace == 'Y') printf("Positive, jumping --> %d",address);
               cpu->scr = address;
               } else if (trace == 'Y') printf("Negative, No jump");
             break;
    case 27: if ((cpu->acc[0] & 0x10000) != 0) {      /* G - Branch Negative */
               if (trace == 'Y') printf("Negative, jumping --> %d",address);
               cpu->scr = address;
               } else if (trace == 'Y') printf("Positive, No jump");
             break;
    case  8: b = readTape();                          /* I - Input */
             if (b != 255) {
               if (cpu->order & 1) address &= 0x1fffe;
               if (trace == 'Y') printf("[%d]=%x",address+(cpu->order & 1),b);
               cpu->mem[address + (cpu->order & 1)] = b;
               if (cpu->order & 1) cpu->mem[address] = 0;
               }
             break;
    case  9: b = (cpu->mem[address] >> 12) & 0x1ff;   /* O - Output */
             print(b);
             cpu->lastOutput = b;
             break;
    case 17:                                          /* F - Verify */
            cpu->mem[address] = cpu->lastOutput << 12;
               if (trace == 'Y') printf("[%d]=%x",address,cpu->lastOutput << 12);
             break;
    case 26:                                          /* X - Nop */
             break;
    case  6: roundAcc(cpu);                           /* Y - Extend ABC */
#ifdef TEXT
             showAcc(cpu);
#endif
             break;
    case 13: stopCommand = 'Y';                       /* Z - Stop */
             if (trace == 'Y') printf("Stopping");
             break;
    default:
             printf("Bad instruction\n");
             stopCommand = 'Y';
    }
  if (trace == 'Y') {
    printf("\n");
    }
  }

