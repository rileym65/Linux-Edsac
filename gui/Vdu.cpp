#include "Vdu.h"

Vdu::Vdu(Control* parent, int x, int y, int w, int h) : Control(parent, x, y, w, h) {
  }

Vdu::~Vdu() {
  }

void Vdu::Redraw() {
  Graphics *gc;
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
  delete(gc);
  }

