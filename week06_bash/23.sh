#! /bin/bash

factorial() {

    list=$(seq $1)
    result=1

    for l in $list; do
        result=$(($result * $l))
    done

    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM