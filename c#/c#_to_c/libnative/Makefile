CC=gcc
CFLAGS= -Wall -O3 -fPIC
RM= rm -f

.PHONY: all clean

all: lib/libnative.so
clean:
	$(RM) *.o lib/*libnative.so

lib/libnative.so: native.o
	$(LINK.c) -shared $< -o $@

native.o:
	$(CC) $(CFLAGS) -c native.c
