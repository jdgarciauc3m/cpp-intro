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
include 02-hola/Makefile.def
include 03-valores/Makefile.def
include 04-control/Makefile.def
include 05-vector/Makefile.def
include 06-errores/Makefile.def
include 07-alcance/Makefile.def
include 08-funciones/Makefile.def
include 09-clases/Makefile.def
include 10-enum/Makefile.def
include 11-operadores/Makefile.def
include 12-interfaz/Makefile.def
include 13-iostream/Makefile.def
include 14-memdin/Makefile.def

ALL_PARTS= \
$(GUIDE_PARTS) \
$(INTROCPP_PARTS) \
$(HOLA_PARTS) \
$(VALORES_PARTS) \
$(CONTROL_PARTS) \
$(VECTOR_PARTS) \
$(ERRORES_PARTS) \
$(FUNCIONES_PARTS) \
$(ALCANCE_PARTS) \
$(CLASES_PARTS) \
$(ENUM_PARTS) \
$(OPERADORES_PARTS) \
$(INTERFAZ_PARTS) \
$(IOSTREAM_PARTS) \
$(MEMDIN_PARTS) \

ALL_SLIDES_FINAL_PDF= \
$(FINAL_DIR)/$(INTROCPP_PDF) \
$(FINAL_DIR)/$(HOLA_PDF) \
$(FINAL_DIR)/$(VALORES_PDF) \
$(FINAL_DIR)/$(CONTROL_PDF) \
$(FINAL_DIR)/$(VECTOR_PDF) \
$(FINAL_DIR)/$(ERRORES_PDF) \
$(FINAL_DIR)/$(FUNCIONES_PDF) \
$(FINAL_DIR)/$(ALCANCE_PDF) \
$(FINAL_DIR)/$(CLASES_PDF) \
$(FINAL_DIR)/$(ENUM_PDF) \
$(FINAL_DIR)/$(OPERADORES_PDF) \
$(FINAL_DIR)/$(INTERFAZ_PDF) \
$(FINAL_DIR)/$(IOSTREAM_PDF) \
$(FINAL_DIR)/$(MEMDIN_PDF) \

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
	git log -1 --format=%ad --date=format:'\date{%B de %Y}' > $(BUILD_DIR)/date.tex
#	git log -1 --format=%ad --date=format:'\date{%d de %B de %Y}' > $(BUILD_DIR)/date.tex

$(FINAL_DIR):
	mkdir $(FINAL_DIR)

include $(GUIDE_BASE)/Makefile.mk
include $(INTROCPP_BASE)/Makefile.mk
include $(HOLA_BASE)/Makefile.mk
include $(VALORES_BASE)/Makefile.mk
include $(CONTROL_BASE)/Makefile.mk
include $(VECTOR_BASE)/Makefile.mk
include $(ERRORES_BASE)/Makefile.mk
include $(FUNCIONES_BASE)/Makefile.mk
include $(ALCANCE_BASE)/Makefile.mk
include $(CLASES_BASE)/Makefile.mk
include $(ENUM_BASE)/Makefile.mk
include $(OPERADORES_BASE)/Makefile.mk
include $(INTERFAZ_BASE)/Makefile.mk
include $(IOSTREAM_BASE)/Makefile.mk
include $(MEMDIN_BASE)/Makefile.mk
