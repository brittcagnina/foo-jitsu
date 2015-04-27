CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

all: fj 

fj: fj.c core.c 
	$(CC) $^ -o fj 

clean:
	rm -rf *o fj 
