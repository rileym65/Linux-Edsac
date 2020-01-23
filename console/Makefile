PROJECT = edsac
CC = g++
LINK = g++
DEFS = -pthread -std=c++11
LIBDIR =
LIBS = -lSmrFramework
INCDIR = -I. -I../common/
INCS =
OBJS = \
	../common/Cpu.o \
	../common/Debug.o \
	Main.o \
	../common/Printer.o \
	../common/Reader.o \
	Stopmode.o

$(PROJECT) : $(OBJS)
	$(LINK) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

../common/Cpu.o: header.h ../common/Cpu.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Cpu.cpp -o ../common/Cpu.o

../common/Debug.o: header.h ../common/Debug.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Debug.cpp -o ../common/Debug.o

../common/Reader.o: header.h ../common/Reader.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Reader.cpp -o ../common/Reader.o

../common/Printer.o: header.h ../common/Printer.cpp
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/Printer.cpp -o ../common/Printer.o

clean:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

Main.o:                header.h Main.cpp
Stopmode.o:            header.h Stopmode.cpp

