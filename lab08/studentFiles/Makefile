# Source Files
SOURCE1 = hw8c.c
SOURCE2 = hw8c_opt1.c
SOURCE3 = hw8c_opt2.c
SOURCE4 = hw8c_opt3.c

# Program Files
HW8C = hw8c
OPT1 = hw8c_opt1
OPT2 = hw8c_opt2
OPT3 = hw8c_opt3

# Output File
OUT  = out.txt
DATA = data.txt

# C Things
# --------
# CC: gcc
# CFLAGS: warnings all, c99, O1 optimization, pedantic?, debugging
# LFLAGS: math library
CC     = gcc 
CFLAGS = -Wall -std=c99 -pedantic -g 
MOVECLOSE  = -DMOVE_IO_CLOSE
MACRO  = -DEN_TIME 




# Dont print out each execution line
.SILENT:

#############################################################################
all: $(HW8C) $(OPT1) $(OPT2) $(OPT3)


# build for hw8c.c and all variations
$(HW8C): $(SOURCE1) 
	echo "Building $@.c $@ all variations"
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O0 $(SOURCE1) -o $(HW8C)_0
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O1 $(SOURCE1) -o $(HW8C)
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O2 $(SOURCE1) -o $(HW8C)_2
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O3 $(SOURCE1) -o $(HW8C)_3
	$(CC) $(CFLAGS) $(MOVECLOSE)  -O1 $(SOURCE1) -o $(HW8C)_mem
	$(CC) -g -O -c $(SOURCE1)	

# build for hw8c_opt1.c and all variations
$(OPT1): $(SOURCE2)
	echo "Building $@.c $@ all variations"
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O0 $(SOURCE2) -o $(OPT1)_0
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O1 $(SOURCE2) -o $(OPT1)
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O2 $(SOURCE2) -o $(OPT1)_2
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O3 $(SOURCE2) -o $(OPT1)_3
	$(CC) $(CFLAGS) $(MOVECLOSE) -O1 $(SOURCE2) -o $(OPT1)_mem
	$(CC) -g -O -c $(SOURCE2)

# build for hw8c_opt2.c	and all	variations
$(OPT2): $(SOURCE3)
	echo "Building $@.c $@ all variations"
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O0 $(SOURCE3) -o $(OPT2)_0
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O1 $(SOURCE3) -o $(OPT2)
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O2 $(SOURCE3) -o $(OPT2)_2
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O3 $(SOURCE3) -o $(OPT2)_3
	$(CC) $(CFLAGS) $(MOVECLOSE)  -O1 $(SOURCE3) -o $(OPT2)_mem
	$(CC) -g -O -c $(SOURCE3)


# build for hw8c_opt3.c and all variations
$(OPT3): $(SOURCE4)
	echo "Building $@.c $@ all variations"
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O0 $(SOURCE4) -o $(OPT3)_0
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O1 $(SOURCE4) -o $(OPT3)
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O2 $(SOURCE4) -o $(OPT3)_2
	$(CC) $(CFLAGS) $(MOVECLOSE) $(MACRO) -O3 $(SOURCE4) -o $(OPT3)_3
	$(CC) $(CFLAGS) $(MOVECLOSE)  -O1 $(SOURCE4) -o $(OPT3)_mem
	$(CC) -g -O -c $(SOURCE4)


.PHONY:mem
mem: $(HW8C) $(OPT1) $(OPT2) $(OPT3)
	@echo "Run valgrind on $(HW8C), $(OPT1), $(OPT2), and $(OPT3)"
	@echo "Printing results in mem.txt"
	@echo "$(HW8C)_mem:" > mem.txt
	valgrind ./$(HW8C)_mem $(DATA) &>> mem.txt
	@echo " " >> mem.txt
	@echo "$(OPT1)_mem:" >> mem.txt
	valgrind ./$(OPT1)_mem $(DATA) &>> mem.txt
	@echo " " >> $(OUT)
	@echo "$(OPT2)_mem:" >> mem.txt
	valgrind ./$(OPT2)_mem $(DATA) &>> mem.txt
	@echo " " >> $(OUT)
	@echo "$(OPT3)_mem:" >> mem.txt
	valgrind ./$(OPT3)_mem $(DATA) &>> mem.txt


test: $(HW8C) $(OPT1) $(OPT2) $(OPT3)
	@echo "Testing for $(HW8C), $(OPT1), $(OPT2), $(OPT3)"
	@echo "All performances testing will be placed in $(OUT)"
	@echo "Testing $(HW8C) with optimization levels (-O0 to -O3)"
	@echo "$(HW8C)_0:" > $(OUT)
	@./$(HW8C)_0 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(HW8C):" >> $(OUT)
	@./$(HW8C) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(HW8C)_2:" >> $(OUT)
	@./$(HW8C)_2 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(HW8C)_3:" >> $(OUT)
	@./$(HW8C)_3 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(OPT1) with optimization levels (-O0 to -O3)"
	@echo "$(OPT1)_0:" >> $(OUT)
	@./$(OPT1)_0 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT1):" >> $(OUT)
	@./$(OPT1) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT1)_2:" >> $(OUT)
	@./$(OPT1)_2 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT1)_3:" >> $(OUT)
	@./$(OPT1)_3 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(OPT2) with optimization levels (-O0 to -O3)"
	@echo "$(OPT2)_0:" >> $(OUT)
	@./$(OPT2)_0 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT2):" >> $(OUT)
	@./$(OPT2) data.txt &>> $(OUT)
	@echo "	" >> $(OUT)
	@echo "$(OPT2)_2:" >> $(OUT)
	@./$(OPT2)_2 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT2)_3:" >> $(OUT)
	@./$(OPT2)_3 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "Testing $(OPT3) with optimization levels (-O0 to -O3)"
	@echo "$(OPT3)_0:" >> $(OUT)
	@./$(OPT3)_0 data.txt &>> $(OUT)
	@echo "	" >> $(OUT)
	@echo "$(OPT3):" >> $(OUT)
	@./$(OPT3) data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT3)_2:" >> $(OUT)
	@./$(OPT3)_2 data.txt &>> $(OUT)
	@echo " " >> $(OUT)
	@echo "$(OPT3)_0:" >> $(OUT)
	@./$(OPT3)_0 data.txt &>> $(OUT)
	@echo " " >> $(OUT)



help:
	@echo all: builds $(SOURCE1), $(SOURCE2), $(SOURCE3), and $(SOURCE4) and all of their variations .
	@echo test: runs the tests for $(SOURCE1), $(SOURCE2), $(SOURCE3), and $(SOURCE4) and thier variations . 
	@echo       and writes them to $(OUT).
	@echo clean: removes temporary and immediate files.



clean:
	-rm -f $(HW8C)
	-rm -f $(HW8C)_0
	-rm -f $(HW8C)_2
	-rm -f $(HW8C)_3
	-rm -f $(HW8C)_mem
	-rm -f $(OPT1)
	-rm -f $(OPT1)_0
	-rm -f $(OPT1)_2
	-rm -f $(OPT1)_3
	-rm -f $(OPT1)_mem
	-rm -f $(OPT2)
	-rm -f $(OPT2)_0
	-rm -f $(OPT2)_2
	-rm -f $(OPT2)_3
	-rm -f $(OPT2)_mem
	-rm -f $(OPT3)
	-rm -f $(OPT3)_0
	-rm -f $(OPT3)_2
	-rm -f $(OPT3)_3
	-rm -f $(OPT3)_mem
	-rm *.o
