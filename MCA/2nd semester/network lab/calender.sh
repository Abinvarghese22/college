#!/bin/bash

# Check if the script is called with exactly two arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <month> <year>"
    exit 1
fi

# Assign arguments to variables
m=$1
y=$2

# Display the calendar for the specified month and year
echo "$(date -d "$y-$m-01" "+%B %Y")"
echo "Su Mo Tu We Th Fr Sa"

# Determine the first day of the month
first_day=$(date -d "$y-$m-01" "+%u")

# Determine the number of days in the month
num_days=$(date -d "$y-$((m+1))-01 - 1 day" "+%d")

# Calculate the number of spaces needed before the first day
for ((i=1; i<$first_day; i++)); do
    echo -n "   "
done

# Print the dates
for ((i=1; i<=$num_days; i++)); do
    printf "%2d " "$i"
    if [ $((($first_day + $i - 1) % 7)) -eq 0 ]; then
        echo ""
    fi
done

echo ""

