#ifndef _TELEPRINTER_H
#define _TELEPRINTER_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

class TelePrinter : public Control {
  protected:
    Int32   printerLine;
    Int32   printerPos;
    Boolean lineChanged;
    Boolean posChanged;
    Boolean locked;
    char  printer[20][80];
  public:
    TelePrinter(Control* parent, int x, int y, int w, int h);
    ~TelePrinter();
    virtual void Cycle();
    virtual void Redraw();
    virtual void Print(Byte out);
    virtual void Print(const char* message);
  };

#endif

