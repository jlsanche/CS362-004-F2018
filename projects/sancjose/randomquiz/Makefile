CC=gcc
CFLAGS=-c -Wall

all:output

output: testme.o 
	$(CC) testme.o   -o output

testme.o: testme.c
	$(CC) $(CFLAGS) testme.c

clean:
	rm *o output