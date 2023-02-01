#!/bin/zsh
# check if two variables are having equal value
read a
read b
if [ $a -eq $b ]; then
	echo "$a and $b are equal!!"
else 
	echo "not equal!!"
fi
