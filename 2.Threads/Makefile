all:
	gcc -o 1.signal.out 1.signal.c
	gcc -o 2.signal.out 2.signal.c
	gcc -o 3.sigaction.out 3.sigaction.c
	cc -D_REENTRANT -I/usr/include/nptl 4.thread.c -o 4.thread.out -L/usr/lib/nptl -lpthread
clean:
	rm -rf *.out

