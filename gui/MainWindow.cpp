#include "header.h"
#include "MainWindow.h"

MainWindow::MainWindow(int w, int h) : Form(NULL, 0, 0, w, h) {
  InitializeComponent();
  }

MainWindow::~MainWindow() {
  }

void MainWindow::clearButtonPressed(void* sender, MouseEventArgs args) {
  UInt32 i;
  UInt32 *mem;
  mem = cpu->Memory();
  for (i=0; i<1024; i++) mem[i] = 0;
  }

void MainWindow::resetButtonPressed(void* sender, MouseEventArgs args) {
  cpu->StopCommand(false);
  }

void MainWindow::startButtonPressed(void* sender, MouseEventArgs args) {
  cpu->Start();
  }

void MainWindow::stepButtonPressed(void* sender, MouseEventArgs args) {
  cpuThread->Step();
  }

void MainWindow::stopButtonPressed(void* sender, MouseEventArgs args) {
  cpu->StopCommand(true);
  }

void MainWindow::TimerTick(void* sender) {
  if (stopped != cpu->StopCommand()) {
    stopped = cpu->StopCommand();
    if (stopped) stopLamp->BackgroundImage(stopOn);
      else stopLamp->BackgroundImage(stopOff);
    }
  vdu1->Cycle();
  vdu2->Cycle();
  vdu3->Cycle();
  vdu4->Cycle();
  vdu5->Cycle();
  vdu6->Cycle();
  timer->Start();
  }

void MainWindow::dialEvent(void* sender, ValueEventArgs args) {
  UInt32  number;
  number = args.Value();
  if (number == 0) number = 10;
  cpu->Acc()[0] = number << 1;
  cpu->StopCommand(false);
  }

void MainWindow::tankEvent(void* sender, ValueEventArgs args) {
  UInt32  number;
  number = args.Value();
  vdu2->Tank(number);
  }

