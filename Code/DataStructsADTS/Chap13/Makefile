CC=gcc
#CFLAGS=-Wall -Wextra -pedantic -std=c90 -O2
CFLAGS=-Wall -Wextra -pedantic -std=c90 -lm -fsanitize=undefined -fsanitize=address -g3
LDLIBS=-lm

students1 : students.c fails1.c students.h
	$(CC) students.c fails1.c -o students1 $(CFLAGS) $(LDLIBS)

students2 : students.c fails2.c students.h
	$(CC) students.c fails2.c -o students2 $(CFLAGS) $(LDLIBS)
