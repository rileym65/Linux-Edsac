#ifndef _CPU_H
#define _CPU_H

#include <SmrFramework.h>

using namespace SmrFramework;

#include "Printer.h"
#include "Reader.h"

class Cpu {
  protected:
    UInt32 order;
    UInt32 scr;
    UInt32 mem[1024];
    UInt32 multiplier[2];
    UInt32 multiplicand[2];
    UInt32 acc[4];
    Byte   lastOutput;
    Int32  initialOrders;
    Printer* printer;
    Reader*  reader;
    Boolean  stopCommand;
    char     trace;
    void   doAnd();
    void   doMul(char mode);
    Byte   getShiftCount(UInt32 a);
    void   lMul(UInt32 address,char mode);
    void   lShift(UInt32* number, UInt32 num);
    void   mbAdd(UInt32* value,Int32 words);
    void   mbSub(UInt32* value,Int32 words);
    Int32  prepForMul(UInt32* number);
    void   roundAcc();
    void   rShift(UInt32* number, UInt32 num);
    void   sMul(UInt32 a,char mode);
    void   twosComp(UInt32* number, UInt32 num);
  public:
    Cpu();
    ~Cpu();
    UInt32  *Acc();
    void     AttachPrinter(Printer* p);
    void     AttachReader(Reader* r);
    String  *Disassem(UInt32 address, UInt32 order);
    UInt32   Fetch(UInt32 addr);
    Printer *GetPrinter();
    Reader  *GetReader();
    void     InitialOrders(Int32 i);
    void     LoadOrders1();
    void     LoadOrders2();
    UInt32  *Memory();
    UInt32  *Multiplicand();
    UInt32  *Multiplier();
    UInt32   Order();
    void     Reset();
    UInt32   Scr();
    UInt32   Scr(UInt32 i);
    void     Step();
    Boolean  StopCommand();
    Boolean  StopCommand(Boolean b);
    char     Trace();
    char     Trace(char c);
  };

#endif

