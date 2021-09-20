all: data_structs.pdf cnotes.pdf move clean


data_structs.pdf: data_structs.tex trees.tex hashing.tex graphs.tex algos2.tex summary.tex
	pdflatex data_structs.tex

cnotes.pdf: cnotes.tex
	pdflatex cnotes.tex

move:
	mv data_structs.pdf ..
	mv cnotes.pdf ..
	
clean:
	rm -f *.aux *.log *.out
