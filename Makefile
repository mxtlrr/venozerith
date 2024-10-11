CC := gcc

GIT_HASH := $(shell git describe --always --dirty --match 'NOT A TAG')
CFLAGS  := -Wall -Wextra -std=c99 -Os -g -Iinclude/ $(LDFLAGS) \
			-DGIT_HASH=\"$(GIT_HASH)\"
LDFLAGS := -lraylib -lm

TARGET := bin/venozerith
override OFILES := $(shell find ./obj/ -type f -name '*.o')
override CFILES := $(shell find ./src/ -type f -name '*.c')

all: build
.PHONY: all

build:
	@mkdir -p bin/ obj/
	@$(foreach file, $(CFILES), $(CC) $(CFLAGS) -c $(file) -o obj/$(basename $(notdir $(file))).o;echo CC $(file);)
	@gcc $(OFILES) $(LDFLAGS) -o $(TARGET)
	@echo LD $(TARGET)

clean:
	rm -rf bin/