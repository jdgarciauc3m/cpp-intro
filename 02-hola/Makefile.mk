$(FINAL_HOLA_PDF): $(HOLA_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(HOLA_BASE) $(HOLA_BASE)/slides.tex

$(FINAL_HOLA_EJ_PDF):	$(HOLA_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(HOLA_BASE)-ej $(HOLA_BASE)/ej/hoja-ej.tex
