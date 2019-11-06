#ifndef _DEBUG_H
#define _DEBUG_H

#include "Cpu.h"

class Debug {
  protected:
    char   debugMode;
    UInt32 breakpoints[1024];
    Cpu*   cpu;
    UInt32 numBreakpoints;
    UInt64 traps;
    Boolean atBreakpoint();
    void    bp(char* buffer);
    void    clear();
    void    disassemble(char* buffer);
    void    dump(char* buffer);
    void    help();
    void    rembp(char* buffer);
    void    reset();
    Boolean run(char* buffer);
    void    showbp();
    void    showreg();
    void    showtraps();
    void    showWord(UInt32 wrd);
    void    step();
    void    tank(char* buffer);
    void    tape(char* buffer);
    void    trap(char* buffer);
    Boolean trapSet();
    void    untrap(char* buffer);
  public:
    Debug(Cpu* c);
    ~Debug();
    void Debugger();
    char    DebugMode();
    char    DebugMode(char c);
    void    showAcc();
    void    showMult();
    void    showMultiplicand();
    void    showTank(UInt32 tank);
  };

#endif

