#! /bin/bash

echo -n "Enter your age: "
read AGE

if [ $AGE -ge 25 ]; then
    echo "당신은 25세 이상입니다."
else
    echo "당신은 25세 미만입니다."
fi