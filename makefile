CC=gcc
CFLAGS=-std=c99 -g3 -pedantic -Wall -Wextra

hw5: hw5.o catalog.o prompts.o
	$(CC) -o hw5 hw5.o catalog.o prompts.o

hw5.o: hw5.c catalog.h prompts.h
	$(CC) $(CFLAGS) -c hw5.c

catalog.o: catalog.c catalog.h
	$(CC) $(CFLAGS) -c catalog.c

prompts.o: prompts.c prompts.h
	$(CC) $(CFLAGS) -c prompts.c

clean:
	rm -f *.o hw5
