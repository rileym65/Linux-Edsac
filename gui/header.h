#ifndef _HEADER_H
#define _HEADER_H

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

#include "MainWindow.h"
#include "Printer.h"
#include "Reader.h"
#include "Cpu.h"
#include "CpuThread.h"

LINK Application *app;
LINK Cpu         *cpu;
LINK CpuThread   *cpuThread;
LINK int          initialOrders;
LINK Printer     *printer;
LINK Reader      *reader;
LINK MainWindow  *window;
LINK Image       *toggleOff;
LINK Image       *toggleOn;
LINK Image       *stopOff;
LINK Image       *stopOn;


#endif

