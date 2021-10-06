CC := clang
CCWARNS = -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla
CFLAGNOABORT := $(CCWARNS) -std=c99 -O1
CFLAGS := $(CFLAGNOABORT) -Werror
LDLIBS := -lm
SOURCES := $(wildcard *.c)
EXES := $(SOURCES:.c=)
AUTORUNS := $(wildcard *.autorun)
AUTOOUTS := $(AUTORUNS:.autorun=.autoout)
MANINPS := $(wildcard *.maninp)
MANOUTS := $(MANINPS:.maninp=.manout)

all : $(EXES) $(AUTOOUTS) $(MANOUTS)

mult : mult.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

fvr : fvr.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

nify2 : nify2.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout


% : %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

%.autoout :
	./$* > $@

%.manout :
	@echo "\nType the following:"
	@cat $*.maninp
	@echo
	@script -c ./$* $*.script
	@cat $*.script | egrep -v "^Script " > $@
	@rm -f $*.script


debugmake : 
	@echo "SOURCES = " $(SOURCES)
	@echo "EXES = " $(EXES)
	@echo "AUTOOUTS = " $(AUTOOUTS)
	@echo "AUTORUNS = " $(AUTORUNS)
	@echo "MANOUTS = " $(MANOUTS)
	@echo "MANRUNS = " $(MANRUNS)

clean:
	rm -f $(EXES) $(AUTOOUTS) $(MANOUTS) *.script
