DIRS=src

default:V: all

all clean nuke install installall:V:
	for(i in $DIRS) @{
		cd $i
		mk $target
		cd ..
	}

