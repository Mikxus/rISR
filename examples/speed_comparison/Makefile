# 'make'        build executable file 'mycc'
# 'make clean'  removes build directory


CC = avr-gcc

# compiler flags
# if avr-gcc version is < 12x
# remove the --param=min-pagesize=0
# https://gcc.gnu.org/bugzilla//show_bug.cgi?id=105523
CFLAGS = -Wall -g -O3 --param=min-pagesize=0
BOARD = atmega328p
INCLUDES = ../../src/rISR.S
BUILD_DIR = build


# define the C source files
EXAMPLES = dynamic.c fast_dynamic.c hard_coded.c

.PHONY: clean

all: $(EXAMPLES) $(BUILD_DIR)
	@echo  Speed comparisons compiled

$(EXAMPLES): $(BUILD_DIR)
	$(CC) -mmcu=$(BOARD) $(CFLAGS) $(INCLUDES) $(@) -o $(BUILD_DIR)/$@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
