PROJECT = edsac
CC = g++
LINK = g++
DEFS = -pthread -std=c++11 -Wall
LIBDIR =
LIBS = -lSmrFramework -lSmrAppFramework -lX11 -lXft
INCDIR = -I. -I../common/ -I/usr/include/freetype2
INCS =
OBJS = \
	../common/Cpu.o \
	CpuThread.o \
	Dial.o \
	MainWindow.o \
	MainWindow_init.o \
	../common/Reader.o \
	Printer.o \
	Vdu.o \
	Main.o

$(PROJECT) : $(OBJS)
	$(LINK) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

../common/Cpu.o: header.h ../common/Cpu.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Cpu.cpp -o ../common/Cpu.o

../common/Reader.o: header.h ../common/Reader.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Reader.cpp -o ../common/Reader.o

clean:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

CpuThread.o:           header.h CpuThread.h CpuThread.cpp
Dial.o:                header.h Dial.h Dial.cpp
Main.o:                header.h MainWindow.h Main.cpp
MainWindow.o:          header.h MainWindow.h MainWindow.cpp
MainWindow_init.o:     header.h MainWindow.h MainWindow_init.cpp
Printer.o:             header.h Printer.cpp
Vdu.o:                 header.h Vdu.h Vdu.cpp

