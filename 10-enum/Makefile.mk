$(FINAL_ENUM_PDF): $(ENUM_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(ENUM_BASE) $(ENUM_BASE)/slides.tex
