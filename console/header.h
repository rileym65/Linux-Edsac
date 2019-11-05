#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

typedef u_int32_t uint32_t;
typedef u_int16_t uint16_t;

#ifndef _BYTE
typedef unsigned char byte;
#endif

#ifndef _WORD
typedef uint16_t word;
#endif


typedef struct {
  uint32_t order;
  uint32_t order2;
  uint32_t scr;
  uint32_t mem[1024];
  uint32_t multiplier[2];
  uint32_t multiplicand[2];
  uint32_t acc[4];
  byte     lastOutput;
  } EDSAC_CPU;

LINK char stopCommand;
LINK char debugMode;
LINK char tapeRemark;
LINK int  initialOrders;
LINK word breakpoints[1024];
LINK int  numBreakpoints;
LINK long cycles;
LINK FILE* tape;
LINK long traps;
LINK char shiftMode;
LINK char trace;
LINK char stopSim;

/* cpu.c */
extern void loadOrders1(EDSAC_CPU* cpu);
extern void loadOrders2(EDSAC_CPU* cpu);
extern void reset(EDSAC_CPU* cpu);
extern void step(EDSAC_CPU* cpu);
extern uint32_t fetch(EDSAC_CPU* cpu,uint32_t addr);
extern void disassem(EDSAC_CPU* cpu,uint32_t scr,uint32_t order);

/* reader.c */
extern byte translateInput(byte in);
extern byte readTape();

/* printer.c */
extern byte translateOutput(byte in);
extern void print(byte out);

/* debug.c */
extern void debug(EDSAC_CPU* cpu);

/* stopmode.c */
extern void stopMode(EDSAC_CPU* cpu);


extern void showAcc(EDSAC_CPU* cpu);
extern void showMult(EDSAC_CPU* cpu);
extern void showMultiplicand(EDSAC_CPU* cpu);
extern void showTank(EDSAC_CPU* cpu,int tank);
