# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: Sort

Sort: Sort.o
	$(CC) Sort.o -o Sort

Sort.o: Sort.cpp
	$(CC) $(CFLAGS) Sort.cpp

clean:
	rm -rf *o hello
