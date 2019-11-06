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
    Byte    translate(Byte in);
  public:
    Printer();
    ~Printer();
    void Print(Byte out);
  };

#endif
