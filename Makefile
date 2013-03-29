all: TimeTools test
EXEC = test
SOURCE = test.c
LIB = libtimetools.a
objects = TimeTools.o
objects2 = TimeTools.c
lib =  libtimetools.a
CFLAGS = -Wall -O2
CC = gcc 

TimeTools : $(objects) 
	ar -rc $(LIB) $(objects) 
TimeTools.o:  TimeTools.c TimeTools.h
	$(CC) -c $(objects2) $(CFLAGS)
test:
	$(CC) -o $(EXEC) $(SOURCE) $(lib) $(CFLAGS)


.PHONY: clean 
clean : 
	rm -f $(objects) $(LIB) $(EXEC)

