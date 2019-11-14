#define MAIN

#include <unistd.h>
#include "header.h"
#include "images.h"

int main(int argc, char** argv) {
  UInt32  i;
  char   tapeFilename[1024];

  cpu = new Cpu();
  reader = new Reader();
  printer = new Printer();
  cpu->AttachReader(reader);
  cpu->AttachPrinter(printer);

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-1") == 0) initialOrders = 1;
    if (strcmp(argv[i],"-2") == 0) initialOrders = 2;
    if (strcmp(argv[i],"-t") == 0) cpu->Trace('Y');
    if (strcmp(argv[i],"-1949") == 0) cpu->Only1949(true);
    if (argv[i][0] != '-') {
      strcpy(tapeFilename,argv[i]);
      if (tapeFilename[strlen(tapeFilename)-1] == '1') initialOrders = 1;
      if (tapeFilename[strlen(tapeFilename)-1] == '2') initialOrders = 2;
      }
    }

  printf("Initial Orders: %d\n",initialOrders);
  if (strlen(tapeFilename) > 0) {
    if (!reader->Mount(tapeFilename)) {
      printf("Could not open tape file: %s\n",tapeFilename);
      exit(1);
      }
    }

  app = new Application();
  if (app == NULL) {
    printf("Could not create application object\n");
    exit(1);
    }
  app->LoopDelay(1000);

  toggleOff = new Image(new MemoryStream(toggle_up, toggle_up_length));
  toggleOn = new Image(new MemoryStream(toggle_dn, toggle_dn_length));
  stopOn = new Image(new MemoryStream(stop_on, stop_on_length));
  stopOff = new Image(new MemoryStream(stop_off, stop_off_length));
  pushOn = new Image(new MemoryStream(push_on, push_on_length));
  pushOff = new Image(new MemoryStream(push_off, push_off_length));

  window = new MainWindow(1000, 700);
  window->BorderWidth(5);
  window->BackgroundColor(0x8000, 0x8000, 0x8000);
  window->Text("EDSAC");
  app->AddForm(window);
  window->Visible(true);

  cpu->Reset();
  if (initialOrders == 1) cpu->LoadOrders1();
    else cpu->LoadOrders2();
  cpu->StopCommand(true);
  cpuThread = new CpuThread(cpu);
  cpuThread->Start(NULL);

  try {
    app->Run();
    }
  catch (Exception &e) {
    printf("Exception caught: %s\n",e.Message());
    if (e.Sender() != NULL) printf("  Type: %s\n",e.Sender()->Type());
      else printf("Sender is NULL\n");
    fflush(stdout);
    }

  cpuThread->Terminate();
  usleep(1000);
  delete(cpuThread);
  delete(cpu);
  delete(app);
  delete(window);
  return 0;
  }

