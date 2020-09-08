### Compiler flags
CC = gcc
CFLAGS = -g -Wall -Werror

### Generic rule

all:	wcat

### Individual files

### The `wcat` utility
wcat:	wcat.c
	$(CC) $(CFLAGS) wcat.c -o wcat

### Clean up
clean:
	rm -f	wcat
