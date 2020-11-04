# Source Files
SOURCE1 = quadTest.c


# Object Files
OBJ1  	= $(patsubst %.c, %.o, $(SOURCE1))

# Program Files
PROG1 = quadTest
PROG2 = quadTestspeed


# Output Files
OUT  = out.txt
MEM = mem.txt
SPEED = speed.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, pedantic?, debugging, optimization 0
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -pedantic -lm
MACRO  = -DEN_TIME


# VALGRING THINGS
# ---------------
#  VAL: valgrind
#  VFLAGS: Flags to run valgrind
VAL    = valgrind
VFLAGS = --tool=memcheck --leak-check=yes

# Dont print out each execution line
.SILENT:

#############################################################################


all: $(PROG1) $(PROG2)


$(OBJ1): $(SOURCE1)
	$(CC) $(SOURCE1) -c $(CFLAGS)	
	
$(OBJ2): $(SOURCE1)
	$(CC) $(SOURCE1) -c $(CFLAGS)

$(PROG1): $(OBJ1)
	$(CC) $(OBJ1) -o $(PROG1) $(CFLAGS) -O1

$(PROG2): $(OBJ1)
	$(CC) $(OBJ1) -o $(PROG2) $(CFLAGS) $(MACRO) -O1


tests: $(PROG1)
	@echo "Running quadratic solver test"
	@echo "Finding roots for 0x**2 + 0x + 1:" > $(OUT)
	./$(PROG1) -a 0 -b 0 -c 1 &>> $(OUT)
	@echo "	" &>> $(OUT)
	@echo "Finding roots for 1x**2 + 0x " &>> $(OUT)
	./$(PROG1) -a 0 -b 0 &>> $(OUT)
	@echo "	" &>> $(OUT)
	@echo "Finding roots for 1x**2 + 0x + 1" &>> $(OUT)
	./$(PROG1) -a 1 -b 0 -c 1 &>> $(OUT)
	


mem: $(PROG1)
	$(VAL) $(VFLAGS) ./$(PROG1) -a 6 -b 11 -c -35 &>> $(MEM)
	



# # # # # # # # # # Help # # # # # # # # # # 

help:
	@echo    all: builds $(SOURCE1) into binary.
	@echo  test: runs $(PROG1) with three test to confirm functionality.
	@echo    mem: runs $(PROG1) with valgrind and writes rsults to $(MEM).
	@echo  clean: removes program and output.


# # # # # # # # # # Clean # # # # # # # # # # 
clean:
	-rm -f $(OUT)
	-rm -f $(MEM)
	-rm -f $(PROG1)
	-rm -f $(OBJ1)
