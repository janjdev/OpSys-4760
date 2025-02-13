CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -ggdb

all: oss user

.SUFFIXES: .c .o

oss: oss.c
	$(CC) $(CFLAGS) -o oss oss.c

user: user.c
	$(CC) $(CFLAGS) -o user user.c

.c.o:
	gcc -ggdb -g -c $<

.PHONY: clean
clean:
	/bin/rm -f oss user *.o