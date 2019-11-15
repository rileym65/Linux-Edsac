#include <unistd.h>
#include "CpuThread.h"

CpuThread::CpuThread(Cpu* c) {
  cpu = c;
  }

CpuThread::~CpuThread() {
  }

void CpuThread::execute(void* arg) {
  HrTimer timer;
  timer.Restart();
  while (!terminate) {
    if (cpu->StopCommand()) {
      while (timer.Microseconds() < 10000) usleep(1000);
      }
    else {
      while (timer.Microseconds() < 100) usleep(100);
      }
    timer.Restart();
    if (step && cpu->StopCommand()) cpu->StopCommand(false);
    if (!cpu->StopCommand()) {
      cpu->Step();
      if (step) {
        step = false;
        cpu->StopCommand(true);
        }
      }
    }
  }

void CpuThread::Step() {
  step = true;
  }

