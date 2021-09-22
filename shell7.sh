#!/bin/bash

echo Enter filename
read FILE
if test -f $FILE; then
	echo Enter string to be searched
	read str
	grep -q $str $FILE && echo $str fount in $FILE || echo $str not found in $FILE
else
	echo $FILE doesn\'t exist
	exit 1
fi

