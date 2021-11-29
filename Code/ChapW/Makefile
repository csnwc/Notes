CC := clang
CWARNS := -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla
CFLAGNOABORT := $(CWARNS) -std=c99 -O3
CFLAGS := $(CFLAGNOABORT) -Werror
LDLIBS := -lm
SOURCES := $(wildcard *.c)
EXES := $(SOURCES:.c=)
AUTORUNS := $(wildcard *.autorun)
AUTOOUTS := $(AUTORUNS:.autorun=.autoout)
MANINPS := $(wildcard *.maninp)
MANOUTS := $(MANINPS:.maninp=.manout)
GENC := ../../../ADTs/General/general.c

all : $(EXES) $(AUTOOUTS) $(MANOUTS)

power : power.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

mult : mult.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

fvr : fvr.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

nify2 : nify2.c
	$(CC) $(CFLAGSNOABORT) $< $(LDLIBS) -o $@
	rm -f $@.autoout $@.manout

llist: llist.c $(GENC)
	$(CC) $(CFLAGS) $< $(GENC) $(LDLIBS) -o $@

llist2: llist2.c $(GENC)
	$(CC) $(CFLAGS) $< $(GENC) ../../../ADTs/Collection/Fixed/fixed.c  -I../../../ADTs/Collection $(LDLIBS) -o $@


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
	@echo "CWARNS = " $(CWARNS)
	@echo "CFLAGS = " $(CFLAGS)
	@echo "CFLAGSNOABORT = " $(CFLAGSNOABORT)
	@echo "SOURCES = " $(SOURCES)
	@echo "EXES = " $(EXES)
	@echo "AUTOOUTS = " $(AUTOOUTS)
	@echo "AUTORUNS = " $(AUTORUNS)
	@echo "MANOUTS = " $(MANOUTS)
	@echo "MANRUNS = " $(MANRUNS)

clean:
	rm -f $(EXES) $(AUTOOUTS) $(MANOUTS) *.script
