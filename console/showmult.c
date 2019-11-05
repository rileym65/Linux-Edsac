#include "header.h"

void showMult(EDSAC_CPU* cpu) {
  int i;
  uint32_t mask;
  mask = 0x8000;
  if (cpu->multiplier[0] & 0x10000) printf("* "); else printf(". ");
  for (i=0; i<16; i++) {
    if (cpu->multiplier[0] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  printf(" ");
  mask = 0x20000;
  for (i=0; i<18; i++) {
    if (cpu->multiplier[1] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  printf("\n");
  }
