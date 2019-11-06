#ifndef _PRINTER_H
#define _PRINTER_H

#include <SmrFramework.h>

using namespace SmrFramework;

class Printer {
  protected:
    char    printer[16][80];
    Int32   printerLine;
    Int32   printerPos;
    Boolean shiftMode;
  public:
    Printer();
    ~Printer();
    void Print(Byte out);
    Boolean ShiftMode();
    Boolean ShiftMode(Boolean b);
    Byte    Translate(Byte in);
  };

#endif
