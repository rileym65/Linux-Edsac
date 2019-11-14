#ifndef _CPU_H
#define _CPU_H

#include <SmrFramework.h>

using namespace SmrFramework;

#include "Printer.h"
#include "Reader.h"

#define CH_ACC       1
#define CH_IER       2
#define CH_ICAND     4
#define CH_MEM_1     8
#define CH_MEM_2    16

class Cpu {
  protected:
    UInt32 address1;
    UInt32 address2;
    UInt32 order;
    UInt32 scr;
    UInt32 mem[1024];
    UInt32 multiplier[2];
    UInt32 multiplicand[2];
    UInt32 acc[4];
    UInt32 changes;
    Int32  breg;
    Byte   lastOutput;
    Int32  initialOrders;
    UInt32   cycles[2];
    Printer* printer;
    Reader*  reader;
    Boolean  stopCommand;
    Boolean  only1949;
    Boolean  overflow;
    char     trace;
    void   doAnd();
    void   doMul(char mode);
    UInt32 fetchB(UInt32 address, Boolean indexed);
    void   storeB(UInt32 address, Boolean indexed, UInt32 value);
    Byte   getShiftCount(UInt32 a);
    void   lMul(UInt32 hi,UInt32 lo,char mode);
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
    UInt32   Address1();
    UInt32   Address2();
    UInt32   Changes();
    UInt32  *Cycles();
    String  *Disassem(UInt32 address, UInt32 order);
    UInt32   Fetch(UInt32 addr);
    Printer *GetPrinter();
    Reader  *GetReader();
    Int32    InitialOrders();
    Int32    InitialOrders(Int32 i);
    void     LoadOrders1();
    void     LoadOrders2();
    UInt32  *Memory();
    UInt32  *Multiplicand();
    UInt32  *Multiplier();
    Boolean  Only1949();
    Boolean  Only1949(Boolean b);
    UInt32   Order();
    void     Reset();
    UInt32   Scr();
    UInt32   Scr(UInt32 i);
    void     Start();
    void     Step();
    Boolean  StopCommand();
    Boolean  StopCommand(Boolean b);
    char     Trace();
    char     Trace(char c);
  };

#endif

