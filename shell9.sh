#!/bin/bash

if [ $# != 3 ]; then
	echo Less arguments given
	exit
fi
`head $1 | cat > $3`
`head $1 | cat >> $3`
echo Successfull copied first 10 lines form $1 and $2 to $3
