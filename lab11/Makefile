# Source Files
SOURCE2 = eqn2solve.c
SOURCE3 = rootfinding.c
SOURCE4 = intTest.c

# Object Files
OBJ2   = $(patsubst %.c, %.o, $(SOURCE2))
OBJ3   = $(patsubst %.c, %.o, $(SOURCE3))
OBJ4   = $(patsubst %.c, %.o, $(SOURCE4))

# Program Files
PROG4  = intTest
PROGMEM = intTest_mem

# Output File
OUT  = out.txt
MEM = mem.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, O1 optimization, pedantic?, debugging
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -O3 -pedantic -g
LFLAGS = -lm

# Valgrind Things
# ---------------
# VAL: valgrind
# VFLAGS: flags to run valgrind
VAL    = valgrind
VFLAGS = --tool=memcheck --leak-check=yes --track-origins=yes -v

# GDB Things
# ----------
# GDB: gdb
GDB = gdb

# Dont print out each execution line
.SILENT:

#############################################################################

all: $(PROG4)

$(OBJ2): $(SOURCE2)
	$(CC) $(SOURCE2) -c $(CFLAGS)

$(OBJ3): $(SOURCE3)
	$(CC) $(SOURCE3) -c $(CFLAGS)

$(OBJ4): $(SOURCE4)
	$(CC) $(SOURCE4) -c $(CFLAGS) -DEN_TIME

$(PROGMEM): $(OBJ4)$(OBJ2)$(OBJ3)
	$(CC) $(OBJ4) $(OBJ2) $(OBJ3) -o $(PROGMEM) $(CFLAGS) $(LFLAGS)
	
$(PROG4): $(OBJ4)$(OBJ2)$(OBJ3)
	$(CC) $(OBJ4) $(OBJ2) $(OBJ3) -o $(PROG4) $(CFLAGS) $(LFLAGS) -DEN_TIME


test: $(PROG4)
	./$(PROG4) &>> $(OUT)



mem: $(PROGMEM)
	valgrind ./$(PROGMEM)  &> $(MEM)
	
.PHONY:help
help:
	@echo all: builds $(SOURCE4)
	@echo test: run root finding test and output information to $(OUT).
	@echo mem: Run valgrind with timing disabled
#	@echo help: You know why you're here
	@echo clean: removes output, object, and program files.

clean:
	-rm -f $(OUT)
	-rm -f $(MEM)
	-rm -f $(PROG4)
	-rm -f $(OBJ2)
	-rm -f $(OBJ3)
	-rm -f $(OBJ4)
