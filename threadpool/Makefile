CFLAG=-c -g -pg
threadpool.o:
	gcc $(CFLAG) threadpool.c
libthreadpool.a:
	ar rc $^ threadpool.a
clean:
	rm -rf *.o *.a
