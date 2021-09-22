#!/bin/bash

if [ $# != 2 ]
	then
		echo No of strings must be 2
else
	test $1 = $2 && echo "Strungs are equal" || echo "Strings are not equal"
fi
