# Source Files
SOURCE1 = hw9.c
SOURCE2 = eqn2solve.c
SOURCE3 = rootfinding.c

# Object Files
OBJ1   = $(patsubst %.c, %.o, $(SOURCE1))
OBJ2   = $(patsubst %.c, %.o, $(SOURCE2))
OBJ3   = $(patsubst %.c, %.o, $(SOURCE3))

# Program Files
PROG1  = hw9

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
# GDB Things
# ----------
# GDB: gdb
GDB = gdb

# Dont print out each execution line
.SILENT:

#############################################################################
.PHONY:all
all: $(PROG1) 

$(OBJ1): $(SOURCE1)
	# to enable timing, uncomment the below line and recomment the line below it
	#$(CC) $(SOURCE1) -c $(CFLAGS) -DEN_TIME
	$(CC) $(SOURCE1) -c $(CFLAGS)

$(OBJ2): $(SOURCE2)
	$(CC) $(SOURCE2) -c $(CFLAGS)

$(OBJ3): $(SOURCE3)
	$(CC) $(SOURCE3) -c $(CFLAGS)


$(PROG1): $(OBJ1)$(OBJ2)$(OBJ3)
	$(CC) $(OBJ1) $(OBJ2) $(OBJ3) -o $(PROG1) $(CFLAGS) $(LFLAGS)

#$(PROG4): $(OBJ4)$(OBJ2)$(OBJ3)
#	$(CC) $(OBJ4) $(OBJ2) $(OBJ3) -o $(PROG4) $(CFLAGS) $(LFLAGS)


test: $(PROG1)
	./$(PROG1) -b -t 1E-6 -ga -2.5 -gb 2.5 -v > $(OUT)
	./$(PROG1) -n -t 1E-6 -ba -1.5 -v >> $(OUT)
	./$(PROG1) -n -t 1E-6 -ba 1.5 -v >> $(OUT)
	./$(PROG1) -s -t 1E-6 -ba -1.5 -bb -5 -v >> $(OUT)
	./$(PROG1) -s -t 1E-6 -ba 1.5 -bb 1.6 -v >> $(OUT)
	cat $(OUT)


.PHONY:opts
opts: $(PROG1)
	./$(PROG1) -b -tol 1E-6 -ga -2 -gb 3 -verb > $(OUT)
	./$(PROG1) -b -t 1E-6 -g -2 -u 3 -v
	./$(PROG1) -b -t 1E-6 -ba -2 -bb 3 -v >> $(OUT)
	cat $(OUT)
	
mem: $(PROG1)
	@echo "bisection ‐2.5, 2.5:" > $(MEM)
	$(VAL) ./$(PROG1) -b -t 1E-6 -ga -2.5 -gb 2.5 -v &>> $(MEM)
	@echo "	" >> $(MEM)
	@echo "secant -1.5 -1.6" >> $(MEM)
	$(VAL) ./$(PROG1) -s -t 1E-6 -ga -1.5 -gb -1.6 -v &>> $(MEM)
	@echo "	" >> $(MEM)
	@echo "newton -1.5" >> $(MEM)
	$(VAL) ./$(PROG1) -n -t 1E-6 -ba -1.5 -v &>> $(MEM)
 
.PHONY:help
help:
	@echo all: builds $(SOURCE1)
	@echo test: run root finding tests and output information to $(OUT).
	@echo opts: run bisection,secant, and netwon root finding with various command\
			variances and output information to $(OUT).
	@echo help: looks like you have figured this one out!
	@echo clean: removes output, object, and program files.

.PHONY:clean
clean:
	-rm -f $(OUT)
	-rm -f $(PROG1)
	-rm -f $(OBJ1)
	-rm -f $(OBJ2)
	-rm -f $(OBJ3)
	-rm -f $(MEM)
