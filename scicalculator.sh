#!/bin/bash

echo "Scientific calculator and its operations"
echo
echo "Operations that can be performed"
echo "Addition: +"
echo "Subtraction: -"
echo "Multiplication: *"
echo "Division: /"
echo "Modulus: %"
echo "Exponential: ^"
echo "Paranthesis: ()"
echo
echo "Enter expression: "
read exp
echo
echo "Result: `awk "BEGIN{print $exp}"`"
echo

