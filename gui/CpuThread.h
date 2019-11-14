#ifndef _CPUTHREAD_H
#define _CPUTHREAD_H

#include <SmrFramework.h>

using namespace SmrFramework;

#include "Cpu.h"

class CpuThread : public Thread {
  protected:
    Boolean step;
    Cpu    *cpu;
    virtual void execute(void* arg);
  public:
    CpuThread(Cpu* c);
    ~CpuThread();
    void Step();
  };

#endif

