CC=gcc
CFLAGS=-O3 -fPIC
DEPS=my_malloc.h

all: lib

lib: my_malloc.o
	$(CC) $(CFLAGS) -shared -o libmymalloc.so my_malloc.o

my_malloc.o: my_malloc.c $(DEPS)
	$(CC) $(CFLAGS) -c -o my_malloc.o my_malloc.c 

clean:
	rm -f *~ *.o *.so

clobber:
	rm -f *~ *.o
