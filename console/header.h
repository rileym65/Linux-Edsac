#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <SmrFramework.h>

using namespace SmrFramework;

#include "Cpu.h"
#include "Reader.h"
#include "Printer.h"
#include "Debug.h"

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


LINK Cpu *cpu;
LINK Reader *reader;
LINK Printer *printer;
LINK Debug   *debugger;

LINK char    tapeRemark;
LINK int     initialOrders;
LINK long    cycles;
LINK char    stopSim;
LINK Boolean singleStep;


extern void StopMode();
