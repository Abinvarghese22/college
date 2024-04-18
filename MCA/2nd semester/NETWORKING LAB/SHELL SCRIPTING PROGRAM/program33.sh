#!/bin/bash

echo "Enter directory path: "
read directory

num_files=$(find "$directory" -type f | wc -l)
num_directories=$(find "$directory" -type d | wc -l)

echo "Number of files: $num_files"
echo "Number of directories: $num_directories"

