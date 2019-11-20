#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <SmrFramework.h>
#include <SmrAppFramework.h>
#include "Vdu.h"
#include "Dial.h"
#include "RotaryKnob.h"
#include "TelePrinter.h"

using namespace SmrFramework;

class MainWindow : public Form {
  protected:
    Boolean       stopped;
    Button       *clearButton;
    Button       *resetButton;
    Button       *startButton;
    Button       *stepButton;
    Button       *stopButton;
    Control      *stopLamp;
    Vdu          *vdu1;
    Vdu          *vdu2;
    Vdu          *vdu3;
    Vdu          *vdu4;
    Vdu          *vdu5;
    Vdu          *vdu6;
    Panel        *vduPanel1;
    Panel        *vduPanel2;
    Panel        *controlPanel;
    Panel        *emulatorPanel;
    Dial         *dial;
    Timer        *timer;
    RotaryKnob   *tankSelect;
    TelePrinter  *telePrinter;
    DropDownList *initialOrders;
    Button       *mountTape;
    CheckBox     *trace;
    RadioButton  *use1949;
    RadioButton  *use1957;
    void InitializeComponent();
    void clearButtonPressed(void* sender, MouseEventArgs args);
    void resetButtonPressed(void* sender, MouseEventArgs args);
    void stepButtonPressed(void* sender, MouseEventArgs args);
    void startButtonPressed(void* sender, MouseEventArgs args);
    void stopButtonPressed(void* sender, MouseEventArgs args);
    void dialEvent(void* sender, ValueEventArgs args);
    void tankEvent(void* sender, ValueEventArgs args);
    void ordersChanged(void* sender, ValueEventArgs args);
    void tapeButtonPressed(void* sender, MouseEventArgs args);
    void traceChanged(void* sender, ValueEventArgs args);
    void useChanged(void* sender, ValueEventArgs args);
    void TimerTick(void* sender);
    void static _clearButtonPressed(void* obj, void* sender, EventArgs args);
    void static _resetButtonPressed(void* obj, void* sender, EventArgs args);
    void static _startButtonPressed(void* obj, void* sender, EventArgs args);
    void static _stepButtonPressed(void* obj, void* sender, EventArgs args);
    void static _stopButtonPressed(void* obj, void* sender, EventArgs args);
    void static _TimerTick(void* obj, void* sender, EventArgs args);
    void static _dialEvent(void* obj, void* sender, EventArgs args);
    void static _tankEvent(void* obj, void* sender, EventArgs args);
    void static _ordersChanged(void* obj, void* sender, EventArgs args);
    void static _tapeButtonPressed(void* obj, void* sender, EventArgs args);
    void static _traceChanged(void* obj, void* sender, EventArgs args);
    void static _useChanged(void* obj, void* sender, EventArgs args);
  public:
    MainWindow(int w, int h);
    ~MainWindow();
    Int32 InitialOrders();
    Int32 InitialOrders(Int32 i);
  };

#endif
