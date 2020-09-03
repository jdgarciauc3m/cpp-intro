BUILD_DIR= build
FINAL_DIR= final

LATEXMK=latexmk -pdf -file-line-error -halt-on-error -outdir=$(FINAL_DIR) 

CONFIG_INPUT=config/config-lst.tex \
	     config/config-tc.tex \
	     config/footline.tex \
	     config/packages.tex \
	     $(BUILD_DIR)/date.tex

LOGOS=\
logos/arcos.png \
logos/logo-uc3m.jpg 

include guide/Makefile.def
include 01-introcpp/Makefile.def
include 02-valores/Makefile.def

ALL_PARTS= \
$(GUIDE_PARTS) \
$(INTROCPP_PARTS) \
$(VALORES_PARTS) \

ALL_SLIDES_FINAL_PDF= \
$(FINAL_DIR)/$(INTROCPP_PDF) \
$(FINAL_DIR)/$(VALORES_PDF) \

ALL_FINAL_PDF=\
$(FINAL_DIR) \
$(ALL_SLIDES_FINAL_PDF) \
$(GUIDE_FINAL_PDF) \

all:	$(ALL_FINAL_PDF)

clean:
	rm -Rf $(BUILD_DIR)
	rm -Rf $(FINAL_DIR)

build:
	mkdir $(BUILD_DIR)

updatevers:	$(BUILD_DIR)
	git log -1 --format=%ad --date=format:'\date{%d de %B de %Y}' > $(BUILD_DIR)/date.tex

$(FINAL_DIR):
	mkdir $(FINAL_DIR)

include guide/Makefile.mk
include 01-introcpp/Makefile.mk
include 02-valores/Makefile.mk
