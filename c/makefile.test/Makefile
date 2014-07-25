CC = gcc
WKDIR=/da1/zhanglanyun/c/makefile.test
CFLAGS=-DLINUX -ansi -I$(WKDIR)/include -Wall -D_GNU_SOURCE $(EXTRA)
OBJECTS = mmap.o
AR = ar
lib = mmap.a
all: ${OBJECTS}
	$(AR) rv ${lib} $?
	
clean:
	rm -f *.o *.a
