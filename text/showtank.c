#include "header.h"
#include "terminal.h"

void showTank(EDSAC_CPU* cpu,int tank) {
  int mem;
  int i;
  int line;
  char side;
  uint32_t mask;
  uint32_t value;
  mem = tank * 32;
  side = 0;
  line = 1;
  GotoXY(1, line);
  for (i=31; i>=0 ;i--) {
    value = cpu->mem[mem+i];
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
