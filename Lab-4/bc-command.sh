#!/bin/zsh

# Using the bc command to evaluate
# expressions and getting floating
# point values
# echo "scale = 20; $1 / $2" | bc

# Finding square root of a number
echo "scale = 2; sqrt($1)" | bc -l