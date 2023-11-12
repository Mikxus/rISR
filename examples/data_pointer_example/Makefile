# 'make'        build
# 'make clean'  removes build directory

CC = avr-gcc

# compiler flags
# if avr-gcc version is < 12x
# remove the --param=min-pagesize=0
# https://gcc.gnu.org/bugzilla//show_bug.cgi?id=105523
CFLAGS = -Wall -g -O3 --param=min-pagesize=0 -Wno-misspelled-isr
BOARD = atmega328p
ADDITIONAL_FILES = ../../src/rISR.S
BUILD_DIR = build


# define the C source files
EXAMPLES = data_pointer_example.c

.PHONY: clean

all: $(EXAMPLES) $(BUILD_DIR)
	@echo  Done

$(EXAMPLES): $(BUILD_DIR)
	$(CC) -mmcu=$(BOARD) $(CFLAGS) $(ADDITIONAL_FILES) $(@) -include data_pointer_example_config.h ../../src/rISR.c -o $(BUILD_DIR)/$@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
