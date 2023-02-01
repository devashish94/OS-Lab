#!/bin/zsh

# Simple addition arithmetic
#echo $(($1 + $2))

# If you don't want to use those 'double brackets',
# then you can use the keyword 'expr'
echo $(expr $1 \+ $2)
