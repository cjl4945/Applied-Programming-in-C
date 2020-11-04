# Source Files
SOURCE1 = hw12.c
SOURCE2 = correction.c
SOURCE3 = myplot.c
SOURCE4 = DynamicArrays.c

# Program Files
PROG1 = hw12
PROG2 = correction
PROG3 = myplot

# Input Files
BI1	= realDevice
BI2	= detError
BI3	= diffVal

# Output File
OUT  = out.txt
MEM = mem.txt
PNG = plotfile.png
REGDAT  = data.txt
DEVDAT  = realdevice.txt
CORDAT  = correction.txt
ALLDAT  = alldata.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, pedantic?, debugging, optimization 0
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -pedantic -g -O1 -lm -lgsl -lgslcblas

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
all: $(PROG1) $(PROG2) $(PROG3)
	./$(BI1) | ./$(BI3) > $(REGDAT)


# # # # # # # # # # PROG1 # # # # # # # # # # 
.PHONY:$(PROG1)
$(PROG1): $(SOURCE1) $(SOURCE4)
	./$(BI1) | ./$(BI3) > $(REGDAT)
	$(CC) $(SOURCE1) $(SOURCE4) -o $(PROG1) $(CFLAGS) -DHW8


# # # # # # # # # # PROG2 # # # # # # # # # # 
.PHONY:$(PROG2)
$(PROG2): $(SOURCE2)
	./$(BI1) | ./$(BI3) > $(REGDAT)
	$(CC) $(SOURCE2) -o $(PROG2) $(CFLAGS)


# # # # # # # # # # PROG3 # # # # # # # # # # 
.PHONY:$(PROG3)
$(PROG3):
	./$(BI1) | ./$(BI3) > $(REGDAT)


# # # # # # # # # # base # # # # # # # # # # 
.PHONY:base
base:
	./$(BI1) | ./$(BI3) > $(REGDAT)
	./$(BI1) | ./$(BI2) > $(OUT)


# # # # # # # # # # correct # # # # # # # # # # 
.PHONY:correct
correct: $(BI2) $(PROG2)
	./$(BI1) | ./$(BI3) > $(REGDAT)
	./$(BI1) | ./$(PROG2) | ./$(BI2) > $(CORDAT)
	


# # # # # # # # # # plot # # # # # # # # # # 
.PHONY:plot
plot: $(PROG3) 
	./$(BI1) > $(DEVDAT)
	./$(BI1) | ./$(PROG2) > $(CORDAT)
	paste $(DEVDAT) $(CORDAT) > $(ALLDAT)
	./myplot -in $(ALLDAT) -out $(PNG)


# # # # # # # # # # MEM # # # # # # # # # # 
.PHONY:mem
mem: $(PROG1)
	$(VAL) $(VFLAGS) ./$(PROG1) -o 3 -p $(REGDAT) &> $(MEM)
	cat $(MEM)


# # # # # # # # # # X # # # # # # # # # # #
.PHONY:x
x: $(BI1) $(BI2) $(BI3) $(PROG3)
	chmod +x $(BI1) $(BI2) $(BI3)	$(PROG3)



# # # # # # # # # # Help # # # # # # # # # # 
.PHONY:help
help:
	@echo     all: builds $(PROG1), $(PROG2), and $(PROG3).
	@echo    base: runs $(PROG1) with $(GE1) - $(GE4) and writes results to $(OUT).
	@echo correct: runs $(PROG2) with $(GE1) - $(GE4) and writes results to $(CORDAT).
	@echo  	 plot: runs $(PROG3) with the corrected data.
	@echo     mem: runs $(PROG1) with $(GE2) and valgrind then writes results to $(MEM).
	@echo    help: You figured this one out.
	@echo   clean: removes program and output.


# # # # # # # # # # Clean # # # # # # # # # # 
.PHONY:clean
clean:
	-rm -f $(OUT)
	-rm -f $(MEM)
	-rm -f $(PNG)
	-rm -f $(DEVDAT)
	-rm -f $(REGDAT)
	-rm -f $(CORDAT)
	-rm -f $(ALLDAT)
	-rm -f $(PROG1)
	-rm -f $(PROG2)
