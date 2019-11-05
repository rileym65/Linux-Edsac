#include "header.h"

void showTank(EDSAC_CPU* cpu,int tank) {
  int mem;
  int i;
  char side;
  uint32_t mask;
  uint32_t value;
  mem = tank * 32;
  side = 0;
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
      printf("\n");
      side = 0;
      }
    }
  }
