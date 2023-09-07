#!/bin/bash

PATTERN="*task*"
find /proc -name $PATTERN 1> output.txt 2> errors.txt 0> /dev/null

# 1> redirects the output 
# 2> redirects the errors

printf "\nFirst 3 lines of output.txt:\n"
head -n 3 output.txt

printf "\nFirst 3 lines of errors.txt\n"
head -n 3 errors.txt
