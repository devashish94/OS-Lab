#!/bin/zsh

# Initialize a 2D Array
declare -A array

# Input values to a 2D Array
echo -n "No. of Rows: "
read row
echo -n "No. of Columns: "
read col
for (( i=1 ; i <= row ; i++ )) do
    for (( j=1 ; j <= col ; j++ )) do
        read x
	array[$i,$j]=$x
    done
done

# Printing values from 2D Array
echo "The 2D Array is: "
for (( i=1 ; i <= row ; i++ )) do
    for (( j=1 ; j <= col ; j++ )) do
        echo -n "${array[$i,$j]} "
    done
    echo
done
