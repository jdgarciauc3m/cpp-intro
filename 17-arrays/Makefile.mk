$(FINAL_ARRAYS_PDF): $(ARRAYS_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(ARRAYS_BASE) $(ARRAYS_BASE)/slides.tex

$(FINAL_ARRAYS_EJ_PDF):	$(ARRAYS_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(ARRAYS_BASE)-ej $(ARRAYS_BASE)/hoja-ej.tex
