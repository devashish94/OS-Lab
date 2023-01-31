#!/usr/bin/env sh
# Passing value through arguments
#echo $1 $2 $3

# Using 'args' for passing values. Use $# for printing the size of the array
echo "All the arguments passed: $@"
echo "Argument count: $#"
