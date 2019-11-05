PROJECT = edsac
CC = gcc
LINK = gcc
DEFS = -DTEXT
LIBDIR =
LIBS =
INCDIR = -I.
INCS =
OBJS = \
	../common/cpu.o \
	../common/debug.o \
	../common/disassem.o \
	main.o \
	printer.o \
	../common/reader.o \
	showacc.o \
	showmemory.o \
	showmult.o \
	showmultiplicand.o \
	showtank.o \
	stopmode.o \
	terminal.o

$(PROJECT) : $(OBJS)
	$(LINK) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.c.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

../common/cpu.o: header.h terminal.h ../common/cpu.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/cpu.c -o ../common/cpu.o

../common/debug.o: header.h terminal.h ../common/debug.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/debug.c -o ../common/debug.o

../common/disassem.o: header.h terminal.h ../common/disassem.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/disassem.c -o ../common/disassem.o

../common/reader.o: header.h terminal.h ../common/reader.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/reader.c -o ../common/reader.o

clean:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

main.o:              header.h terminal.h main.c
printer.o:           header.h terminal.h printer.c
showacc.o:           header.h terminal.h showacc.c
showmemory.o:        header.h terminal.h showmemory.c
showmult.o:          header.h terminal.h showmult.c
showmultiplicand.o:  header.h terminal.h showmultiplicand.c
showtank.o:          header.h terminal.h showtank.c
stopmode.o:          header.h terminal.h stopmode.c
terminal.o:          header.h terminal.h terminal.c
