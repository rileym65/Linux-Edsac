#include "header.h"
#include "terminal.h"

void showAcc(EDSAC_CPU* cpu) {
  int i,j;
  uint32_t mask;
  GotoXY(1, 20);
  printf("Accumulator : ");

  mask = 0x8000;
  if (cpu->acc[0] & 0x10000) printf("* "); else printf(". ");
  for (i=0; i<16; i++) {
    if (cpu->acc[0] & mask) printf("*"); else printf(".");
    mask >>= 1;
    }
  for (j=1; j<4; j++) {
    printf(" ");
    mask = 0x20000;
    for (i=0; i<18; i++) {
      if (cpu->acc[j] & mask) printf("*"); else printf(".");
      mask >>= 1;
      }
    if (j == 1) printf("\n             ");
    }
  fflush(stdout);
  }
