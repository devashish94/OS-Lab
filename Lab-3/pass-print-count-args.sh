#!/usr/bin/env sh
# Passing value through arguments
#echo $1 $2 $3

# Use '$@' for passing values. Use '$#' for argument count
echo "All the arguments passed: $@"
echo "Argument count: $#"
