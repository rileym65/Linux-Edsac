#include <stdio.h>
#include <string.h>
#include "Debug.h"

Debug::Debug(Cpu* c) {
  cpu = c;
  debugMode = 'N';
  numBreakpoints = 0;
  traps = 0;
  }

Debug::~Debug() {
  }

Boolean Debug::atBreakpoint() {
  UInt32 i;
  for (i=0; i<numBreakpoints; i++)
    if (cpu->Scr() == breakpoints[i]) return true;
  return trapSet();
  }

void Debug::bp(char* buffer) {
  Int32 i;
  UInt32 bp;
  bp = atoi(buffer);
  for (i=0; i<numBreakpoints; i++)
    if (breakpoints[i] == bp) {
      printf("Breakpoint already set\n");
      return;
      }
  breakpoints[numBreakpoints++] = bp;
  }

void Debug::clear() {
  UInt32  i;
  UInt32 *mem;
  mem = cpu->Memory();
  for (i=0; i<1024; i++) mem[i] = 0;
  }

char Debug::DebugMode() {
  return debugMode;
  }

char Debug::DebugMode(char c) {
  debugMode = c;
  return debugMode;
  }

void Debug::disassemble(char* buffer) {
  Int32   i;
  UInt32  addr;
  String *line;
  addr = (strlen(buffer) > 0) ? atoi(buffer) : cpu->Scr();
  for (i=0; i<16; i++) {
    line = cpu->Disassem(addr+i,cpu->Memory()[addr+i]);
    delete(line);
    printf("\n");
    }
  }

void Debug::dump(char* buffer) {
  Int32  i;
  UInt32 addr;
  addr = (strlen(buffer) > 0) ? atoi(buffer) : cpu->Scr();
  for (i=0; i<16; i++) {
    printf("[%3d] ",addr+i);
    showWord(cpu->Memory()[addr+i]);
    printf("\n");
    }
  }

void Debug::help() {
  printf("BP addr      - Set breakpoint\n");
  printf("CLEAR        - Clear memory\n");
  printf("DIS [addr]   - Disassemble\n");
  printf("DUMP [addr]  - Dump memory\n");
  printf("ORDERS 1|2   - Load initial orders\n");
  printf("REMBP addr   - Remove breakpoint\n");
  printf("RESET        - Reset cpu\n");
  printf("RUN [bp]     - Run to option breakpoint\n");
  printf("SHOWBP       - Show current breakpoins\n");
  printf("SHOWREG      - Show cpu registers\n");
  printf("SHOWTRAPS    - Show all command traps\n");
  printf("STEP         - Execute one instruction\n");
  printf("TANK n       - Show specified tank\n");
  printf("TAPE name    - Attach a tape\n");
  printf("TRACE ON|OFF - Turn command tracing on or off\n");
  printf("TRAP cmd     - Set trap on command\n");
  printf("UNTRAP cmd   - Remove trap on command\n");
  printf("QUIT         - Quit simulator\n");
  printf("HELP         - Show available commands\n");
  }

void Debug::rembp(char* buffer) {
  Int32 i;
  Int32 j;
  UInt32 bp;
  bp = atoi(buffer);
  j = -1;
  for (i=0; i<numBreakpoints; i++)
    if (breakpoints[i] == bp) j = i;
  if (j < 0) {
    printf("Breakpoint not found\n");
    return;
    }
  for (i=j; i<numBreakpoints-1; i++)
    breakpoints[i] = breakpoints[i+1];
  numBreakpoints--;
  }

void Debug::reset() {
  UInt32  i;
  UInt32 *acc;
  acc = cpu->Acc();
  for (i=0; i<4; i++) acc[i] = 0;
  cpu->Scr(0);
  }

Boolean Debug::run(char* buffer) {
  UInt32 addr;
  if (strlen(buffer) == 0) {
    if (numBreakpoints == 0 && traps == 0) {
      debugMode = 'N';
      return false;
      }
    while (atBreakpoint() != 'Y' && !cpu->StopCommand()) cpu->Step();
    } else {
    addr = atoi(buffer);
    while (cpu->Scr() != addr && !cpu->StopCommand()) step();
    }
  return true;
  }

void Debug::showAcc() {
  Int32   i,j;
  UInt32  mask;
  UInt32 *acc;
  mask = 0x8000;
  acc = cpu->Acc();
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
  printf("\n");
  }

void Debug::showbp() {
  UInt32 i;
  for (i=0; i<numBreakpoints; i++) printf("[%3d]\n",breakpoints[i]);
  }

void Debug::showMult() {
  Int32   i;
  UInt32  mask;
  UInt32 *multiplier;
  mask = 0x8000;
  multiplier = cpu->Multiplier();
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
  printf("\n");
  }

void Debug::showMultiplicand() {
  Int32   i;
  UInt32  mask;
  UInt32 *multiplicand;
  mask = 0x8000;
  multiplicand = cpu->Multiplicand();
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
  printf("\n");
  }

void Debug::showreg() {
  printf("Multiplier  : ");
  showMult();
  printf("Multiplicand: ");
  showMultiplicand();
  printf("Accumulator : ");
  showAcc();
  printf("\n");
  }

void Debug::showTank(UInt32 tank) {
  UInt32  mem;
  UInt32 *memory;
  UInt32  i;
  char    side;
  UInt32  mask;
  UInt32  value;
  mem = tank * 32;
  side = 0;
  memory = cpu->Memory();
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
      printf("\n");
      side = 0;
      }
    }
  }

void Debug::showtraps() {
  Int32 i;
  Int32 cmd;
  Boolean tmpShiftMode;
  UInt32 mask;
  mask = 0x80000000;
  cmd = 31;
  tmpShiftMode = cpu->GetPrinter()->ShiftMode();
  cpu->GetPrinter()->ShiftMode(false);
  while (mask != 0) {
    if (traps & mask) printf("%c",cpu->GetPrinter()->Translate(cmd));
      else printf("-");
    cmd--;
    mask >>= 1;
    }
  printf("\n");
  cpu->GetPrinter()->ShiftMode(tmpShiftMode);
  }

void Debug::showWord(UInt32 wrd) {
  UInt32 mask;
  mask = 0x20000;
  while (mask != 0) {
    if (wrd & mask) printf("*"); else printf(".");
    mask >>= 1;
    if (mask == 0x10000) printf(" ");
    if (mask == 0x800) printf(" ");
    if (mask == 0x400) printf(" ");
    if (mask == 0x1) printf(" ");
    }
  printf("  %05x",wrd);
  }

void Debug::step() {
  cpu->Step();
  }

void Debug::tank(char* buffer) {
  showTank(atoi(buffer));
  }

void Debug::trap(char* buffer) {
  UInt32 cmd;
  while (buffer[0] == ' ') buffer++;
  cmd = cpu->GetReader()->Translate(buffer[0]);
  traps |= (1 << cmd);
  }

void Debug::tape(char* buffer) {
  if (!cpu->GetReader()->Mount(buffer)) {
    printf("Could not open tape file: %s\n",buffer);
    }
  }

Boolean Debug::trapSet() {
  UInt32 opcode;
  if (traps == 0) return 'N';
  opcode = cpu->Memory()[cpu->Scr()] >> 12;
  if (traps & (1 << opcode)) return true;
  return false;
  }

void Debug::untrap(char* buffer) {
  int cmd;
  while (buffer[0] == ' ') buffer++;
  cmd = cpu->GetReader()->Translate(buffer[0]);
  traps &= ~(1 << cmd);
  }

void Debug::Debugger() {
  char buffer[1024];
  char flag;
  UInt32 order;
  String *line;
  flag = 'Y';
  while (flag == 'Y') {
    order = cpu->Fetch(cpu->Scr());
    line = cpu->Disassem(cpu->Scr(),order);
    printf("%s>",line->AsCharArray());
    delete(line);
    fgets(buffer,1023,stdin);
    while (buffer[0] != 0 && buffer[strlen(buffer)-1] < ' ')
      buffer[strlen(buffer)-1] = 0;
    if (strlen(buffer) == 0) cpu->Step();
    if (strcasecmp(buffer,"help") == 0) help();
    if (strcasecmp(buffer,"orders 1") == 0) cpu->LoadOrders1();
    if (strcasecmp(buffer,"orders 2") == 0) cpu->LoadOrders2();
    if (strcasecmp(buffer,"reset") == 0) reset();
    if (strcasecmp(buffer,"clear") == 0) clear();
    if (strcasecmp(buffer,"step") == 0) cpu->Step();
    if (strncasecmp(buffer,"bp ",3) == 0) bp(buffer+3);
    if (strncasecmp(buffer,"dis",3) == 0) disassemble(buffer+3);
    if (strncasecmp(buffer,"dump",4) == 0) dump(buffer+4);
    if (strncasecmp(buffer,"run",3) == 0) flag = run(buffer+3);
    if (strncasecmp(buffer,"rembp ",6) == 0) rembp(buffer+6);
    if (strncasecmp(buffer,"tank ",5) == 0) tank(buffer+5);
    if (strncasecmp(buffer,"trap ",5) == 0) trap(buffer+5);
    if (strncasecmp(buffer,"tape ",5) == 0) tape(buffer+5);
    if (strncasecmp(buffer,"untrap ",7) == 0) untrap(buffer+7);
    if (strcasecmp(buffer,"showbp") == 0) showbp();
    if (strcasecmp(buffer,"showreg") == 0) showreg();
    if (strcasecmp(buffer,"showtraps") == 0) showtraps();
    if (strcasecmp(buffer,"trace on") == 0) cpu->Trace('Y');
    if (strcasecmp(buffer,"trace off") == 0) cpu->Trace('N');
    if (strcasecmp(buffer,"quit") == 0) {
      flag = 'N';
      }
    }
  }

