$(FINAL_VALORES_PDF): $(VALORES_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(VALORES_BASE) $(VALORES_BASE)/slides.tex
