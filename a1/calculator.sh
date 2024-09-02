#!/bin/bash

declare -i solution=0

if [ "$#" -ne "3" ]; then
    echo "Usage -./calculator.sh value1 operator value2"
    echo "where,"
    echo "value1: numeric value"
    echo "value2: numeric value"
    echo "operator: one of +,-,/,x"
    exit
fi

if [ "$2" == "/" ] && [ "$3" == "0" ]; then
    echo "Division-by-zero Error!"
    exit
fi

if [ "$2" == "+" ]; then
    solution=$(($1 + $3))
elif [ "$2" == "-" ]; then
    solution=$(($1 - $3))
elif [ "$2" == "/" ]; then
    solution=$(($1 / $3))
elif [ "$2" == "x" ]; then
    solution=$(($1 * $3))
fi
echo $solution