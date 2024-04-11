#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

if cmp -s "$1" "$2"; then
    echo "The contents of $1 and $2 are the same. Deleting $2..."
    rm "$2"
else
    echo "The contents of $1 and $2 are different."
fi

