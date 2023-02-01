#!/bin/zsh
echo "Enter the mark"
read mark
if (( $mark >= 90 )); then
	echo "Grade - A"
elif (( $mark < 90 && $mark >= 70 )); then
	echo "Grade - B"
elif (( $mark < 70 && $mark >= 50 )); then
	echo "Grade - C"
elif (( $mark < 50 && $mark >= 30 )); then
	echo "Grade - D"
else
	echo "Grade - F"
fi
