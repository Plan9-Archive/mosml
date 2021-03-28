PERL=perl
MOSMLL=aux/camlrunm /sys/lib/mosml/mosmllnk -stdlib /sys/lib/mosml -P none
MOSMLLEX=aux/camlrunm /sys/lib/mosml/mosmllex
MOSMLYACC=aux/mosmlyac
MOSMLCUT=aux/camlrunm /sys/lib/mosml/cutdeps 
MOSMLDEP=aux/camlrunm /sys/lib/mosml/mosmldep
MOSMLC=aux/camlrunm /sys/lib/mosml/mosmlcmp -stdlib /sys/lib/mosml -P none

# to test current compiler
# MOSMLC=aux/camlrunm ../compiler/mosmlcmp -stdlib . -P none

%.ui:D: %.sig
	$MOSMLC $COMPFLAGS $stem.sig

%.uo:D: %.sml
	$MOSMLC $COMPFLAGS $stem.sml

%.sml:D: %.mlp
	tr '''' '␣' < $prereq | cpp -Dunix -Dplan9 |tr '␣' '''' |grep -v '^#line' >$target

%.sml:D: %.lex
	$MOSMLLEX $stem.lex

%.sml %.sig:D: %.grm
	$MOSMLYACC $stem.grm

CAMLRT=/sys/src/cmd/mosml/src/runtime
MOSMLTOOLS=/sys/src/cmd/mosml/src/tools

LIBDIR=/sys/lib/mosml

# crummy hack: % keeps it from being default target
installall%:V:
	for(objtype in $CPUS)
		mk install
