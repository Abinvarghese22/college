#!/bin/bash

# Prompt the user to enter a number
echo "Enter a number: "
read num

# Check if the number is divisible by 2
if (( num % 2 == 0 )); then
    echo "$num is even."
else
    echo "$num is odd."
fi

