CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -ggdb

all: oss worker

.SUFFIXES: .c .o

oss: oss.c
	$(CC) $(CFLAGS) -o oss oss.c

user: worker.c
	$(CC) $(CFLAGS) -o worker worker.c

.c.o:
	gcc -ggdb -g -c $<

.PHONY: clean
clean:
	/bin/rm -f oss worker *.o