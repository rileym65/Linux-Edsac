#define MAIN

#include "header.h"
#include "terminal.h"

int main(int argc,char** argv) {
  byte i;
  char tapeFilename[1024];
  EDSAC_CPU cpu;
  tapeRemark = 'N';
  debugMode = 'N';
  trace = 'N';
  numBreakpoints = 0;
  initialOrders = 2;
  tape = NULL;
  traps = 0;
  strcpy(tapeFilename,"");
  for (i=0; i<16; i++)
    strcpy(printer[i],"                                        ");
  printerPos = 0;
  printerLine = 0;
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-d") == 0) debugMode = 'Y';
    if (strcmp(argv[i],"-1") == 0) initialOrders = 1;
    if (strcmp(argv[i],"-2") == 0) initialOrders = 2;
    if (strcmp(argv[i],"-t") == 0) trace = 'Y';
    if (argv[i][0] != '-') {
      strcpy(tapeFilename,argv[i]);
      if (tapeFilename[strlen(tapeFilename)-1] == '1') initialOrders = 1;
      if (tapeFilename[strlen(tapeFilename)-1] == '2') initialOrders = 2;
      }
    }
  printf("Initial Orders: %d\n",initialOrders);
  if (debugMode == 'Y') trace = 'Y';
  if (strlen(tapeFilename) > 0) {
    tape = fopen(tapeFilename,"r");
    if (tape == NULL) {
      printf("Could not open tape file: %s\n",tapeFilename);
      exit(1);
      }
    }
  ClrScr();
  reset(&cpu);
  if (initialOrders == 1) loadOrders1(&cpu);
    else loadOrders2(&cpu);
  i = 0;
  cycles = 0;
  stopCommand = 'N';
  stopSim = 'N';
  currentTank = 0;
  showTank(&cpu, currentTank);
  showAcc(&cpu);
  showMult(&cpu);
  showMultiplicand(&cpu);
  if (debugMode == 'Y') debug(&cpu);
  HideCursor();
  while (stopSim != 'Y') {
    if (stopCommand != 'Y') {
      step(&cpu);
      cycles++;
/*      if (cycles > 1000000) stopCommand = 'Y';  */
      }
    else stopMode(&cpu);
    }
  ShowCursor();
  return 0;
  }

