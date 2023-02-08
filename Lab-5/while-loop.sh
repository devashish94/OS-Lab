#!/bin/zsh

# Program for Mathematical table of a
# number you input
echo -n "enter number: "
read number
i=1
while [ $i -le 10 ]; do
    echo "$number x $i = $(expr $number \* $i)"
    i=$(( $i + 1 ))
done
