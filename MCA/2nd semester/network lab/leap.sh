#!/bin/bash

# Check if a year is provided as argument, otherwise use the current year
if [ $# -eq 0 ]; then
    yr=$(date +"%Y")
else
    yr=$1
fi

# Check if the year is divisible by 4, 100, and 400 to determine leap year
if [ $((yr % 4)) -eq 0 ] && [ $((yr % 100)) -ne 0 ] || [ $((yr % 400)) -eq 0 ]; then
    echo "$yr is a leap year"
else
    echo "$yr is not a leap year"
fi
