# Source Files
SOURCE1 = hw7c.c
SOURCE2 = hw7c2.c
SOURCE3 = hw7cpp.cpp
SOURCE4 = hw7cpp2.cpp

# Program Files
PROG1 = hw7c
PROG2 = hw7c2 
PROG3 = hw7cpp
PROG4 = hw7cpp2
PROG5 = hw7cm
PROG6 = hw7c2m
PROG7 = hw7cppm
PROG8 = hw7cpp2m

# Output File
OUT  = out.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, O1 optimization, pedantic?, debugging
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -pedantic -O1 



# CPP Things
# --------
# CPP: g++ things
CPP   = g++ -Wall -pedantic 


# Dont print out each execution line
.SILENT:

#############################################################################
.PHONY:all
all: $(PROG1) $(PROG2) $(PROG3) $(PROG4) $(PROG5) $(PROG6) $(PROG7) $(PROG8)


# Test 1
.PHONY:$(PROG1)
$(PROG1): $(SOURCE1) 
	$(CC) $(CFLAGS) -DEN_TIME $(SOURCE1) -o $(PROG1)

# Test 2
.PHONY:$(PROG2)
$(PROG2): $(SOURCE2)
	$(CC) $(CFLAGS) -DEN_TIME $(SOURCE2) -o $(PROG2)
# Test 3
.PHONY:$(PROG5)
$(PROG5): $(SOURCE1)
	$(CC) $(CFLAGS) -DEN_TIME -DMOVE_IO_CLOSE $(SOURCE1) -o $(PROG5)
# Test 4
.PHONY:$(PROG6)
$(PROG6): $(SOURCE2)
	$(CC) $(CFLAGS) -DEN_TIME -DMOVE_IO_CLOSE $(SOURCE2) -o $(PROG6)
# Test 5
.PHONY:$(PROG3)
$(PROG3): $(SOURCE3)
	$(CPP) -DEN_TIME $(SOURCE3) -o $(PROG3)
# Test 6
.PHONY:$(PROG4)
$(PROG4): $(SOURCE4)
	$(CPP) -DEN_TIME $(SOURCE4) -o $(PROG4)
# Test 7
.PHONY:$(PROG7)
$(PROG7): $(SOURCE3)
	$(CPP) -DEN_TIME -DMOVE_IO_CLOSE $(SOURCE3) -o $(PROG7)
# Test 8
.PHONY:$(PROG8)
$(PROG8): $(SOURCE4)
	$(CPP) -DEN_TIME -DMOVE_IO_CLOSE $(SOURCE4) -o $(PROG8)


.PHONY:test
test: $(PROG1) $(PROG2) $(PROG3) $(PROG4) $(PROG5) $(PROG6) $(PROG7) $(PROG8)
	@echo "Testing $(PROG1) without MOVE_IO_CLOSE macro"
	@echo "$(PROG1):" > $(OUT)
	@./$(PROG1) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG2) without MOVE_IO_CLOSE macro"
	@echo "$(PROG2):" >> $(OUT)
	@./$(PROG2) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG5) with MOVE_IO_CLOSE macro"
	@echo "$(PROG5):" >> $(OUT)
	@./$(PROG5) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG6) with MOVE_IO_CLOSE macro"
	@echo "$(PROG6):" >> $(OUT)
	@./$(PROG6) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG3) without MOVE_IO_CLOSE macro"
	@echo "$(PROG3):" >> $(OUT)
	@./$(PROG3) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG4) without MOVE_IO_CLOSE macro"
	@echo "$(PROG4):" >> $(OUT)
	@./$(PROG4) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG7) with MOVE_IO_CLOSE macro"
	@echo "$(PROG7):" >> $(OUT)
	@./$(PROG7) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(PROG8) with MOVE_IO_CLOSE macro"
	@echo "$(PROG8):" >> $(OUT)
	@./$(PROG8) data.txt &>> $(OUT)
	@echo " " >> $(OUT)


.PHONY:help
help:
	@echo all: builds $(SOURCE1), $(SOURCE2), $(SOURCE3), and $(SOURCE4) with and without the MOVE_IO_CLOSE macro into programs.
	@echo test: runs 8 test cases for c and cpp files using with and without the MOVE_IO_CLOSE macro. 
	@echo       and writes that to $(OUT).
	@echo clean: removes temporary and immediate files.


.PHONY:clean
clean:
	-rm -f $(OUT)
	-rm -f $(PROG1)
	-rm -f $(PROG2)
	-rm -f $(PROG3)
	-rm -f $(PROG4)
	-rm -f $(PROG5)
	-rm -f $(PROG6)
	-rm -f $(PROG7)
	-rm -f $(PROG8)
