CC=gcc
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90 -Werror
DEBUG= -g3
SANITIZE= -fsanitize=undefined -fsanitize=address
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS=

all: testfixed testfixed_s testfixed_v testlinked testlinked_s testlinked_v pdfs simslow

testfixed: queue.h Fixed/specific.h Fixed/fixed.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Fixed/fixed.c ../General/general.c -o testfixed -I./Fixed $(PRODUCTION) $(LDLIBS)

testlinked: queue.h Linked/specific.h Linked/linked.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Linked/linked.c ../General/general.c -o testlinked -I./Linked $(PRODUCTION) $(LDLIBS)

testfixed_s: queue.h Fixed/specific.h Fixed/fixed.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Fixed/fixed.c ../General/general.c -o testfixed_s -I./Fixed $(SANITIZE) $(LDLIBS)

testlinked_s: queue.h Linked/specific.h Linked/linked.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Linked/linked.c ../General/general.c -o testlinked_s -I./Linked $(SANITIZE) $(LDLIBS)

testfixed_v: queue.h Fixed/specific.h Fixed/fixed.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Fixed/fixed.c ../General/general.c -o testfixed_v -I./Fixed $(VALGRIND) $(LDLIBS)

testlinked_v: queue.h Linked/specific.h Linked/linked.c testqueue.c ../General/general.h ../General/general.c
	$(CC) testqueue.c Linked/linked.c ../General/general.c -o testlinked_v -I./Linked $(VALGRIND) $(LDLIBS)


simslow: queue.h Fixed/specific.h Fixed/fixed.c simslow.c ../General/general.h ../General/general.c
	$(CC) simslow.c Fixed/fixed.c ../General/general.c -o simslow -I./Fixed $(SANITIZE) $(LDLIBS)




clean:
	rm -f testfixed testfixed_s testfixed_v testlinked testlinked_s testlinked_v Linkedq.dot Fixedq.dot Fixedq.pdf Linkedq.pdf simslow 

run: all
	./testfixed_s
	valgrind --quiet ./testfixed_v
	./testlinked_s
	valgrind --quiet ./testlinked_v
































DOT := $(shell command -v dot 2> /dev/null)

Fixedq.dot : testfixed
	./testfixed

Linkedq.dot : testlinked
	./testlinked

Fixedq.pdf: Fixedq.dot testqueue.c testfixed Fixedq.dot
ifndef DOT
    $(error "dot is not available please install graphviz")
endif
	dot -Tpdf -o Fixedq.pdf Fixedq.dot 
Linkedq.pdf: Linkedq.dot testqueue.c testlinked Linkedq.dot
ifndef DOT
    $(error "dot is not available please install graphviz")
endif
	dot -Tpdf -o Linkedq.pdf Linkedq.dot 

pdfs:	Fixedq.pdf Linkedq.pdf
