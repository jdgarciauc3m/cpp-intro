$(FINAL_DEFTIPOS_PDF): $(DEFTIPOS_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(DEFTIPOS_OUT) $(DEFTIPOS_BASE)/slides.tex
