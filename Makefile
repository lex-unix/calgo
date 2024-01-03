CC=gcc
CFLAGS=-Wall

# 'main' depends on 'main.o'
main: main.o
	$(CC) -o main main.o

# 'main.o' depends on 'main.c'
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
