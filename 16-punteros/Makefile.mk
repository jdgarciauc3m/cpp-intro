$(FINAL_PUNTEROS_PDF): $(PUNTEROS_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(PUNTEROS_BASE) $(PUNTEROS_BASE)/slides.tex

$(FINAL_PUNTEROS_EJ_PDF):	$(PUNTEROS_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(PUNTEROS_BASE)-ej $(PUNTEROS_BASE)/hoja-ej.tex
