#!/bin/bash

args=$@

# Prints all the values at once
echo "Arguments: $args"

# Prints the total count of values provided
echo "Count: $#"

# Prints the index of all the values
echo -n "Indices: "
i=1
for arg in $@
do 
	echo -n "$i "
	i=$((i + 1))
done
echo
