#include "header.h"
#include "Vdu.h"

Vdu::Vdu(Control* parent, int x, int y, int w, int h) : Control(parent, x, y, w, h) {
  UInt32 i;
  tank = 0;
  for (i=0; i<32; i++) lines[i] = 0xac75;
  showGrid = false;
  }

Vdu::~Vdu() {
  }

void Vdu::cycleSingle(UInt32 hi, UInt32 lo, UInt32 y, Byte start) {
  UInt32    x;
  UInt32    mask;
  UInt32    ofs;
  Graphics *gc;
  gc = GetGraphics();
  gc->ForegroundColor(0x0000, 0xf000, 0x0000);
  gc->LineWidth(3);
  ofs = 30;
  mask = 0x20000;
  for (x=0; x<18; x++) {
    if ((hi & mask) != (lines[start] & mask)) {
      if (hi & mask) {
        gc->ForegroundColor(0x2000, 0x2000, 0x2000);
        gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
        gc->ForegroundColor(0x0000, 0xf000, 0x0000);
        gc->LineWidth(1);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
        gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
        gc->LineWidth(3);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
        }
      else {
        gc->ForegroundColor(0x2000, 0x2000, 0x2000);
        gc->LineWidth(1);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
        gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
        gc->LineWidth(3);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
        gc->ForegroundColor(0x0000, 0xf000, 0x0000);
        gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
        }
      }
    mask >>= 1;
    }
  lines[start] = hi;
  ofs += 72;
  mask = 0x20000;
  for (x=0; x<18; x++) {
    if ((lo & mask) != (lines[start+1] & mask)) {
      if (lo & mask) {
        gc->ForegroundColor(0x2000, 0x2000, 0x2000);
        gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
        gc->ForegroundColor(0x0000, 0xf000, 0x0000);
        gc->LineWidth(1);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
        gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
        gc->LineWidth(3);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
        }
      else {
        gc->ForegroundColor(0x2000, 0x2000, 0x2000);
        gc->LineWidth(1);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
        gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
        gc->LineWidth(3);
        gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
        gc->ForegroundColor(0x0000, 0xf000, 0x0000);
        gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
        }
      }
    mask >>= 1;
    }
  lines[start+1] = lo;
  delete(gc);
  }

void Vdu::cycleStore() {
  UInt32    i;
  UInt32    x,y;
  UInt32    ofs;
  UInt32   *memory;
  Graphics *gc;
  UInt32    tmp;
  UInt32    mask;
  memory = cpu->Memory();
  gc = GetGraphics();
  gc->ForegroundColor(0x0000, 0xa000, 0x0000);
  gc->LineWidth(1);
  for (i=0; i<32; i++) {
    tmp = memory[tank*32+i];
    if (tmp != lines[i]) {
      y = 55 + (15-(i/2))*6;
      ofs = (i & 1) ? 30 : 30+18*4;
      mask = 1 << 17;
      for (x=0; x<18; x++) {
        if ((tmp & mask) != (lines[i] & mask)) {
          if (tmp & mask) {
            gc->ForegroundColor(0x0000,0xf000, 0x0000);
            gc->DrawLine(ofs+x*4-1,y,ofs+x*4+2,y);
            gc->DrawLine(ofs+x*4,y-1,ofs+x*4,y+2);
            }
          else {
            gc->ForegroundColor(0x2000,0x2000, 0x2000);
            gc->DrawLine(ofs+x*4-1,y,ofs+x*4+2,y);
            gc->DrawLine(ofs+x*4,y-1,ofs+x*4,y+2);
            gc->ForegroundColor(0x0000,0xa000, 0x0000);
            gc->DrawPoint(ofs+x*4,y);
            }
          }
        mask >>= 1;
        }
      lines[i] = tmp;
      }
    }
  delete(gc);
  }

void Vdu::redrawSingle(UInt32 hi, UInt32 lo, UInt32 y, Byte start) {
  UInt32    x;
  UInt32    mask;
  UInt32    ofs;
  Graphics *gc;
  gc = GetGraphics();
  gc->ForegroundColor(0x0000, 0xf000, 0x0000);
  gc->LineWidth(3);
  ofs = 30;
  mask = 0x20000;
  for (x=0; x<18; x++) {
    if (hi & mask) {
      gc->LineWidth(1);
      gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
      gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
      gc->LineWidth(3);
      gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
      }
    else {
      gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
      }
    mask >>= 1;
    }
  lines[start] = hi;
  ofs += 72;
  mask = 0x20000;
  for (x=0; x<18; x++) {
    if (lo & mask) {
      gc->LineWidth(1);
      gc->DrawLine(ofs+x*4,y-15,ofs+x*4,y+2);
      gc->DrawLine(ofs+x*4+3,y-14,ofs+x*4+3,y+2);
      gc->LineWidth(3);
      gc->DrawLine(ofs+x*4,y-15,ofs+x*4+3,y-15);
      }
    else {
      gc->DrawLine(ofs+x*4,y,ofs+x*4+4,y);
      }
    mask >>= 1;
    }
  lines[start+1] = lo;
  delete(gc);
  }

void Vdu::redrawStore() {
  UInt32    i;
  UInt32    x,y;
  UInt32    ofs;
  UInt32   *memory;
  Graphics *gc;
  UInt32    tmp;
  UInt32    mask;
  memory = cpu->Memory();
  gc = GetGraphics();
  gc->ForegroundColor(0x0000, 0xa000, 0x0000);
  gc->LineWidth(1);
  for (i=0; i<32; i++) {
    tmp = memory[tank*32+i];
    lines[i] = tmp;
    y = 55 + (15-(i/2))*6;
    ofs = (i & 1) ? 30 : 30+18*4;
    mask = 1 << 17;
    for (x=0; x<18; x++) {
      if (tmp & mask) {
        gc->ForegroundColor(0x0000,0xf000, 0x0000);
        gc->DrawLine(ofs+x*4-1,y,ofs+x*4+2,y);
        gc->DrawLine(ofs+x*4,y-1,ofs+x*4,y+2);
        }
      else {
        gc->ForegroundColor(0x0000,0xa000, 0x0000);
        gc->DrawPoint(ofs+x*4,y);
        }
      mask >>= 1;
      }
    }
  delete(gc);
  }

void Vdu::Mode(Byte m) {
  if (m < 6) mode = m;
  }

void Vdu::Redraw() {
  UInt32 i;
  UInt32 y;
  Graphics *gc;
  UInt32   *data;
  gc = GetGraphics();
  gc->ForegroundColor(Color::Black());
  gc->FillEllipse(0,0,width, height);
  gc->ForegroundColor(0x2000, 0x2000, 0x2000);
  gc->FillEllipse(10,10,width-20,height-20);
  gc->ForegroundColor(0xa000, 0xa000, 0xa000);
  gc->FillEllipse(12,12,12,12);
  gc->FillEllipse(width-12,12,12,12);
  gc->FillEllipse(12,height-12,12,12);
  gc->FillEllipse(width-12,height-12,12,12);
  switch (mode) {
    case Accumulator:
         data = cpu->Acc();
         redrawSingle(data[0],data[1], 85, 0);
         redrawSingle(data[2],data[3], 115, 2);
         break;
    case Counter:
         data = cpu->Cycles();
         redrawSingle(data[1], data[0], 100, 0);
         break;
    case    Scr: redrawSingle(cpu->Scr(), 0, 100, 0); break;
    case Memory: redrawStore(); break;
    case  Order: redrawSingle(cpu->Order(), 0, 100, 0); break;
    case Multiplier:
         data = cpu->Multiplier();
         redrawSingle(data[0],data[1], 85, 0);
         data = cpu->Multiplicand();
         redrawSingle(data[0],data[1], 115, 2);
         break;
    }
  if (showGrid) {
    gc->ForegroundColor(0x9000, 0x9000, 0x9000);
    gc->LineWidth(1);
    switch (mode) {
      case Memory:
           gc->DrawLine(100,30,100,50);
           gc->DrawLine(100,150,100,170);
           gc->DrawLine(13,100,28,100);
           gc->DrawLine(172,100,187,100);
           break;
      case Accumulator:
           for (i=0; i<36; i++) {
             if (i == 0 || i == 1 || i == 13 || i == 9 || i == 5 ||
                 i == 31 || i == 27 || i == 23 || i == 19)
               y = 46;
             else y = 54;
             if (i == 17) y = 40;
             gc->DrawLine(34+i*4,y,34+i*4,65);
             }
           for (i=0; i<36; i++) {
             if (i == 1 || i == 13 || i == 9 || i == 5 ||
                 i == 31 || i == 27 || i == 23 || i == 19)
               y = 119;
             else y = 111;
             if (i == 17) y = 125;
             gc->DrawLine(34+i*4,15+104,34+i*4,15+y);
             }
           gc->DrawLine(30,119,30,126);
           break;
      case Multiplier:
           for (i=0; i<36; i++) {
             if (i == 0 || i == 1 || i == 13 || i == 9 || i == 5 ||
                 i == 31 || i == 27 || i == 23 || i == 19)
               y = 46;
             else y = 54;
             if (i == 17) y = 40;
             gc->DrawLine(34+i*4,y,34+i*4,65);
             }
           for (i=0; i<36; i++) {
             if (i == 0 || i == 1 || i == 13 || i == 9 || i == 5 ||
                 i == 31 || i == 27 || i == 23 || i == 19)
               y = 119;
             else y = 111;
             if (i == 17) y = 125;
             gc->DrawLine(34+i*4,15+104,34+i*4,15+y);
             }
           break;
      case Counter:
           for (i=0; i<36; i++) {
             if (i == 0 || i == 4 || i == 7 || i == 11 || i == 15 ||
                 i == 31 || i == 27 || i == 23 || i == 19)
               y = 119;
             else y = 111;
             gc->DrawLine(34+i*4,104,34+i*4,y);
             }
           break;
      case Order:
           gc->DrawLine(102, 104, 102, 119);
           gc->DrawLine( 98, 104,  98, 119);
           gc->DrawLine( 94, 104,  94, 111);
           gc->DrawLine( 90, 104,  90, 111);
           gc->DrawLine( 86, 104,  86, 111);
           gc->DrawLine( 82, 104,  82, 111);
           gc->DrawLine( 78, 104,  78, 111);
           gc->DrawLine( 74, 104,  74, 111);
           gc->DrawLine( 70, 104,  70, 111);
           gc->DrawLine( 66, 104,  66, 111);
           gc->DrawLine( 62, 104,  62, 111);
           gc->DrawLine( 58, 104,  58, 119);
           gc->DrawLine( 54, 104,  54, 119);
           gc->DrawLine( 50, 104,  50, 111);
           gc->DrawLine( 46, 104,  46, 111);
           gc->DrawLine( 42, 104,  42, 111);
           gc->DrawLine( 38, 104,  38, 111);
           gc->DrawLine( 34, 104,  34, 119);
           break;
      case Scr:
           gc->DrawLine(102, 104, 102, 119);
           gc->DrawLine( 98, 104,  98, 111);
           gc->DrawLine( 94, 104,  94, 111);
           gc->DrawLine( 90, 104,  90, 111);
           gc->DrawLine( 86, 104,  86, 119);
           gc->DrawLine( 82, 104,  82, 111);
           gc->DrawLine( 78, 104,  78, 111);
           gc->DrawLine( 74, 104,  74, 111);
           gc->DrawLine( 70, 104,  70, 119);
           gc->DrawLine( 66, 104,  66, 111);
           gc->DrawLine( 62, 104,  62, 119);
           break;
      }
    }
  delete(gc);
  }

void Vdu::Tank(Byte t) {
  tank = t;
  Redraw();
  }

void Vdu::Cycle() {
  UInt32 *data;
  switch (mode) {
    case Accumulator:
         data = cpu->Acc();
         cycleSingle(data[0],data[1], 85, 0);
         cycleSingle(data[2],data[3], 115, 2);
         break;
    case Counter:
         data = cpu->Cycles();
         cycleSingle(data[1], data[0], 100, 0);
         break;
    case    Scr: cycleSingle(cpu->Scr(), 0, 100, 0); break;
    case Memory: cycleStore(); break;
    case  Order: cycleSingle(cpu->Order(), 0, 100, 0); break;
    case Multiplier:
         data = cpu->Multiplier();
         cycleSingle(data[0],data[1], 85, 0);
         data = cpu->Multiplicand();
         cycleSingle(data[0],data[1], 115, 2);
         break;
    }
  }

void Vdu::ShowGrid(Boolean b) {
  showGrid = b;
  }

