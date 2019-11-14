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
  timer->Start();
  }

