#!/bin/zsh

read fname
read lname

if [[ $fname == "Devashish" ]]; then
	if [[ $lname == "Roy" ]]; then
		echo "You are Devashish Roy!"
	else 
		echo "No!"
	fi
else 
	echo "No!!"
fi
