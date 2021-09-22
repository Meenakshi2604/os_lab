#!/bin/bash

echo Enter name
read name
name2=${name// /} #Without whiespace
echo No of alphabets : ${#name2}
echo Reverse: `echo $name | rev`
