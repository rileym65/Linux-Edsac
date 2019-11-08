#include "header.h"

void smHelp() {
  printf("0-9       - Enter number on dial and run\n");
  printf("CLEAR     - Clear store\r\n");
  printf("ORDERSn   - Set initial orders. n=1 or 2\r\n");
  printf("RUN       - Continue execution\r\n");
  printf("START     - Load initial orders and run\r\n");
  printf("STEP      - Execute 1 cycle\r\n");
  printf("REGS      - Show registers\n");
  printf("Tn        - Show tank n\n");
  printf("TAPE name - Mount tape\r\n");
  printf("QUIT      - Quit simulator\n");
  printf("HELP      - Show available commands\n");
  }

void smTank(char* buffer) {
  debugger->showTank(atoi(buffer));
  }

void smClear() {
  UInt32 i;
  UInt32 *mem;
  mem = cpu->Memory();
  for (i=0; i<1024; i++) mem[i] = 0;
  }

void smShowreg() {
  printf("Multiplier  : ");
  debugger->showMult();
  printf("Multiplicand: ");
  debugger->showMultiplicand();
  printf("Accumulator : ");
  debugger->showAcc();
  printf("\n");
  }

void StopMode() {
  char flag;
  char buffer[1024];
  flag = 'N';
  while (flag != 'Y') {
    printf("\nSTOP> ");
    fgets(buffer,1023,stdin);
    while (buffer[0] > 0 && buffer[strlen(buffer)-1] < ' ')
      buffer[strlen(buffer)-1] = 0;
    if (strcasecmp(buffer,"regs") == 0) smShowreg();
    if (strcasecmp(buffer,"run") == 0) {
      cpu->StopCommand(false);
      flag = 'Y';
      }
    if (strncasecmp(buffer,"t",1) == 0) smTank(buffer+1);
    if (strcasecmp(buffer,"quit") == 0) { stopSim = 'Y'; flag = 'Y'; }
    if (strcasecmp(buffer,"clear") == 0) smClear();
    if (strcasecmp(buffer,"orders1") == 0) cpu->InitialOrders(1);
    if (strcasecmp(buffer,"orders2") == 0) cpu->InitialOrders(2);
    if (strcasecmp(buffer,"start") == 0) {
      cpu->Start();
      flag = 'Y';
      }
    if (strcasecmp(buffer,"step") == 0) {
      singleStep = true;
      cpu->StopCommand(false);
      flag = 'Y';
      }
    if (strncasecmp(buffer,"tape ",5) == 0) {
      if (!reader->Mount(buffer+5)) {
        printer->Print("Could not open tape\r\n");
        }
      else printer->Print("Tape mounted\r\n");
      }

    if (strcasecmp(buffer,"help") == 0) smHelp();
    if (buffer[0] == '0') {
      cpu->Acc()[0] = 10 << 1;
      cpu->StopCommand(false);
      flag = 'Y';
      }
    if (buffer[0] >= '1' && buffer[0] <= '9') {
      cpu->Acc()[0] = (buffer[0] - '0') << 1;
      cpu->StopCommand(false);
      flag = 'Y';
      }
    }
  }

