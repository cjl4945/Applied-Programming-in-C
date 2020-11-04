CC=gcc
CFLAGS=-I.

all: myMain.o myFunctions.o
	$(CC) -g -o myMain myMain.o myFunctions.o
clean:
	rm -f myMain myMain.o
	
mem:
	valgrind ./myMain
	
help:
	@echo "make options:  all, mem, clean, help"
