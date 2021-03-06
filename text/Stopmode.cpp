#include <string.h>
#include "header.h"
#include "Terminal.h"

void smHelp() {
  printer->Print("0-9       - Enter number on dial and run\r\n");
  printer->Print("BP addr   - Set breakpoint at addr\r\n");
  printer->Print("CLEAR     - Clear store\r\n");
  printer->Print("LSBP      - List breakpoints\r\n");
  printer->Print("ORDERSn   - Set initial orders. n=1 or 2\r\n");
  printer->Print("RMBP addr - Remove breakpoint at addr\r\n");
  printer->Print("RUN       - Continue execution\r\n");
  printer->Print("START     - Load initial orders and run\r\n");
  printer->Print("STEP      - Execute 1 cycle\r\n");
  printer->Print("Tn        - Show tank n\r\n");
  printer->Print("TAPE name - Mount tape\r\n");
  printer->Print("TRACE st  - Turn on trace st=ON/OFF\r\n");
  printer->Print("QUIT      - Quit simulator\r\n");
  printer->Print("HELP      - Show available commands\r\n");
  }

void smTank(char* buffer) {
  showTank(atoi(buffer));
  currentTank = atoi(buffer);
  }

void smClear() {
  UInt32 i;
  UInt32 *mem;
  mem = cpu->Memory();
  for (i=0; i<1024; i++) mem[i] = 0;
  showTank(currentTank);
  }

void StopMode() {
  UInt32 i;
  char flag;
  char buffer[1024];
  char buffer1[1024];
  flag = 'N';
  ShowCursor();
  while (flag != 'Y') {
    GotoXY(1, 22);
    printf("                                    ");
    GotoXY(1, 22);
    printf("STOP> ");
    fgets(buffer,1023,stdin);
    while (buffer[0] > 0 && buffer[strlen(buffer)-1] < ' ')
      buffer[strlen(buffer)-1] = 0;
    if (strcasecmp(buffer,"run") == 0) {
      cpu->StopCommand(false);
      flag = 'Y';
      }
    if (strncasecmp(buffer,"t",1) == 0 &&
        buffer[1] >= '0' && buffer[1] <= '9') smTank(buffer+1);
    if (strncasecmp(buffer,"bp ",3) == 0) {
      i = atoi(buffer+3);
      if (i < 1024) {
        breakPoints[i] = true;
        sprintf(buffer1,"Breakpoint set at %d\r\n",i);
        printer->Print(buffer1);
        }
      }
    if (strncasecmp(buffer,"rmbp ",5) == 0) {
      i = atoi(buffer+5);
      if (i < 1024) {
        breakPoints[i] = false;
        sprintf(buffer1,"Breakpoint removed at %d\r\n",i);
        printer->Print(buffer1);
        }
      }
    if (strcasecmp(buffer,"quit") == 0) { stopSim = 'Y'; flag = 'Y'; }
    if (strcasecmp(buffer,"clear") == 0) smClear();
    if (strcasecmp(buffer,"listbp") == 0) {
      for (i=0; i<1024; i++)
        if (breakPoints[i]) {
          sprintf(buffer1,"Breakpoint: %d\r\n",i);
          printer->Print(buffer1);
          }
      }
    if (strcasecmp(buffer,"orders1") == 0) cpu->InitialOrders(1);
    if (strcasecmp(buffer,"orders2") == 0) cpu->InitialOrders(2);
    if (strcasecmp(buffer,"trace on") == 0) cpu->Trace('Y');
    if (strcasecmp(buffer,"trace off") == 0) cpu->Trace('N');
    if (strcasecmp(buffer,"start") == 0) {
      cpu->Start();
      flag = 'Y';
      }
    if (strcasecmp(buffer,"step") == 0 || strcasecmp(buffer,"s") == 0) {
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
  GotoXY(1, 22);
  printf("                                    \n");
  HideCursor();
  }

