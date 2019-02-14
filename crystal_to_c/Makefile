CC=gcc
CFLAGS=-I.

mainmake: main.o
	$(CC) -c main.c -o main.o
	crystal build main.cr

clean:
	rm -f ./*.o main