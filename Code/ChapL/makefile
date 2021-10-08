CC := gcc
CNOVLAFLAGS := -Wall -Wpedantic -Wextra -Wfloat-equal -std=c99 -O1
CNOABORTFLAGS := $(CNOVLAFLAGS) -Wvla
CFLAGS := $(CNOABORTFLAGS) -Werror
LDLIBS := -lm
SOURCES := $(wildcard *.c)
EXES := $(SOURCES:.c=)

all : $(EXES)

strdup1 : strdup1.c
	$(CC) $(CNOVLAFLAGS) -Werror $< $(LDLIBS) -o $@

nify2 : nify2.c
	$(CC) $(CNOABORTFLAGS) $< $(LDLIBS) -o $@

% : %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

clean:
	rm -f $(EXES)
