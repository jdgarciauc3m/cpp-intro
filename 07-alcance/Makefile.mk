$(FINAL_ALCANCE_PDF): $(ALCANCE_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(ALCANCE_BASE) $(ALCANCE_BASE)/slides.tex

$(FINAL_ALCANCE_EJ_PDF):	$(ALCANCE_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(ALCANCE_BASE)-ej $(ALCANCE_BASE)/ej/hoja-ej.tex

