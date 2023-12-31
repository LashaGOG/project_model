# AUTHORS : TAN Philippe
#           GOGRITCHIANI Lasha
#           CHEN Virginie

# declaration of variables
CC = gcc
CCFLAGS = -g -Wall -Wextra -c
COFLAGS = -g -Wall -Wextra -o
PROGRAMS = main

# source and Object directories
SRC_DIR = src
OBJ_DIR = bin
INCLUDE_DIR = include

# automatically collect all C source files and corresponding object files
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# default rule
all: prepare $(PROGRAMS)

# create bin directory
prepare:
	@[ -d $(OBJ_DIR) ] || mkdir -p $(OBJ_DIR)

# main program rule
$(PROGRAMS): $(OBJECTS)
	$(CC) $(COFLAGS) $@ $^ -lm

# generic rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(PROGRAMS)
