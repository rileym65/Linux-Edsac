#include "header.h"
#include "MainWindow.h"

#define SW_W       35
#define SW_H       35
#define CLEAR_X   270
#define CLEAR_Y   150
#define START_X   345
#define START_Y   150
#define STOP_X    420
#define STOP_Y    150
#define RESET_X   495
#define RESET_Y   150
#define STEP_X    570
#define STEP_Y    150
#define STOPL_X   700
#define STOPL_Y   150
#define VDU1_X     25
#define VDU1_Y     25
#define VDU2_X    300
#define VDU2_Y     25
#define VDU3_X    575
#define VDU3_Y     25
#define VDU4_X     25
#define VDU4_Y     25
#define VDU5_X    300
#define VDU5_Y     25
#define VDU6_X    575
#define VDU6_Y     25
#define VDU_W     200
#define VDU_H     200
#define DIAL_X     25
#define DIAL_Y     25
#define DIAL_W    200
#define DIAL_H    200
#define TANK_X    500
#define TANK_Y    150
#define TANK_W     50
#define TANK_H     50

void MainWindow::InitializeComponent() {
  Label *label;

  stopped = true;

  controlPanel = new Panel(this, 0, 480, 834, height-480);
  controlPanel->BackgroundColor(0xb000, 0xb000, 0xb000);
  controlPanel->Visible(true);
  controlPanel->BorderWidth(0);
  controlPanel->BorderColor(0x6000, 0x6000, 0x6000);
  this->Add(controlPanel);

  clearButton = new Button(controlPanel, CLEAR_X, CLEAR_Y, SW_W, SW_H);
  clearButton->Visible(true);
  clearButton->BorderWidth(0);
  clearButton->BackgroundImage(pushOff);
  clearButton->PressedImage(pushOn);
  clearButton->OnPress(new EventHandler(MainWindow::_clearButtonPressed, controlPanel));
  controlPanel->Add(clearButton);

  label = new Label(controlPanel, CLEAR_X-10, CLEAR_Y-30, SW_W+20, 25, "CLEAR");
  label->BackgroundColor(0xb000, 0xb000, 0xb000);
  label->ForegroundColor(Color::Black());
  controlPanel->Add(label);

  startButton = new Button(controlPanel, START_X, START_Y, SW_W, SW_H);
  startButton->Visible(true);
  startButton->BorderWidth(0);
  startButton->BackgroundImage(pushOff);
  startButton->PressedImage(pushOn);
  startButton->OnPress(new EventHandler(MainWindow::_startButtonPressed, controlPanel));
  controlPanel->Add(startButton);

  label = new Label(controlPanel, START_X-10, START_Y-30, SW_W+20, 25, "START");
  label->BackgroundColor(0xb000, 0xb000, 0xb000);
  label->ForegroundColor(Color::Black());
  controlPanel->Add(label);

  stopButton = new Button(controlPanel, STOP_X, STOP_Y, SW_W, SW_H);
  stopButton->Visible(true);
  stopButton->BorderWidth(0);
  stopButton->BackgroundImage(pushOff);
  stopButton->PressedImage(pushOn);
  stopButton->OnPress(new EventHandler(MainWindow::_stopButtonPressed, controlPanel));
  controlPanel->Add(stopButton);

  label = new Label(controlPanel, STOP_X-10, STOP_Y-30, SW_W+20, 25, "STOP");
  label->BackgroundColor(0xb000, 0xb000, 0xb000);
  label->ForegroundColor(Color::Black());
  controlPanel->Add(label);

  resetButton = new Button(controlPanel, RESET_X, RESET_Y, SW_W, SW_H);
  resetButton->Visible(true);
  resetButton->BorderWidth(0);
  resetButton->BackgroundImage(pushOff);
  resetButton->PressedImage(pushOn);
  resetButton->OnPress(new EventHandler(MainWindow::_resetButtonPressed, controlPanel));
  controlPanel->Add(resetButton);

  label = new Label(controlPanel, RESET_X-10, RESET_Y-30, SW_W+20, 25, "RESET");
  label->BackgroundColor(0xb000, 0xb000, 0xb000);
  label->ForegroundColor(Color::Black());
  controlPanel->Add(label);

  stepButton = new Button(controlPanel, STEP_X, STEP_Y, SW_W, SW_H);
  stepButton->Visible(true);
  stepButton->BorderWidth(0);
  stepButton->BackgroundImage(pushOff);
  stepButton->PressedImage(pushOn);
  stepButton->OnPress(new EventHandler(MainWindow::_stepButtonPressed, controlPanel));
  controlPanel->Add(stepButton);

  label = new Label(controlPanel, STEP_X-10, STEP_Y-30, SW_W+20, 25, "STEP");
  label->BackgroundColor(0xb000, 0xb000, 0xb000);
  label->ForegroundColor(Color::Black());
  controlPanel->Add(label);

  stopLamp = new Control(controlPanel, STOPL_X, STOPL_Y, 35, 35);
  stopLamp->Visible(true);
  stopLamp->BorderWidth(0);
  stopLamp->BackgroundImage(stopOn);
  controlPanel->Add(stopLamp);

  vduPanel1 = new Panel(this, 0, 0, 825, 240);
  vduPanel1->BackgroundColor(0x8000, 0x8000, 0x8000);
  vduPanel1->Visible(true);
  vduPanel1->BorderWidth(5);
  vduPanel1->BorderColor(0x6000, 0x6000, 0x6000);
  this->Add(vduPanel1);

  vduPanel2 = new Panel(this, 0, 240, 825, 240);
  vduPanel2->BackgroundColor(0x8000, 0x8000, 0x8000);
  vduPanel2->Visible(true);
  vduPanel2->BorderWidth(5);
  vduPanel2->BorderColor(0x6000, 0x6000, 0x6000);
  this->Add(vduPanel2);

  vdu1 = new Vdu(vduPanel1, VDU1_X, VDU1_Y, VDU_W, VDU_H);
  vdu1->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu1->Mode(Vdu::Counter);
  vdu1->Visible(true);
  vdu1->BorderWidth(0);
  vdu1->ShowGrid(showGridLines);
  vduPanel1->Add(vdu1);

  vdu2 = new Vdu(vduPanel1, VDU2_X, VDU2_Y, VDU_W, VDU_H);
  vdu2->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu2->Mode(Vdu::Memory);
  vdu2->Visible(true);
  vdu2->BorderWidth(0);
  vdu2->ShowGrid(showGridLines);
  vduPanel1->Add(vdu2);

  vdu3 = new Vdu(vduPanel1, VDU3_X, VDU3_Y, VDU_W, VDU_H);
  vdu3->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu3->Mode(Vdu::Scr);
  vdu3->Visible(true);
  vdu3->BorderWidth(0);
  vdu3->ShowGrid(showGridLines);
  vduPanel1->Add(vdu3);

  vdu4 = new Vdu(vduPanel2, VDU4_X, VDU4_Y, VDU_W, VDU_H);
  vdu4->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu4->Mode(Vdu::Order);
  vdu4->Visible(true);
  vdu4->BorderWidth(0);
  vdu4->ShowGrid(showGridLines);
  vduPanel2->Add(vdu4);

  vdu5 = new Vdu(vduPanel2, VDU5_X, VDU5_Y, VDU_W, VDU_H);
  vdu5->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu5->Mode(Vdu::Accumulator);
  vdu5->Visible(true);
  vdu5->BorderWidth(0);
  vdu5->ShowGrid(showGridLines);
  vduPanel2->Add(vdu5);

  vdu6 = new Vdu(vduPanel2, VDU6_X, VDU6_Y, VDU_W, VDU_H);
  vdu6->BackgroundColor(0x8000, 0x8000, 0x8000);
  vdu6->Mode(Vdu::Multiplier);
  vdu6->Visible(true);
  vdu6->BorderWidth(0);
  vdu6->ShowGrid(showGridLines);
  vduPanel2->Add(vdu6);

  label = new Label(vduPanel1, VDU1_X, VDU1_Y-25, VDU_W, 25, "Counter");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel1->Add(label);

  label = new Label(vduPanel1, VDU2_X, VDU2_Y-25, VDU_W, 25, "Memory");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel1->Add(label);

  label = new Label(vduPanel1, VDU3_X, VDU3_Y-25, VDU_W, 25, "Sequence control");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel1->Add(label);

  label = new Label(vduPanel2, VDU4_X, VDU4_Y-25, VDU_W, 25, "Order");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel2->Add(label);

  label = new Label(vduPanel2, VDU5_X, VDU5_Y-25, VDU_W, 25, "Accumulator");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel2->Add(label);

  label = new Label(vduPanel2, VDU6_X, VDU6_Y-25, VDU_W, 25, "Multiplier/Mulitplicand");
  label->BackgroundColor(0x8000, 0x8000, 0x8000);
  label->ForegroundColor(Color::Black());
  vduPanel2->Add(label);

  dial = new Dial(controlPanel, DIAL_X, DIAL_Y, DIAL_W, DIAL_H);
  dial->BackgroundColor(0xb000, 0xb000, 0xb000);
  dial->ForegroundColor(0x1000, 0x1000, 0x1000);
  dial->OnDial(new EventHandler(MainWindow::_dialEvent, this));
  dial->Visible(true);
  dial->BorderWidth(0);
  controlPanel->Add(dial);

  tankSelect = new RotaryKnob(vduPanel1, TANK_X, TANK_Y, TANK_W, TANK_H);
  tankSelect->BackgroundColor(0x8000, 0x8000, 0x8000);
  tankSelect->Visible(true);
  tankSelect->BorderWidth(0);
  tankSelect->OnTurn(new EventHandler(MainWindow::_tankEvent, this));
  vduPanel1->Add(tankSelect);

  telePrinter = new TelePrinter(this, 835, 0, width-835, 488);
  telePrinter->BackgroundColor(0xe000, 0xe000, 0xe000);
  telePrinter->Visible(true);
  telePrinter->BorderWidth(1);
  this->Add(telePrinter);
  ptr = telePrinter;

  emulatorPanel = new Panel(this, 835, 490, width-835, height-490);
  emulatorPanel->BackgroundColor(Color::White());
  emulatorPanel->Visible(true);
  emulatorPanel->BorderWidth(1);
  emulatorPanel->BorderColor(Color::Black());
  this->Add(emulatorPanel);

  initialOrders = new DropDownList(emulatorPanel, 110, 50, 150, 30);
  initialOrders->MaxVisibleItems(2);
  initialOrders->Add(new String("Initial Orders 1"));
  initialOrders->Add(new String("Initial Orders 2"));
  initialOrders->SelectedIndex(0);
  initialOrders->BackgroundColor(0xc000, 0xc000, 0xc000);
  initialOrders->ForegroundColor(Color::Black());
  initialOrders->OnValueChanged(new EventHandler(MainWindow::_ordersChanged, this));
  initialOrders->Visible(true);
  emulatorPanel->Add(initialOrders);

  mountTape = new Button(emulatorPanel, 110, 135, 150, 30);
  mountTape->Text("Mount Tape");
  mountTape->BorderWidth(0);
  mountTape->BackgroundColor(0xc000, 0xc000, 0xc000);
  mountTape->ForegroundColor(Color::Black());
  mountTape->OnRelease(new EventHandler(MainWindow::_tapeButtonPressed, this));
  mountTape->Visible(true);
  emulatorPanel->Add(mountTape);

  trace = new CheckBox(emulatorPanel, 25, emulatorPanel->Height() - 35, 75, 30);
  trace->Text("Trace");
  trace->Checked(false);
  trace->BackgroundColor(Color::White());
  trace->ForegroundColor(Color::Black());
  trace->OnCheckChanged(new EventHandler(MainWindow::_traceChanged, this));
  trace->Visible(true);
  emulatorPanel->Add(trace);

  use1949 = new RadioButton(emulatorPanel, 125, emulatorPanel->Height()-35, 75, 30);
  use1949->Text("1949");
  use1949->Checked(cpu->Only1949());
  use1949->BackgroundColor(Color::White());
  use1949->ForegroundColor(Color::Black());
  use1949->Visible(true);
  use1949->OnCheckChanged(new EventHandler(MainWindow::_useChanged, this));
  emulatorPanel->Add(use1949);

  use1957 = new RadioButton(emulatorPanel, 200, emulatorPanel->Height()-35, 75, 30);
  use1957->Text("1957");
  use1957->Checked(!cpu->Only1949());
  use1957->BackgroundColor(Color::White());
  use1957->ForegroundColor(Color::Black());
  use1957->Visible(true);
  use1957->OnCheckChanged(new EventHandler(MainWindow::_useChanged, this));
  emulatorPanel->Add(use1957);

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

void MainWindow::_tankEvent(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->tankEvent(sender, (ValueEventArgs&)args);
  }

void MainWindow::_ordersChanged(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->ordersChanged(sender, (ValueEventArgs&)args);
  }

void MainWindow::_tapeButtonPressed(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->tapeButtonPressed(sender, (MouseEventArgs&)args);
  }

void MainWindow::_traceChanged(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->traceChanged(sender, (ValueEventArgs&)args);
  }

void MainWindow::_useChanged(void* obj, void* sender, EventArgs args) {
  ((MainWindow*)obj)->useChanged(sender, (ValueEventArgs&)args);
  }

