# Source Files
SOURCE2 = TestSearch.c
SOURCE4 = LinkedLists.c
SOURCE5 = DynamicArrays.c

# Program Files
PROG2 = TestSearch 
PROG4 = LinkedLists
PROG5 = DynamicArrays

# Output File
OUT  = out.txt
MEM = mem.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, pedantic?, debugging, optimization 0
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -pedantic -g -O0

# VALGRING THINGS
# ---------------
#  VAL: valgrind
#  VFLAGS: Flags to run valgrind
VAL    = valgrind
VFLAGS = --tool=memcheck --leak-check=yes 

# Dont print out each execution line
.SILENT:

#############################################################################
.PHONY:all
all: $(PROG2)





# # # # # # # # # # TestSearch # # # # # # # # # #
#
# build
.PHONY:$(PROG2)
$(PROG2): $(SOURCE2) $(SOURCE4) $(SOURCE5)
	$(CC) $(SOURCE2) $(SOURCE4) $(SOURCE5) -o $(PROG2) $(CFLAGS) -DSEARCHWORD

# test
.PHONY:searchword
searchword: $(SOURCE2) $(SOURCE4) $(SOURCE5)
	./$(PROG2) engWords.txt space &> out.txt
	cat out.txt




# # # # # # # # # # Valgrind # # # # # # # # # # 
.PHONY:mem
mem: $(PROG2)
	$(VAL) $(VFLAGS) ./$(PROG2) fiveTest.txt &> mem.txt
	cat mem.txt
	

# # # # # # # # # # Help # # # # # # # # # # 
.PHONY:help
help:
	@echo    all: builds  $(SOURCE2).
	@echo searchword: runs $(PROG2) and writes results to out.txt.
	@echo    mem: runs $(PROG2) with valgrind and writes rsults to $(MEM).
	@echo  clean: removes program and output.


# # # # # # # # # # Clean # # # # # # # # # # 
.PHONY:clean
clean:
	-rm -f $(OUT)
	-rm -f $(MEM)
	-rm -f $(PROG2)
	-rm -f $(PROG4)
	-rm -f $(PROG5)
