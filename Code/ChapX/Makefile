CC = gcc
CFLAGS = -O3 -Wall -Wextra -Wpedantic -Wfloat-equal

all: ./avx2 ./primes ./primes_no ./alin ./avx ./thread ./twiddle_bw ./twiddle_nb
	/usr/bin/time -f "%U\n" ./twiddle_bw
	/usr/bin/time -f "%U\n" ./twiddle_nb
	./alin
	/usr/bin/time -f "%U\n" ./avx
	/usr/bin/time -f "%U\n" ./avx2
	./thread
	/usr/bin/time -f "%e\n" ./primes
	/usr/bin/time -f "%e\n" ./primes_no

# aligned_alloc() issue:
# Can't use c99 for this, USE -std=c11
avx2: avx2.c
	$(CC) $(CFLAGS) -std=c11 -mavx2 -o avx2 avx2.c

avx: avx.c
	$(CC) $(CFLAGS) -std=c11        -o avx avx.c

primes: primes.c
	$(CC) $(CFLAGS) -std=c99 -fopenmp -o primes primes.c

primes_no: primes_no.c
	$(CC) $(CFLAGS) -std=c99          -o primes_no primes_no.c

thread: thread.c
	$(CC) $(CFLAGS) -std=c99 -fopenmp -o thread thread.c

alin: alin.c
	$(CC) $(CFLAGS) -std=c99 -o alin alin.c

twiddle_bw: twiddle.c
	$(CC) -O0 -std=c99 -o twiddle_bw -DBITWISE twiddle.c

twiddle_nb: twiddle.c
	$(CC) -O0 -std=c99 -o twiddle_nb           twiddle.c

clean:
	rm -f primes primes_no alin avx avx2 thread twiddle_nb twiddle_bw
