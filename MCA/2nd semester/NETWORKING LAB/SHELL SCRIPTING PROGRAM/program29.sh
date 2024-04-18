#!/bin/bash

# Prompt the user for the string to check
echo "Enter a string: "
read string

# Reverse the string
reverse=$(echo $string | rev)

# Check if the string is equal to its reverse
if [ "$string" == "$reverse" ]; then
    echo "$string is a palindrome."
else
    echo "$string is not a palindrome."
fi

