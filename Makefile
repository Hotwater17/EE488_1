CC=gcc
CCFLAGS= -I.

all: main.c record.c searcher.c files.c mystrings.c
	$(CC) $(CCFLAGS) -o search main.c record.c searcher.c files.c mystrings.c -I.

clobber:
	rm -f *~ \#*\# core

clean:
	rm -f search *.o
