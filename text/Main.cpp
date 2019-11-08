#define MAIN

#include "header.h"
#include "Cpu.h"
#include "Reader.h"
#include "Printer.h"
#include "Debug.h"
#include "Terminal.h"

UInt32 lastAcc[4];
UInt32 lastMultiplier[2];
UInt32 lastMultiplicand[2];

void showScr() {
  UInt32 i;
  UInt32 mask;
  UInt32 scr;
  scr = cpu->Scr();
  mask = 0x200;
  GotoXY(53, 18);
  printf("Scr   : ");
  for (i=0; i<10; i++) {
    if (scr & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  }

void showOrder() {
  UInt32 i;
  UInt32 mask;
  UInt32 order;
  order = cpu->Order();
  mask = 0x10000;
  GotoXY(53, 19);
  printf("Order : ");
  for (i=0; i<17; i++) {
    if (order & mask) printf("*"); else printf(".");
    if (i == 4) printf(" ");
    if (i == 5) printf(" ");
    if (i == 15) printf(" ");
    mask >>= 1;
    }
  }

void showAcc() {
  Int32   i,j;
  UInt32  mask;
  UInt32 *acc;
  acc = cpu->Acc();
  if (acc[0] == lastAcc[0] &&
      acc[1] == lastAcc[1] &&
      acc[2] == lastAcc[2] &&
      acc[3] == lastAcc[3]) return;
  lastAcc[0] = acc[0];
  lastAcc[1] = acc[1];
  lastAcc[2] = acc[2];
  lastAcc[3] = acc[3];
  GotoXY(1, 20);
  printf("Accumulator : ");
  mask = 0x8000;
  if (acc[0] & 0x10000) printf("* "); else printf(". ");
  for (i=0; i<16; i++) {
    if (acc[0] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  for (j=1; j<4; j++) {
    printf(" ");
    mask = 0x20000;
    for (i=0; i<18; i++) {
      if (acc[j] & mask) printf("*"); else printf(".");
      mask >>= 1;
      }
    if (j == 1) printf("\n             ");
    }
  fflush(stdout);
  }

void showMemory(UInt32 address) {
  UInt32 mask;
  UInt32 value;
  Int32 line;
  if (address < currentTank * 32) return;
  if (address >= (currentTank+1) * 32) return;
  value = cpu->Memory()[address];
  line = (address % 32) >> 1;
  if (address & 1) GotoXY(1, 16-line);
    else GotoXY(19, 16-line);
  mask = 0x20000;
  while (mask != 0) {
    if (value & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  fflush(stdout);
  }

void showMult() {
  Int32   i;
  UInt32  mask;
  UInt32 *multiplier;
  mask = 0x8000;
  multiplier = cpu->Multiplier();
  if (multiplier[0] == lastMultiplier[0] &&
      multiplier[1] == lastMultiplier[1]) return;
  lastMultiplier[0] = multiplier[0];
  lastMultiplier[1] = multiplier[1];
  GotoXY(1, 18);
  printf("Multiplier  : ");
  if (multiplier[0] & 0x10000) printf("* "); else printf(". ");
  for (i=0; i<16; i++) {
    if (multiplier[0] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  printf(" ");
  mask = 0x20000;
  for (i=0; i<18; i++) {
    if (multiplier[1] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  fflush(stdout);
  }

void showMultiplicand() {
  Int32   i;
  UInt32  mask;
  UInt32 *multiplicand;
  multiplicand = cpu->Multiplicand();
  if (multiplicand[0] == lastMultiplicand[0] &&
      multiplicand[1] == lastMultiplicand[1]) return;
  lastMultiplicand[0] = multiplicand[0];
  lastMultiplicand[1] = multiplicand[1];
  GotoXY(1, 19);
  printf("Multiplicand: ");
  mask = 0x8000;
  if (multiplicand[0] & 0x10000) printf("* "); else printf(". ");
  for (i=0; i<16; i++) {
    if (multiplicand[0] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  printf(" ");
  mask = 0x20000;
  for (i=0; i<18; i++) {
    if (multiplicand[1] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  fflush(stdout);
  }

void showTank(int tank) {
  Int32   mem;
  Int32   i;
  Int32   line;
  char    side;
  UInt32  mask;
  UInt32  value;
  UInt32 *memory;
  mem = tank * 32;
  side = 0;
  line = 1;
  memory = cpu->Memory();
  GotoXY(1, line);
  for (i=31; i>=0 ;i--) {
    value = memory[mem+i];
    mask = 0x20000;
    while (mask != 0) {
      if (value & mask) printf("*"); else printf(".");
      mask >>= 1;
      }
    if (side == 0) {
      side = 1;
      } else {
      line++;
      GotoXY(1, line);
      side = 0;
      }
    }
  fflush(stdout);
  }

int main(int argc,char** argv) {
  byte i;
  UInt32 changes;
  char tapeFilename[1024];
  for (i=0; i<4; i++) lastAcc[i] = 0xffffffff;
  for (i=0; i<2; i++) lastMultiplier[i] = 0xffffffff;
  for (i=0; i<2; i++) lastMultiplicand[i] = 0xffffffff;
  cpu = new Cpu();
  reader = new Reader();
  printer = new Printer();
  cpu->AttachReader(reader);
  cpu->AttachPrinter(printer);
  debugger = new Debug(cpu);
  initialOrders = 2;
  currentTank = 0;
  singleStep = false;
  strcpy(tapeFilename,"");
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-d") == 0) debugger->DebugMode('Y');
    if (strcmp(argv[i],"-1") == 0) initialOrders = 1;
    if (strcmp(argv[i],"-2") == 0) initialOrders = 2;
    if (strcmp(argv[i],"-t") == 0) cpu->Trace('Y');
    if (argv[i][0] != '-') {
      strcpy(tapeFilename,argv[i]);
      if (tapeFilename[strlen(tapeFilename)-1] == '1') initialOrders = 1;
      if (tapeFilename[strlen(tapeFilename)-1] == '2') initialOrders = 2;
      }
    }
  printf("Initial Orders: %d\n",initialOrders);
  if (debugger->DebugMode() == 'Y') cpu->Trace('Y');
  if (strlen(tapeFilename) > 0) {
    if (!reader->Mount(tapeFilename)) {
      printf("Could not open tape file: %s\n",tapeFilename);
      exit(1);
      }
    }
  ClrScr();
  cpu->Reset();
  if (initialOrders == 1) cpu->LoadOrders1();
    else cpu->LoadOrders2();
  i = 0;
  cycles = 0;
  cpu->StopCommand(false);
  showTank(0);
  showMult();
  showMultiplicand();
  showAcc();
  stopSim = 'N';
  HideCursor();
  if (debugger->DebugMode() == 'Y') debugger->Debugger();
  while (stopSim != 'Y') {
    if (!cpu->StopCommand()) {
      cpu->Step();
      changes = cpu->Changes();
      if (changes & CH_IER) showMult();
      if (changes & CH_ICAND) showMultiplicand();
      if (changes & CH_ACC) showAcc();
      if (changes & CH_MEM_1) showMemory(cpu->Address1());
      if (changes & CH_MEM_2) showMemory(cpu->Address2());
      showScr();
      showOrder();
      cycles++;
      if (singleStep) {
        singleStep = false;
        cpu->StopCommand(true);
        }
      }
    else StopMode();
    }
  ShowCursor();
  return 0;
  }

