$(FINAL_SMARTPTR_PDF): $(SMARTPTR_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(SMARTPTR_BASE) $(SMARTPTR_BASE)/slides.tex

$(FINAL_SMARTPTR_EJ_PDF):	$(SMARTPTR_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(SMARTPTR_BASE)-ej $(SMARTPTR_BASE)/hoja-ej.tex
