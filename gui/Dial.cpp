#include "header.h"
#include "Dial.h"

static Double angles[10][2] = {
  {   0.500, -0.866 },                 // 0   150deg
  {   0.866,  0.500 },                 // 1    60deg
  {   0.500,  0.866 },                 // 2    30deg
  {   0.000,  1.000 },                 // 3     0deg
  {  -0.500,  0.866 },                 // 4   330deg
  {  -0.866,  0.500 },                 // 5   300deg
  {  -1.000,  0.000 },                 // 6   270deg
  {  -0.866, -0.500 },                 // 7   240deg
  {  -0.500, -0.866 },                 // 8   210deg
  {   0.000, -1.000 },                 // 9   180deg
  };

Dial::Dial(Control* parent, int x, int y, int w, int h) : Control(parent, x, y, w, h) {
  dialHandler = NULL;
  }

Dial::~Dial() {
  }


void Dial::Redraw() {
  UInt32    i;
  Graphics *gc;
  Double    dist;
  Double    x,y;
  char      buffer[8];
  x = width / 2.0;
  y = height / 2.0;
  dist = (width / 2.0) * 0.75;
  rad = (dist * 0.45) / 2.0;
  gc = GetGraphics();
  gc->ForegroundColor(foregroundColor);
  gc->FillEllipse(0,0,width, height);
  gc->ForegroundColor(Color::White());
  for (i=0; i<10; i++) {
    points[i][0] = x+dist*angles[i][0];
    points[i][1] = y-dist*angles[i][1];
    gc->FillEllipse(points[i][0]-rad,points[i][1]-rad,rad*2,rad*2);
    }
  gc->ForegroundColor(Color::Black());
  for (i=0; i<10; i++) {
    sprintf(buffer,"%d",i);
    gc->DrawText(points[i][0]-3, points[i][1]+5, buffer);
    }
  delete(gc);
  }

void Dial::OnDial(EventHandler* handler) {
  dialHandler = handler;
  }

void Dial::MouseDownEvent(int x, int y, int button) {
  UInt32 i;
  Int32 hole;
  UInt32 dist;
  hole = -1;
  for (i=0; i<10; i++) {
    dist = (x-points[i][0]) * (x-points[i][0]);
    dist += (y-points[i][1]) * (y-points[i][1]);
    if (dist < rad*rad) hole = i;
    }
  if (hole >= 0 && this->dialHandler != NULL) {
    dialHandler->Call(this, ValueEventArgs(hole));
    }
  }

