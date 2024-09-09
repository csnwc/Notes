CC=gcc
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90 -Werror
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS =

all: ll_s ll_v ll

ll_s: llist.c general.h general.c
	$(CC) llist.c general.c -o ll_s $(SANITIZE) $(LDLIBS)

ll_v: llist.c general.h general.c
	$(CC) llist.c general.c -o ll_v $(VALGRIND) $(LDLIBS)

ll: llist.c general.h general.c
	$(CC) llist.c general.c -o ll $(PRODUCTION) $(LDLIBS)


clean:
	rm -f ll_s ll_v ll

run: all
	valgrind ./ll_v < testinput.txt
