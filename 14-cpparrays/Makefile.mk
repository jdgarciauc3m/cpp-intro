$(FINAL_CPPARRAYS_PDF): $(CPPARRAYS_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(CPPARRAYS_BASE) $(CPPARRAYS_BASE)/slides.tex

$(FINAL_CPPARRAYS_EJ_PDF):	$(CPPARRAYS_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(CPPARRAYS_BASE)-ej $(CPPARRAYS_BASE)/ej/hoja-ej.tex

