$(FINAL_VALORES_PDF): $(VALORES_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(VALORES_BASE) $(VALORES_BASE)/slides.tex

$(FINAL_VALORES_EJ_PDF):	$(VALORES_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(VALORES_BASE)-ej $(VALORES_BASE)/ej/hoja-ej.tex
