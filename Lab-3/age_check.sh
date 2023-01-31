# check if a person is eligible for voting
read a
if (( $a >= 18 )); then 
    echo "can vote"
else 
    echo "cannot vote"
fi
