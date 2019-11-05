#include "header.h"
#include "terminal.h"

void showMemory(EDSAC_CPU* cpu, int address) {
  uint32_t mask;
  uint32_t value;
  int line;
  if (address < currentTank * 32) return;
  if (address >= (currentTank+1) * 32) return;
  value = cpu->mem[address];
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
