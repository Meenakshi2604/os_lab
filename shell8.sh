#!/bin/bash

echo Enter file 1
read f1
if [ -f $f1 ]; then
	echo Enter file 2
	read f2
	`cat >> $f2 $f1`
	echo $f1 successfully copied to $f2
else
	echo $f1 doesn\'t exist
fi
	 
