all: ../cnotes.pdf ../cnotes_slides.pdf ../datastructs.pdf ../datastructs_slides.pdf

../cnotes.pdf: 2darrs.tex cnotes_body.tex str.tex contypes.tex datatypes.tex cnotes_defs.tex flowcontrol.tex functions.tex grammar.tex cnotes_handout.tex helloworld.tex preamble.tex typeenum.tex files.tex advmem.tex
	pdflatex cnotes_handout.tex
	pdflatex cnotes_handout.tex
	mv cnotes_handout.pdf ../cnotes.pdf
	rm -f *.aux *.log *.out *.toc *.nav *.vrb cnotes*.pdf datastructs*.pdf *.snm

../cnotes_slides.pdf: 2darrs.tex cnotes_body.tex str.tex contypes.tex datatypes.tex cnotes_defs.tex flowcontrol.tex functions.tex grammar.tex helloworld.tex preamble.tex typeenum.tex cnotes_slides.tex files.tex advmem.tex
	pdflatex cnotes_slides.tex
	pdflatex cnotes_slides.tex
	mv cnotes_slides.pdf ..
	rm -f *.aux *.log *.out *.toc *.nav *.vrb cnotes*.pdf datastructs*.pdf *.snm

../datastructs.pdf: recurs.tex datastructs_body.tex datastructs_defs.tex datastructs_handout.tex algossearch.tex linked.tex adts_coll.tex adts_stacks.tex adts_queues.tex adts_trees.tex adts_hashing.tex adts_graphs.tex algos_sortstringgraph.tex algos_parsing.tex
	pdflatex datastructs_handout.tex
	pdflatex datastructs_handout.tex
	mv datastructs_handout.pdf ../datastructs.pdf
	rm -f *.aux *.log *.out *.toc *.nav *.vrb cnotes*.pdf datastructs*.pdf *.snm

../datastructs_slides.pdf: recurs.tex datastructs_body.tex datastructs_defs.tex datastructs_slides.tex algossearch.tex linked.tex adts_coll.tex adts_stacks.tex adts_queues.tex adts_trees.tex adts_hashing.tex adts_graphs.tex algos_sortstringgraph.tex algos_parsing.tex
	pdflatex datastructs_slides.tex
	pdflatex datastructs_slides.tex
	mv datastructs_slides.pdf ..
	rm -f *.aux *.log *.out *.toc *.nav *.vrb cnotes*.pdf datastructs*.pdf *.snm

clean:
	rm -f *.aux *.log *.out *.toc *.nav *.vrb cnotes*.pdf datastructs*.pdf *.snm
