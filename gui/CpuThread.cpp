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
    while (timer.Microseconds() < 1400) {
      usleep(100);
      }
    timer.Restart();
    if (step && cpu->StopCommand()) cpu->StopCommand(false);
    if (!cpu->StopCommand()) {
      cpu->Step();
      if (step) {
        step = false;
        cpu->StopCommand(true);
printf("scr:%d\n",cpu->Scr());
        }
      }
    }
  }

void CpuThread::Step() {
  step = true;
  }

