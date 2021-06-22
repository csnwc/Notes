CFLAGS := -Wall -Wextra -Wvla -pedantic -std=c99 -Werror -O3
LDLIBS := -lm
SOURCES := $(wildcard *.c)
EXES := $(SOURCES:.c=)
AUTORUNS := $(wildcard *.autorun)
AUTOOUTS := $(AUTORUNS:.autorun=.autoout)
MANINPS := $(wildcard *.maninp)
MANOUTS := $(MANINPS:.maninp=.manout)

% : %.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $*
	rm -f $*.autoout $*.manout

%.autoout :
	./$* > $@

%.manout :
	@echo "Type the following:"
	@cat $*.maninp
	@script -c /home/csnwc/Lecturing/ComsM1201/Git/Notes/Code/ChapD/$* $*.script
	@cat $*.script | egrep -v "^Script " > $@
	@rm -f $*.script

all : $(EXES) $(AUTOOUTS) $(MANOUTS)

doof : 
	@echo "AUTOOUTS = " $(AUTOOUTS)
	@echo "AUTORUNS = " $(AUTORUNS)
	@echo "MANOUTS = " $(MANOUTS)
	@echo "MANRUNS = " $(MANRUNS)

clean:
	rm -f $(EXES) $(AUTOOUTS) $(MANOUTS) *.script
