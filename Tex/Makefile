all: data_structs.pdf cnotes.pdf clean


data_structs.pdf: data_structs.tex
	pdflatex data_structs.tex
	mv data_structs.pdf ..

cnotes.pdf: cnotes.tex
	pdflatex cnotes.tex
	mv cnotes.pdf ..

clean:
	rm -f *.aux *.log *.out
