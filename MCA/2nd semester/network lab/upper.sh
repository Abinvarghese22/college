#!/bin/bash

# Check if file exists
if [ ! -f "$1" ]; then
    echo "File '$1' not found."
    exit 1
fi

# Convert contents to uppercase using tr command
tr '[:lower:]' '[:upper:]' < "$1"

