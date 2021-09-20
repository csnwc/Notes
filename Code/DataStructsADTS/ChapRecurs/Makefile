CC=gcc
#CFLAGS=-Wall -Wextra -pedantic -std=c90 -O2
#CFLAGS=-Wall -Wextra -pedantic -std=c90 -lm -fsanitize=undefined -fsanitize=address -g3
CFLAGS=-Wall -Wextra -pedantic -std=c90 -lm -fsanitize=undefined -fsanitize=address -O0
LDLIBS=-lm

maze: maze.c neillsimplescreen.c neillsimplescreen.h
	$(CC) maze.c neillsimplescreen.c $(CFLAGS) -o maze $(LDLIBS)
