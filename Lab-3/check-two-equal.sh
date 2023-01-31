# check if two variables are having equal value
read a
read b
if [ $a == $b ]; then
	echo "$a and $b are equal!!"
else 
	echo "not equal!!"
fi
