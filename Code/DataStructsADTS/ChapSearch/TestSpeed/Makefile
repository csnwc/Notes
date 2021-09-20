CC=gcc
#CFLAGS=-Wall -Wextra -pedantic -std=c90 -O2
CFLAGS=-Wall -Wextra -pedantic -std=c90 -lm -fsanitize=undefined -fsanitize=address -g3
LDLIBS=-lm

test: test_bin_it test_bin_rec test_interp

test_bin_it: time_srch
	@ echo "Binary Search : Iterative "
	@ echo -n "n =    100000 = "
	@ /usr/bin/time --format "%U" ./time_srch 100000 0
	@ echo -n "n =    800000 = "
	@ /usr/bin/time --format "%U" ./time_srch 800000 0
	@ echo -n "n =   6400000 = "
	@ /usr/bin/time --format "%U" ./time_srch 6400000 0
	@ echo -n "n =  51200000 = "
	@ /usr/bin/time --format "%U" ./time_srch 51200000 0

test_bin_rec: time_srch
	@ echo "Binary Search : Recursive"
	@ echo -n "n =    100000 = "
	@ /usr/bin/time --format "%U" ./time_srch 100000 1
	@ echo -n "n =    800000 = "
	@ /usr/bin/time --format "%U" ./time_srch 800000 1
	@ echo -n "n =   6400000 = "
	@ /usr/bin/time --format "%U" ./time_srch 6400000 1
	@ echo -n "n =  51200000 = "
	@ /usr/bin/time --format "%U" ./time_srch 51200000 1

test_interp: time_srch
	@ echo "Interpolation"
	@ echo -n "n =    100000 = "
	@ /usr/bin/time --format "%U" ./time_srch 100000 2
	@ echo -n "n =    800000 = "
	@ /usr/bin/time --format "%U" ./time_srch 800000 2
	@ echo -n "n =   6400000 = "
	@ /usr/bin/time --format "%U" ./time_srch 6400000 2
	@ echo -n "n =  51200000 = "
	@ /usr/bin/time --format "%U" ./time_srch 51200000 2

time_srch: time_srch.c
	$(CC) time_srch.c -o time_srch $(CFLAGS) $(LDLIBS)
