$(FINAL_INTERFAZ_PDF): $(INTERFAZ_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(INTERFAZ_BASE) $(INTERFAZ_BASE)/slides.tex

$(FINAL_INTERFAZ_EJ_PDF):	$(INTERFAZ_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(INTERFAZ_BASE)-ej $(INTERFAZ_BASE)/hoja-ej.tex

