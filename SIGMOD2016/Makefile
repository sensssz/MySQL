filename=predictability

pdf:
	xelatex ${filename}
	bibtex ${filename}
	xelatex ${filename}
	xelatex ${filename}
	open ${filename}.pdf

clean:
	rm -f ${filename}.{ps,pdf,log,aux,out,dvi,bbl,blg}
