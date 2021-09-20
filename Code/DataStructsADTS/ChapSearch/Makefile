CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c90 -O2
#CFLAGS=-Wall -Wextra -pedantic -std=c90 -lm -fsanitize=undefined -fsanitize=address -g3
LDLIBS=-lm

seqsearch: seqsearch.c
	$(CC) seqsearch.c -o seqsearch $(CFLAGS) $(LDLIBS)

seqsearch2: seqsearch2.c
	$(CC) seqsearch2.c -o seqsearch2 $(CFLAGS) $(LDLIBS)

binsearch_it: binsearch_it.c
	$(CC) binsearch_it.c -o binsearch_it $(CFLAGS) $(LDLIBS)

binsearch_rec: binsearch_rec.c
	$(CC) binsearch_rec.c -o binsearch_rec $(CFLAGS) $(LDLIBS)

interp:	interp.c
	$(CC) interp.c -o interp $(CFLAGS) $(LDLIBS)

clean:	
	rm -fr binsearch_rec binsearch_it interp seqsearch seqsearch2
