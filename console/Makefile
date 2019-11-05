PROJECT = edsac
CC = gcc
LINK = gcc
DEFS =
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
	showmult.o \
	showmultiplicand.o \
	showtank.o \
	stopmode.o

$(PROJECT) : $(OBJS)
	$(LINK) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.c.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

../common/cpu.o: header.h ../common/cpu.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/cpu.c -o ../common/cpu.o

../common/debug.o: header.h ../common/debug.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/debug.c -o ../common/debug.o

../common/disassem.o: header.h ../common/disassem.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/disassem.c -o ../common/disassem.o

../common/reader.o: header.h ../common/reader.c
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c ../common/reader.c -o ../common/reader.o

clean:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

main.o:                header.h main.c
printer.o:             header.h printer.c
showacc.o:             header.h showacc.c
showmult.o:            header.h showmult.c
showmultiplicand.o:    header.h showmultiplicand.c
showtank.o:            header.h showtank.c
stopmode.o:            header.h stopmode.c

