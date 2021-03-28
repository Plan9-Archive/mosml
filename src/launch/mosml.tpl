#!/bin/rc

stdlib=LIBDIR
mosmlbin=BINDIR
includes=()
options=(-conservative)

while() {
	switch($1) {
	case ''
		exec $mosmlbin/camlrunm $stdlib/mosmltop -stdlib $stdlib $includes $options
	case -I -include
		includes=($includes -I $2)
		shift
	case -P -perv
		options=($options -P $2)
		shift
	case -m -msgstyle
		options=($options -m $2)
		shift
	case -orthodox -conservative -liberal -imptypes -quietdec -valuepoly
		options=($options $1)
	case -stdlib
		stdlib=$2
		shift
	case -*
		echo 'unknown option '^$1^'; ignored' >[1=2]
	case *
		exec $mosmlbin/$camlrunm $stdlib/mosmltop -stdlib $stdlib $includes $options $*
	}
	shift
}

