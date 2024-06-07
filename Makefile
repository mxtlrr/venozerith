SRCS 	  := $(shell find . -type f -name '*.c')

CC 	    := gcc
CFLAGS  := -Wall -Wextra -std=c99 -Os -g
LDFLAGS := -lm -lraylib

TARGET := bin/venozerith
OBJS   := $(SRCS:.c=.o)

# Default target
all: build_dir $(TARGET)
.PHONY: all

build_dir:
	@mkdir -p bin/

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)
	@echo LD ./$(TARGET)
	@rm -f $(OBJS)

# Compile each C file
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo CC $<

clean:
	@rm -rf bin/
