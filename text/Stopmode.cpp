#include "header.h"

void smHelp() {
  printf("0-9           - Enter number on dial and run\n");
  printf("REGS          - Show registers\n");
  printf("Tn            - Show tank n\n");
  printf("QUIT          - Quit simulator\n");
  printf("HELP          - Show available commands\n");
  }

void smTank(char* buffer) {
  debugger->showTank(atoi(buffer));
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

