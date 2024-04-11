echo "Enter a number:"
read number

# Remove the minus sign if the number is negative
number=${number#-}

# Initialize smallest with the first digit
smallest=${number:0:1}

# Loop through the remaining digits
for (( i=1; i<${#number}; i++ )); do
    digit=${number:i:1}
    if (( digit < smallest )); then
        smallest=$digit
    fi
done

echo "Smallest digit: $smallest"

