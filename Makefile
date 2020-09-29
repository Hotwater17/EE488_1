all: main.c record.c searcher.c files.c mystrings.c
	gcc -o search main.c record.c searcher.c files.c mystrings.c -I.

clobber:
	rm -f *~ \#*\# core

clean:
	rm -f search *.o
