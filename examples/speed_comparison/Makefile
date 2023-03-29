# 'make'        build executable file 'mycc'
# 'make clean'  removes build directory

CC = avr-gcc

# compiler flags
# if avr-gcc version is < 12x
# remove the --param=min-pagesize=0
# https://gcc.gnu.org/bugzilla//show_bug.cgi?id=105523
CFLAGS = -Wall -g -O3 --param=min-pagesize=0
BOARD = atmega328p
BUILD_DIR = build


# define the C source files
EXAMPLES = dynamic.c fast_dynamic.c hard_coded.c

.PHONY: clean

all: dynamic.c fast_dynamic.c hard_coded.c
	@echo  Speed comparisons compiled

dynamic.c: $(BUILD_DIR)
	$(CC) -mmcu=$(BOARD) $(CFLAGS) $@  -include dynamic_config.h ../../src/rISR.c ../../src/rISR.S -o $(BUILD_DIR)/dynamic.o

fast_dynamic.c: $(BUILD_DIR)
	$(CC) -mmcu=$(BOARD) $(CFLAGS) $@  -include fast_dynamic_config.h ../../src/rISR.c ../../src/rISR.S -o $(BUILD_DIR)/fast_dynamic.o

hard_coded.c: $(BUILD_DIR)
	$(CC) -mmcu=$(BOARD) $(CFLAGS) $@ -o $(BUILD_DIR)/hard_coded.o

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
