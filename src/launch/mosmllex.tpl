#!/bin/rc

stdlib=LIBDIR
mosmlbin=BINDIR

while(){
	switch($1){
	case ''
		exec $mosmlbin/camlrunm $stdlib/mosmllex
	case -*
		echo 'unknown option '^$1^'; ignored' >[1=2]
	case *
		exec $mosmlbin/camlrunm $stdlib/mosmllex $*
	}
	shift
}
