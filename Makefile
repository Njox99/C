CC = gcc
CFLAGS = -Wall -Wextra -g
CFILENAME = main.c
CBUILDFILE = main

main.c: main
	$(CC) -o $(CBUILDFILE) $(CFLAGS)

run:
	./CBUILDFILE

clean:
	rm -rf a.out $(CBUILDFILE) main.o
