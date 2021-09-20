CC=gcc
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90 -Werror
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS =

all: testrealloc_s testrealloc_v testrealloc testlinked testlinked_s testlinked_v revstr_realloc revstr_linked pdfs

testrealloc : stack.h Realloc/specific.h Realloc/realloc.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Realloc/realloc.c ../General/general.c -o testrealloc -I./Realloc $(PRODUCTION) $(LDLIBS)

testlinked: stack.h Linked/specific.h Linked/linked.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Linked/linked.c ../General/general.c -o testlinked -I./Linked $(PRODUCTION) $(LDLIBS)

testrealloc_s : stack.h Realloc/specific.h Realloc/realloc.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Realloc/realloc.c ../General/general.c -o testrealloc_s -I./Realloc $(SANITIZE) $(LDLIBS)

testlinked_s: stack.h Linked/specific.h Linked/linked.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Linked/linked.c ../General/general.c -o testlinked_s -I./Linked $(SANITIZE) $(LDLIBS)

testrealloc_v : stack.h Realloc/specific.h Realloc/realloc.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Realloc/realloc.c ../General/general.c -o testrealloc_v -I./Realloc $(VALGRIND) $(LDLIBS)

testlinked_v: stack.h Linked/specific.h Linked/linked.c teststack.c ../General/general.h ../General/general.c
	$(CC) teststack.c Linked/linked.c ../General/general.c -o testlinked_v -I./Linked $(VALGRIND) $(LDLIBS)



revstr_linked : revstr.c stack.h Linked/specific.h Linked/linked.c ../General/general.h ../General/general.c
	$(CC) revstr.c Linked/linked.c ../General/general.c -o revstr_linked -I./Linked $(SANITIZE) $(LDLIBS)

revstr_realloc : revstr.c stack.h Realloc/specific.h Realloc/realloc.c ../General/general.h ../General/general.c
	$(CC) revstr.c Realloc/realloc.c ../General/general.c -o revstr_realloc -I./Realloc $(SANITIZE) $(LDLIBS)



clean:
	rm -f testrealloc_s testrealloc_v testrealloc testlinked testlinked_s testlinked_v Linkeds.dot Linkeds.pdf Reallocs.dot Reallocs.pdf revstr_realloc revstr_linked

run: all
	./testrealloc_s
	./testlinked_s
	valgrind ./testrealloc_v
	valgrind ./testlinked_v

































DOT := $(shell command -v dot 2> /dev/null)

Linkeds.dot:  testlinked
	./testlinked
Reallocs.dot: testrealloc
	./testrealloc

Linkeds.pdf:  teststack.c testlinked Linkeds.dot
ifndef DOT
    $(error "dot is not available please install graphviz")
endif
	dot -Tpdf -o Linkeds.pdf Linkeds.dot
Reallocs.pdf:  teststack.c testrealloc Reallocs.dot
ifndef DOT
    $(error "dot is not available please install graphviz")
endif
	dot -Tpdf -o Reallocs.pdf Reallocs.dot

pdfs : Linkeds.pdf Reallocs.pdf
