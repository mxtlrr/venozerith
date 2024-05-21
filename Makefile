CC := gcc
CFLAGS := -lraylib -lm -Os -g

all: clean venozerith
.PHONY: all

clean:
	rm -rf bin/

venozerith:
	mkdir -p bin/
	$(CC) src/main.c $(CFLAGS) -o bin/venozerith