#ifndef _DIAL_H
#define _DIAL_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

class Dial : public Control {
  protected:
    Double rad;
    UInt32 points[10][2];
    EventHandler* dialHandler;
  public:
    Dial(Control* parent, int x, int y, int w, int h);
    ~Dial();
    virtual void Redraw();
    virtual void OnDial(EventHandler* handler);
    virtual void MouseDownEvent(int x, int y, int button);
  };

#endif

