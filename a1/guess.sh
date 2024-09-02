#!/bin/bash

echo "Welcome to the number game."
echo "Guess a number between 1 and 64 (inclusive)."

rand=$[ $RANDOM % 64 + 1 ]

declare -i tries=6

while [ "$tries" -gt 0 ]
do
    read guess
    if ((guess < 1 || guess > 64)); then
        echo "Error: Your number should be between 1 and 64 (inclusive)."
        continue
    fi
    if ((guess < rand)); then
        echo "Too small."
    elif ((guess > rand)); then
        echo "Too big."
    else
        echo "You won!"
        exit
    fi  

    ((tries--))

    if [ "$tries" -gt "0" ]; then
        echo "Try again."
    fi
done
echo "You lost!"