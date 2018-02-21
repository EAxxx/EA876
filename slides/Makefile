
PDFLATEX = pdflatex
BIBTEX = bibtex
SRCS := $(shell find ./ -name '*.tex')
SLIDES_PDF = $(SRCS:.tex=.pdf)

DOTSRC := $(shell find ./dot -name '*.dot')
DOTPDF = $(DOTSRC:.dot=.pdf)
DOT = dot

FIGDIR = ./fig/
FIGS := $(shell find $(FIGFIR) -name '*.*')

all:$(DOTPDF) $(SLIDES_PDF)

$(DOTPDF):$(DOTSRC)
	$(DOT) -Tpdf < $(@:.pdf=.dot) > $@

$(SLIDES_PDF):$(SRCS)
	$(PDFLATEX) $(@:.pdf=.tex)

clean:
	rm *.aux *.log *.nav *.out *.snm $(DOTPDF)
