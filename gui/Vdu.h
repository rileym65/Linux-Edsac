#ifndef _VDU_H
#define _VDU_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

class Vdu : public Control {
  protected:
    UInt32 lines[32];
    Byte   mode;
    Byte   tank;
    void   cycleSingle(UInt32 hi, UInt32 lo,UInt32 y, Byte start);
    void   cycleStore();
    void   redrawSingle(UInt32 hi, UInt32 lo,UInt32 y, Byte start);
    void   redrawStore();
  public:
    static const Byte Memory = 0;
    static const Byte Counter = 1;
    static const Byte Scr = 2;
    static const Byte Order = 3;
    static const Byte Accumulator = 4;
    static const Byte Multiplier = 5;
    Vdu(Control* parent, int x, int y, int w, int h);
    ~Vdu();
    virtual void Cycle();
    virtual void Mode(Byte m);
    virtual void Redraw();
    virtual void Tank(Byte t);
  };

#endif

