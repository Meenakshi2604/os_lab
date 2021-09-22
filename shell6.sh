#!/bin/bash

if [ $# = 1 ]
	then
		[ -f $! ] && echo $1 exists || echo $1 doesn\'t exist
elif [ $# = 2 ]
	then
		if [ $1 == $2 ] 
			then
			 echo "Both are same files"
			 exit
		fi
		[ -f $1 ] && echo `mv $1 $2` $1 successfully renamed to $2 || echo $1 doesn\'t exist
else
	echo No of parameters = $# \(Should be 1 or 2\)
fi	
