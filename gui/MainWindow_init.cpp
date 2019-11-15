#include "header.h"
#include "MainWindow.h"

#define SW_W       35
#define SW_H       35
#define CLEAR_X   250
#define CLEAR_Y   650
#define START_X   325
#define START_Y   650
#define STOP_X    400
#define STOP_Y    650
#define RESET_X   475
#define RESET_Y   650
#define STEP_X    550
#define STEP_Y    650
#define STOPL_X   625
#define STOPL_Y   650
#define VDU1_X     25
#define VDU1_Y     25
#define VDU2_X    300
#define VDU2_Y     25
#define VDU3_X    575
#define VDU3_Y     25
#define VDU4_X     25
#define VDU4_Y    275
#define VDU5_X    300
#define VDU5_Y    275
#define VDU6_X    575
#define VDU6_Y    275
#define VDU_W     200
#define VDU_H     200
#define DIAL_X     25
#define DIAL_Y    500
#define DIAL_W    200
#define DIAL_H    200

void MainWindow::InitializeComponent() {
  Label *label;

  stopped = true;

  clearButton = new Button(this, CLEAR_X, CLEAR_Y, SW_W, SW_H);
  clearButton->Visible(true);
  clearButton->BorderWidth(0);
  clearButton->BackgroundImage(pushOff);
  clearButton->PressedImage(pushOn);
  clearButton->OnPress(new EventHandler(MainWindow::_clearButtonPressed, this));
  this->Add(clearButton);

  label = new Label(this, CLEAR_X-10, CLEAR_Y-30, SW_W+20, 25, "CLEAR");
  label->BackgroundColor(Color::White());
  label->ForegroundColor(Color::Black());
  this->Add(label);

  startButton = new Button(this, START_X, START_Y, SW_W, SW_H);
  startButton->Visible(true);
  startButton->BorderWidth(0);
  startButton->BackgroundImage(pushOff);
  startButton->PressedImage(pushOn);
  startButton->OnPress(new EventHandler(MainWindow::_startButtonPressed, this));
  this->Add(startButton);

  label = new Label(this, START_X-10, START_Y-30, SW_W+20, 25, "START");
  label->BackgroundColor(Color::White());
  label->ForegroundColor(Color::Black());
  this->Add(label);

  stopButton = new Button(this, STOP_X, STOP_Y, SW_W, SW_H);
  stopButton->Visible(true);
  stopButton->BorderWidth(0);
  stopButton->BackgroundImage(pushOff);
  stopButton->PressedImage(pushOn);
  stopButton->OnPress(new EventHandler(MainWindow::_stopButtonPressed, this));
  this->Add(stopButton);

  label = new Label(this, STOP_X-10, STOP_Y-30, SW_W+20, 25, "STOP");
  label->BackgroundColor(Color::White());
  label->ForegroundColor(Color::Black());
  this->Add(label);

  resetButton = new Button(this, RESET_X, RESET_Y, SW_W, SW_H);
  resetButton->Visible(true);
  resetButton->BorderWidth(0);
  resetButton->BackgroundImage(pushOff);
  resetButton->PressedImage(pushOn);
  resetButton->OnPress(new EventHandler(MainWindow::_resetButtonPressed, this));
  this->Add(resetButton);

  label = new Label(this, RESET_X-10, RESET_Y-30, SW_W+20, 25, "RESET");
  label->BackgroundColor(Color::White());
  label->ForegroundColor(Color::Black());
  this->Add(label);

  stepButton = new Button(this, STEP_X, STEP_Y, SW_W, SW_H);
  stepButton->Visible(true);
  stepButton->BorderWidth(0);
  stepButton->BackgroundImage(pushOff);
  stepButton->PressedImage(pushOn);
  stepButton->OnPress(new EventHandler(MainWindow::_stepButtonPressed, this));
  this->Add(stepButton);

  label = new Label(this, STEP_X-10, STEP_Y-30, SW_W+20, 25, "STEP");
  label->BackgroundColor(Color::White());
  label->ForegroundColor(Color::Black());
  this->Add(label);

  stopLamp = new Control(this, STOPL_X, STOPL_Y, 35, 35);
  stopLamp->Visible(true);
  stopLamp->BorderWidth(0);
  stopLamp->BackgroundImage(stopOn);
  this->Add(stopLamp);

  vdu1 = new Vdu(this, VDU1_X, VDU1_Y, VDU_W, VDU_H);
  vdu1->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu1->Mode(Vdu::Counter);
  vdu1->Visible(true);
  vdu1->BorderWidth(0);
  this->Add(vdu1);

  vdu2 = new Vdu(this, VDU2_X, VDU2_Y, VDU_W, VDU_H);
  vdu2->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu2->Mode(Vdu::Memory);
  vdu2->Visible(true);
  vdu2->BorderWidth(0);
  this->Add(vdu2);

  vdu3 = new Vdu(this, VDU3_X, VDU3_Y, VDU_W, VDU_H);
  vdu3->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu3->Mode(Vdu::Scr);
  vdu3->Visible(true);
  vdu3->BorderWidth(0);
  this->Add(vdu3);

  vdu4 = new Vdu(this, VDU4_X, VDU4_Y, VDU_W, VDU_H);
  vdu4->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu4->Mode(Vdu::Order);
  vdu4->Visible(true);
  vdu4->BorderWidth(0);
  this->Add(vdu4);

  vdu5 = new Vdu(this, VDU5_X, VDU5_Y, VDU_W, VDU_H);
  vdu5->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu5->Mode(Vdu::Accumulator);
  vdu5->Visible(true);
  vdu5->BorderWidth(0);
  this->Add(vdu5);

  vdu6 = new Vdu(this, VDU6_X, VDU6_Y, VDU_W, VDU_H);
  vdu6->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu6->Mode(Vdu::Multiplier);
  vdu6->Visible(true);
  vdu6->BorderWidth(0);
  this->Add(vdu6);

  label = new Label(this, VDU1_X, VDU1_Y-25, VDU_W, 25, "Counter");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  label = new Label(this, VDU2_X, VDU2_Y-25, VDU_W, 25, "Memory");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  label = new Label(this, VDU3_X, VDU3_Y-25, VDU_W, 25, "Sequence control");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  label = new Label(this, VDU4_X, VDU4_Y-25, VDU_W, 25, "Order");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  label = new Label(this, VDU5_X, VDU5_Y-25, VDU_W, 25, "Accumulator");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  label = new Label(this, VDU6_X, VDU6_Y-25, VDU_W, 25, "Multiplier/Mulitplicand");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  this->Add(label);

  dial = new Dial(this, DIAL_X, DIAL_Y, DIAL_W, DIAL_H);
  dial->BackgroundColor(0x8000, 0x8000, 0x8000);
  dial->ForegroundColor(0x1000, 0x1000, 0x1000);
  dial->OnDial(new EventHandler(MainWindow::_dialEvent, this));
  dial->Visible(true);
  dial->BorderWidth(0);
  this->Add(dial);

  timer = new Timer();
  timer->OnTick(new EventHandler(MainWindow::_TimerTick, this));
  timer->Interval(1);
  timer->StopOnTick(true);
  timer->Start();
  }

void MainWindow::_clearButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->clearButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_resetButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->resetButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_startButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->startButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_stepButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->stepButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_stopButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->stopButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_TimerTick(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->TimerTick(sender);
  }

void MainWindow::_dialEvent(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->dialEvent(sender, (ValueEventArgs&)args);
  }

