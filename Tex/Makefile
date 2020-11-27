all: data_structs.pdf cnotes.pdf move clean


data_structs.pdf: data_structs.tex
	pdflatex data_structs.tex

cnotes.pdf: cnotes.tex
	pdflatex cnotes.tex

move:
	mv data_structs.pdf ..
	mv cnotes.pdf ..
	
clean:
	rm -f *.aux *.log *.out
