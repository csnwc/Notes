CC=gcc
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90 -Werror
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS =

all: testfixed_s testrealloc_s testlinked_s testfixed_v testrealloc_v testlinked_v testfixed testrealloc testlinked

testfixed_s : coll.h Fixed/specific.h Fixed/fixed.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Fixed/fixed.c ../General/general.c -o testfixed_s -I./Fixed $(SANITIZE) $(LDLIBS)

testrealloc_s : coll.h Realloc/specific.h Realloc/realloc.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Realloc/realloc.c ../General/general.c -o testrealloc_s -I./Realloc $(SANITIZE) $(LDLIBS)

testlinked_s: coll.h Linked/specific.h Linked/linked.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Linked/linked.c ../General/general.c -o testlinked_s -I./Linked $(SANITIZE) $(LDLIBS)

testfixed_v : coll.h Fixed/specific.h Fixed/fixed.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Fixed/fixed.c ../General/general.c -o testfixed_v -I./Fixed $(VALGRIND) $(LDLIBS)

testrealloc_v : coll.h Realloc/specific.h Realloc/realloc.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Realloc/realloc.c ../General/general.c -o testrealloc_v -I./Realloc $(VALGRIND) $(LDLIBS)

testlinked_v: coll.h Linked/specific.h Linked/linked.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Linked/linked.c ../General/general.c -o testlinked_v -I./Linked $(VALGRIND) $(LDLIBS)

testfixed : coll.h Fixed/specific.h Fixed/fixed.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Fixed/fixed.c ../General/general.c -o testfixed -I./Fixed $(PRODUCTION) $(LDLIBS)

testrealloc : coll.h Realloc/specific.h Realloc/realloc.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Realloc/realloc.c ../General/general.c -o testrealloc -I./Realloc $(PRODUCTION) $(LDLIBS)

testlinked: coll.h Linked/specific.h Linked/linked.c testcoll.c ../General/general.h ../General/general.c
	$(CC) testcoll.c Linked/linked.c ../General/general.c -o testlinked -I./Linked $(PRODUCTION) $(LDLIBS)


clean:
	rm -f testfixed_s testrealloc_s testlinked_s testfixed_v testrealloc_v testlinked_v testfixed testrealloc testlinked

run: all
	./testfixed_s
	./testrealloc_s
	./testlinked_s
	valgrind --quiet ./testfixed_v
	valgrind --quiet ./testrealloc_v
	valgrind --quiet ./testfixed_v
