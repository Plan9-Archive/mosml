# Unix Makefile for lexyacc example

MOSMLHOME=${HOME}/mosml
MOSMLTOOLS=camlrunm $(MOSMLHOME)/tools
MOSMLC=mosmlc -c
MOSMLL=mosmlc
MOSMLLEX=mosmllex
MOSMLYACC=mosmlyac

all: Data.uo Lexer.uo Main.uo Parser.uo
	mosml load

Parser.sml Parser.sig: Parser.grm
	$(MOSMLYACC) Parser.grm

.SUFFIXES :
.SUFFIXES : .sml .sig .ui .uo .mlp .lex .c .o

.sig.ui:
	$(MOSMLC) $<

.sml.uo:
	$(MOSMLC) $<

.lex.sml:
	$(MOSMLLEX) $<

depend: Lexer.sml Parser.sml 
	rm -f Makefile.bak
	mv Makefile Makefile.bak
	$(MOSMLTOOLS)/cutdeps < Makefile.bak > Makefile
	$(MOSMLTOOLS)/mosmldep >> Makefile

clean:
	rm -f Parser.sig Parser.sml Lexer.sml
	rm -f *.ui *.uo
	rm -f Makefile.bak

### DO NOT DELETE THIS LINE
Parser.ui: Data.uo 
Parser.uo: Parser.ui Data.uo 
Lexer.uo: Parser.ui 
Main.uo: Parser.ui Lexer.uo 
