$(FINAL_OPERADORES_PDF): $(OPERADORES_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(OPERADORES_OUT) $(OPERADORES_BASE)/slides.tex
