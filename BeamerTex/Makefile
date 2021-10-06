all: cnotes.pdf clean

cnotes.pdf: 2darrs.tex body.tex charstr.tex contypes.tex datatypes.tex defs.tex flowcontrol.tex functions.tex grammar.tex handout.tex helloworld.tex preamble.tex typeenum.tex slides.tex
	pdflatex handout.tex
	pdflatex slides.tex
	pdflatex handout.tex
	pdflatex slides.tex
	mv handout.pdf ../cnotes.pdf
	mv slides.pdf ../cnotes_slides.pdf

clean:
	rm -f *.aux *.log *.out *.toc *.nav *.vrb handout.pdf slides.pdf *.snm
