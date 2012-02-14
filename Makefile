OUTPUT=lickly_masters_thesis.pdf
C_SOURCES=tryin_example.c timedloop_example.c
TEX_SOURCE=$(OUTPUT:pdf=tex)
REWRITTEN=$(C_SOURCES:.c=.rewritten.c)

all: $(OUTPUT)

$(OUTPUT): $(TEX_SOURCE) $(C_SOURCES) $(REWRITTEN)
	pdflatex -interaction=nonstopmode $<

%.rewritten.c: %.c
	$(RM) $@
	clang-cc -rewrite-pret $<
	astyle $@

clean:
	$(RM) $(REWRITTEN) $(OUTPUT) *.aux *.log
