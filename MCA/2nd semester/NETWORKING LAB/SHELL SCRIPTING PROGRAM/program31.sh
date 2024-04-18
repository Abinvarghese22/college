#!/bin/bash

# Set the search directory
search_dir="."

# Find all ".txt" files in the search directory and its subdirectories
# Count occurrences of "Linux" in each file and sum them up
count=$(find "$search_dir" -type f -name "*.txt" -exec grep -o "Linux" {} + | wc -l)

# Print the total count
echo "Total count of 'Linux' in all .txt files: $count"

