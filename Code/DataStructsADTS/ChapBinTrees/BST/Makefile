CFLAGS = -Wall -Wextra -Werror -Wfloat-equal -pedantic -ansi
INCS = bst.h

all: testbst testbst_d

testbst:  bst.c testbst.c $(INCS)
	$(CC) bst.c testbst.c -o testbst -O3 $(CFLAGS)

testbst_d:  bst.c testbst.c $(INCS)
	$(CC) bst.c testbst.c -o testbst_d -g -fsanitize=undefined -O $(CFLAGS)

run: all
	./testbst

memchk: testbst_d
	valgrind --error-exitcode=1 --quiet --leak-check=full testbst_d

clean:
	rm -f testbst testbst_d

.PHONY: clean run memchk all
