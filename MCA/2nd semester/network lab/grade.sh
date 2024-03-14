#!/bin/bash

# Function to calculate grade based on percentage
calculate_grade() {
    if (( $(echo "$1 >= 90" | bc -l) )); then
        echo "Grade: A"
    elif (( $(echo "$1 >= 80" | bc -l) )); then
        echo "Grade: B"
    elif (( $(echo "$1 >= 70" | bc -l) )); then
        echo "Grade: C"
    elif (( $(echo "$1 >= 60" | bc -l) )); then
        echo "Grade: D"
    else
        echo "Grade: F"
    fi
}

# Input marks for subjects
echo "Enter marks for each subject (out of 100):"
read -p "Subject 1: " subject1
read -p "Subject 2: " subject2
read -p "Subject 3: " subject3

# Calculate total marks
total_marks=$((subject1 + subject2 + subject3))

# Calculate percentage
percentage=$(echo "scale=2; $total_marks / 3" | bc)

echo "Total marks: $total_marks"
echo "Percentage: $percentage%"

# Calculate and display grade
calculate_grade $percentage

