#ifndef _ROTARYKNOB_H
#define _ROTARYKNOB_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

class RotaryKnob : public Control {
  protected:
    Int32 value;
    EventHandler* turnHandler;
  public:
    RotaryKnob(Control* parent, int x, int y, int w, int h);
    ~RotaryKnob();
    virtual void Redraw();
    virtual void OnTurn(EventHandler* handler);
    virtual void MouseDownEvent(int x, int y, int button);
  };

#endif

