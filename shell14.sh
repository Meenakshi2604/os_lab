#!/bin/bash

read -p "Enter n = " n
sum=0
if [ 0 -gt $n ]; then
	echo Negative number entered. Cannot find the sum
	exit
fi

for (( i=1; i<=$n; i++ )) do
	sum=`expr $sum + $i`
done
echo Sum of first $n integers = $sum
