#include "header.h"
#include "TelePrinter.h"

TelePrinter::TelePrinter(Control* parent, int x, int y, int w, int h) : Control(parent, x, y, w, h) {
  Int32 i;
  Font("Courier-10");
  printerLine = 0;
  printerPos = 0;
  for (i=0; i<20; i++)
    strcpy(printer[i],"                                        ");
  lineChanged = false;
  posChanged = false;
  }

TelePrinter::~TelePrinter() {
  }


void TelePrinter::Redraw() {
  UInt32 i;
  Graphics *gc;
  gc = GetGraphics();
  if (lineChanged) {
    lineChanged = false;
    }
  gc->Clear();
  for (i=0; i<20; i++)
    gc->DrawText(20,20+i*20,printer[i]);
  delete(gc);
  }

void TelePrinter::Print(Byte out) {
  UInt32 i;
  locked = true;
  if (out == 10) {
    printerPos = 0;
    }
  else if (out == 13) {
    printerLine++;
    if (printerLine == 20) {
      for (i=0; i<19; i++) strcpy(printer[i],printer[i+1]);
      strcpy(printer[19],"                                        ");
      printerLine = 19;
      }
    lineChanged = true;
    }
  else {
    if (printerPos < 40) {
      printer[printerLine][printerPos+1] = 0;
      printer[printerLine][printerPos++] = out;
      posChanged = true;
      }
    }
  locked = false;
  }

void TelePrinter::Cycle() {
  if (locked) return;
  if (lineChanged || posChanged) {
    posChanged = false;
    Redraw();
    }
  }

void TelePrinter::Print(const char* message) {
  while (*message != 0) {
    Print(*message);
    message++;
    }
  }

