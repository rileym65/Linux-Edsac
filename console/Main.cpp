#define MAIN

#include "header.h"
#include "Cpu.h"
#include "Reader.h"
#include "Printer.h"
#include "Debug.h"

int main(int argc,char** argv) {
  byte i;
  char tapeFilename[1024];
  cpu = new Cpu();
  reader = new Reader();
  printer = new Printer();
  cpu->AttachReader(reader);
  cpu->AttachPrinter(printer);
  debugger = new Debug(cpu);
  initialOrders = 2;
  singleStep = false;
  strcpy(tapeFilename,"");
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-d") == 0) debugger->DebugMode('Y');
    if (strcmp(argv[i],"-1") == 0) initialOrders = 1;
    if (strcmp(argv[i],"-2") == 0) initialOrders = 2;
    if (strcmp(argv[i],"-t") == 0) cpu->Trace('Y');
    if (strcmp(argv[i],"-1949") == 0) cpu->Only1949(true);
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
  cpu->Reset();
  if (initialOrders == 1) cpu->LoadOrders1();
    else cpu->LoadOrders2();
  i = 0;
  cycles = 0;
  cpu->StopCommand(false);
  stopSim = 'N';
  if (debugger->DebugMode() == 'Y') debugger->Debugger();
  while (stopSim != 'Y') {
    if (!cpu->StopCommand()) {
      cpu->Step();
      cycles++;
      if (singleStep) {
        singleStep = false;
        cpu->StopCommand(true);
        }
      }
    else StopMode();
    }
  return 0;
  }

