#include "header.h"
#include "RotaryKnob.h"
#include <math.h>

RotaryKnob::RotaryKnob(Control* parent, int x, int y, int w, int h) : Control(parent, x, y, w, h) {
  turnHandler = NULL;
  value = 0;
  }

RotaryKnob::~RotaryKnob() {
  }


void RotaryKnob::Redraw() {
  UInt32    i;
  Graphics *gc;
  Double    x,y;
  Double    x1,y1;
  Double    x2,y2;
  Double    dist;
  Double    dist2;
  Double    angle;
  x = width / 2.0;
  y = height / 2.0;
  dist = x * 0.80;
  gc = GetGraphics();
  gc->ForegroundColor(0x2000, 0x2000, 0x2000);
  gc->FillEllipse(x-dist,y-dist,dist*2, dist*2);
  gc->ForegroundColor(Color::White());
  angle = 0;
  dist = x * 0.90;
  for (i=0; i<32; i++) {
    x1 = sin(angle * Math::PI / 180) * dist;
    y1 = cos(angle * Math::PI / 180) * dist;
    gc->DrawPoint(x+x1,y-y1);
    angle += 11.25;
    }
  angle = 0;
  dist = x * 0.80;
  dist2 = x;
  for (i=0; i<8; i++) {
    x1 = sin(angle * Math::PI / 180) * dist;
    y1 = cos(angle * Math::PI / 180) * dist;
    x2 = sin(angle * Math::PI / 180) * dist2;
    y2 = cos(angle * Math::PI / 180) * dist2;
    gc->DrawLine(x+x1,y-y1,x+x2,y-y2);
    angle += 45.0;
    }
  angle = 11.25 * value;
  dist = x * 0.55;
  dist2 = x * 0.75;
  x1 = sin(angle * Math::PI / 180) * dist;
  y1 = cos(angle * Math::PI / 180) * dist;
  x2 = sin(angle * Math::PI / 180) * dist2;
  y2 = cos(angle * Math::PI / 180) * dist2;
  gc->DrawLine(x+x1,y-y1,x+x2,y-y2);
  dist = x * 0.54;
  gc = GetGraphics();
  gc->ForegroundColor(Color::Black());
  gc->FillEllipse(x-dist,y-dist,dist*2, dist*2);
  delete(gc);
  }

void RotaryKnob::OnTurn(EventHandler* handler) {
  turnHandler = handler;
  }

void RotaryKnob::MouseDownEvent(int x, int y, int button) {
  if (x > (width / 2)) value++;
    else value--;
  if (value < 0) value = 31;
  if (value > 31) value = 0;
  Redraw();
  if (this->turnHandler != NULL) {
    turnHandler->Call(this, ValueEventArgs(value));
    }
  }

