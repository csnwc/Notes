CC := gcc
CNOABORTFLAGS := -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla -std=c99 -O1
CFLAGS := $(CNOABORTFLAGS) -Werror
LDLIBS := -lm
SOURCES := $(wildcard *.c)
EXES := $(SOURCES:.c=)

all : $(EXES)

nify2 : nify2.c
	$(CC) $(CNOABORTFLAGS) $< $(LDLIBS) -o $@

% : %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

clean:
	rm -f $(EXES)
