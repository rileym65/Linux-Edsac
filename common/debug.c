#include "header.h"

void debug_help() {
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

void debug_reset(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<4; i++) cpu->acc[i] = 0;
  cpu->scr = 0;
  }

void debug_clear(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<1024; i++) cpu->mem[i] = 0;
  }

void showWord(uint32_t wrd) {
  uint32_t mask;
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

char trapSet(EDSAC_CPU* cpu) {
  uint32_t opcode;
  if (traps == 0) return 'N';
  opcode = cpu->mem[cpu->scr] >> 12;
  if (traps & (1 << opcode)) return 'Y';
  return 'N';
  }

char atBreakpoint(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<numBreakpoints; i++)
    if (cpu->scr == breakpoints[i]) return 'Y';
  return trapSet(cpu);
  }

void debug_showbp(EDSAC_CPU* cpu) {
  int i;
  for (i=0; i<numBreakpoints; i++) printf("[%3d]\n",breakpoints[i]);
  }

void debug_showreg(EDSAC_CPU* cpu) {
  printf("Multiplier  : ");
  showMult(cpu);
  printf("Multiplicand: ");
  showMultiplicand(cpu);
  printf("Accumulator : ");
  showAcc(cpu);
  printf("\n");
  }

void debug_step(EDSAC_CPU* cpu) {
  step(cpu);
  cycles++;
  }

void debug_tank(EDSAC_CPU* cpu,char* buffer) {
  showTank(cpu,atoi(buffer));
  }

void debug_dis(EDSAC_CPU* cpu,char* buffer) {
  int  i;
  word addr;
  addr = (strlen(buffer) > 0) ? atoi(buffer) : cpu->scr;
  for (i=0; i<16; i++) {
    disassem(cpu,addr+i,cpu->mem[addr+i]);
    printf("\n");
    }
  }

void debug_dump(EDSAC_CPU* cpu,char* buffer) {
  int  i;
  word addr;
  addr = (strlen(buffer) > 0) ? atoi(buffer) : cpu->scr;
  for (i=0; i<16; i++) {
    printf("[%3d] ",addr+i);
    showWord(cpu->mem[addr+i]);
    printf("\n");
    }
  }

void debug_bp(EDSAC_CPU* cpu,char* buffer) {
  int i;
  word bp;
  bp = atoi(buffer);
  for (i=0; i<numBreakpoints; i++)
    if (breakpoints[i] == bp) {
      printf("Breakpoint already set\n");
      return;
      }
  breakpoints[numBreakpoints++] = bp;
  }

void debug_rembp(EDSAC_CPU* cpu,char* buffer) {
  int i;
  int j;
  word bp;
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

void debug_trap(EDSAC_CPU* cpu,char* buffer) {
  int cmd;
  while (buffer[0] == ' ') buffer++;
  cmd = translateInput(buffer[0]);
  traps |= (1 << cmd);
  }

void debug_untrap(EDSAC_CPU* cpu,char* buffer) {
  int cmd;
  while (buffer[0] == ' ') buffer++;
  cmd = translateInput(buffer[0]);
  traps &= ~(1 << cmd);
  }

void debug_showtraps(EDSAC_CPU* cpu) {
  int i;
  int cmd;
  char tmpShiftMode;
  unsigned long mask;
  mask = 0x80000000;
  cmd = 31;
  tmpShiftMode = shiftMode;
  shiftMode = 0;
  while (mask != 0) {
    if (traps & mask) printf("%c",translateOutput(cmd)); else printf("-");
    cmd--;
    mask >>= 1;
    }
  printf("\n");
  shiftMode = tmpShiftMode;
  }

void debug_tape(EDSAC_CPU* cpu,char* buffer) {
  if (tape != NULL) {
    fclose(tape);
    tape = NULL;
    }
  if (strlen(buffer) > 0) {
    tape = fopen(buffer,"r");
    if (tape == NULL) {
      printf("Could not open tape file: %s\n",buffer);
      }
    }
  }

char debug_run(EDSAC_CPU* cpu,char* buffer) {
  word addr;
  if (strlen(buffer) == 0) {
    if (numBreakpoints == 0 && traps == 0) {
      debugMode = 'N';
      return 'N';
      }
    while (atBreakpoint(cpu) != 'Y' && stopCommand != 'Y') debug_step(cpu);
    } else {
    addr = atoi(buffer);
    while (cpu->scr != addr && stopCommand != 'Y') debug_step(cpu);
    }
  return 'Y';
  }

void debug(EDSAC_CPU* cpu) {
  char buffer[1024];
  char flag;
  flag = 'Y';
  while (flag == 'Y') {
    cpu->order = fetch(cpu,cpu->scr);
    disassem(cpu,cpu->scr,cpu->order);
    printf(">");
    fgets(buffer,1023,stdin);
    while (buffer[0] != 0 && buffer[strlen(buffer)-1] < ' ')
      buffer[strlen(buffer)-1] = 0;
    if (strlen(buffer) == 0) debug_step(cpu);
    if (strcasecmp(buffer,"help") == 0) debug_help();
    if (strcasecmp(buffer,"orders 1") == 0) loadOrders1(cpu);
    if (strcasecmp(buffer,"orders 2") == 0) loadOrders2(cpu);
    if (strcasecmp(buffer,"reset") == 0) debug_reset(cpu);
    if (strcasecmp(buffer,"clear") == 0) debug_clear(cpu);
    if (strcasecmp(buffer,"step") == 0) debug_step(cpu);
    if (strncasecmp(buffer,"bp ",3) == 0) debug_bp(cpu,buffer+3);
    if (strncasecmp(buffer,"dis",3) == 0) debug_dis(cpu,buffer+3);
    if (strncasecmp(buffer,"dump",4) == 0) debug_dump(cpu,buffer+4);
    if (strncasecmp(buffer,"run",3) == 0) flag = debug_run(cpu,buffer+3);
    if (strncasecmp(buffer,"rembp ",6) == 0) debug_rembp(cpu,buffer+6);
    if (strncasecmp(buffer,"tank ",5) == 0) debug_tank(cpu,buffer+5);
    if (strncasecmp(buffer,"trap ",5) == 0) debug_trap(cpu,buffer+5);
    if (strncasecmp(buffer,"tape ",5) == 0) debug_tape(cpu,buffer+5);
    if (strncasecmp(buffer,"untrap ",7) == 0) debug_untrap(cpu,buffer+7);
    if (strcasecmp(buffer,"showbp") == 0) debug_showbp(cpu);
    if (strcasecmp(buffer,"showreg") == 0) debug_showreg(cpu);
    if (strcasecmp(buffer,"showtraps") == 0) debug_showtraps(cpu);
    if (strcasecmp(buffer,"trace on") == 0) trace = 'Y';
    if (strcasecmp(buffer,"trace off") == 0) trace = 'N';
    if (strcasecmp(buffer,"quit") == 0) {
      flag = 'N';
      stopSim = 'Y';
      }
    }
  }

