#ifndef _VDU_H
#define _VDU_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>

using namespace SmrFramework;

class Vdu : public Control {
  protected:
  public:
    Vdu(Control* parent, int x, int y, int w, int h);
    ~Vdu();
    virtual void Redraw();
  };

#endif

