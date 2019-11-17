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
  ptr->Cycle();
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

void MainWindow::ordersChanged(void* sender, ValueEventArgs args) {
  UInt32 number;
  number = args.Value();
printf("orders: %d\n",number);
  }

Int32 MainWindow::InitialOrders() {
  return initialOrders->SelectedIndex() + 1;
  }

Int32 MainWindow::InitialOrders(Int32 i) {
  if (i == 1) initialOrders->SelectedIndex(0);
  if (i == 2) initialOrders->SelectedIndex(1);
  return initialOrders->SelectedIndex() + 1;
  }

void MainWindow::tapeButtonPressed(void* sender, MouseEventArgs args) {
  OpenFileDialog *dialog;
  DialogResult    result;
  Int32           initialOrders;
  String         *filename;
  initialOrders = 0;
  dialog = new OpenFileDialog(NULL, 100, 100, 600, 500);
  result = dialog->ShowDialog();
  if (result.Result() == DialogResult::OK) {
    filename = dialog->FileName();
    if (filename != NULL) {
      if (filename->EndsWith(".1")) {
        initialOrders = 1;
        }
      if (filename->EndsWith(".2")) {
        initialOrders = 2;
        }
      if (initialOrders == 1) cpu->LoadOrders1();
      if (initialOrders == 2) cpu->LoadOrders2();
      reader->Mount(filename->AsCharArray());
      delete(filename);
      }
    }
  delete(dialog);
//  if (initialOrders != 0) InitialOrders(initialOrders);
  }

