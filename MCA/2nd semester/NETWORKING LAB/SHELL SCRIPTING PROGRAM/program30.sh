#!/bin/bash

# Prompt the user for the file name
echo "Enter the file name: "
read file

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "File not found."
    exit 1
fi

# Convert the contents of the file to lowercase and replace all non-alphanumeric characters with spaces
contents=$(tr '[:upper:]' '[:lower:]' < "$file" | sed 's/[^a-z0-9]/ /g')

# Extract unique words and count occurrences
unique_words=$(echo "$contents" | tr -s ' ' '\n' | sort | uniq)
declare -A count
for word in $unique_words; do
    count[$word]=$(grep -o "\<$word\>" <<< "$contents" | wc -l)
done

# Print the unique words and their counts
echo "Unique words in $file:"
for word in "${!count[@]}"; do
    echo "$word: ${count[$word]}"
done

