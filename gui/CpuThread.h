#ifndef _CPUTHREAD_H
#define _CPUTHREAD_H

#include <SmrFramework.h>

using namespace SmrFramework;

#include "Cpu.h"

class CpuThread : public Thread {
  protected:
    Boolean step;
    UInt32  speed;
    Cpu    *cpu;
    virtual void execute(void* arg);
  public:
    CpuThread(Cpu* c);
    ~CpuThread();
    void Speed(UInt32 i);
    void Step();
  };

#endif

