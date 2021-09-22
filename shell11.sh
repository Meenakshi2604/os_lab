#!/bin/bash

echo Enter file
read f1

echo Enter new file
read f2

`cat < $f1 | tr 'aeiou' 'AEIOU' | cat > $f2`
echo Vowels of $f1 are converted to uppercase and result is stored in $f2
