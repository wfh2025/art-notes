PROJ_DIR 	:= $(CURDIR)
RM 			:= rm -f

XELATEX :=latexmk -r $(PROJ_DIR)/latexmkrc -xelatex

IGNORE = \
	*.aux \
	*/*.aux \
	*.bbl \
	*.bbl-SAVE-ERROR \
	*.fls \
	*.lol \
	*.listing

all: main.pdf

%.pdf: %.tex FORCE_MAKE
	$(XELATEX) -g -silent $<
view: main.tex
	$(XELATEX) -pv -silent -time $<
pvc: main.tex
	$(XELATEX) -pvc -silent $<
debug: debug.tex
	$(XELATEX) -pvc -silent $<
bug:
	grep -inr -C 5 'LaTeX Error' *.log
clean: 
	latexmk -r $(PROJ_DIR)/latexmkrc -C && $(RM) $(IGNORE)
print-%:
	@echo $* = $($*)
.PHONY: all install view clean bug FORCE_MAKE
