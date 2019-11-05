#include "header.h"

void disassem(EDSAC_CPU* cpu,uint32_t scr,uint32_t order) {
  printf("[%3d] ",scr);
  switch ((order >> 12) & 0x1ff) {
    case  0: printf("P"); break;
    case  1: printf("Q"); break;
    case  2: printf("W"); break;
    case  3: printf("E"); break;
    case  4: printf("R"); break;
    case  5: printf("T"); break;
    case  6: printf("Y"); break;
    case  7: printf("U"); break;
    case  8: printf("I"); break;
    case  9: printf("O"); break;
    case 10: printf("J"); break;
    case 11: printf("#"); break;
    case 12: printf("S"); break;
    case 13: printf("Z"); break;
    case 14: printf("K"); break;
    case 15: printf("*"); break;
    case 16: printf("."); break;
    case 17: printf("F"); break;
    case 18: printf("@"); break;
    case 19: printf("D"); break;
    case 20: printf("!"); break;
    case 21: printf("H"); break;
    case 22: printf("N"); break;
    case 23: printf("M"); break;
    case 24: printf("&"); break;
    case 25: printf("L"); break;
    case 26: printf("X"); break;
    case 27: printf("G"); break;
    case 28: printf("A"); break;
    case 29: printf("B"); break;
    case 30: printf("C"); break;
    case 31: printf("V"); break;
    default: printf("-");
    }
  if (((order >> 1) & 0x7ff) > 0) printf("%5d",(order >> 1) & 0x7ff);
    else printf("     ");
  if (initialOrders == 1) { if (order & 1) printf(" L"); else printf(" S"); }
  if (initialOrders == 2) { if (order & 1) printf(" D"); else printf(" F"); }
  printf("     ");
  }
