OUTPUT=lickly_masters_thesis.pdf
C_SOURCES=tryin_example.c timedloop_example.c
TEX_SOURCE=$(OUTPUT:pdf=tex)
REWRITTEN=$(C_SOURCES:.c=.rewritten.c)
LLVMDIR=llvm-clang
CLANGCC=$(LLVMDIR)/Debug/bin/clang-cc

all: $(OUTPUT)

$(OUTPUT): $(TEX_SOURCE) $(C_SOURCES) $(REWRITTEN)
	pdflatex -interaction=nonstopmode $<

%.rewritten.c: %.c $(CLANGCC)
	$(RM) $@
	$(CLANGCC) -rewrite-pret $<
	astyle $@

$(CLANGCC): $(LLVMDIR)
	cd $(LLVMDIR) && ./configure && $(MAKE)

$(LLVMDIR):
	git clone https://github.com/blickly/llvm-clang -b insupleestyle $(LLVMDIR)

clean:
	$(RM) *.aux *.log *~ *.swp *.orig
distclean: clean
	$(RM) $(REWRITTEN) $(OUTPUT)
