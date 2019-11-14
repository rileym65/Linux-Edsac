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
    while (timer.Microseconds() < 200) {
      usleep(100);
      }
    timer.Restart();
    if (!cpu->StopCommand()) {
      cpu->Step();
      }
    }
  }

