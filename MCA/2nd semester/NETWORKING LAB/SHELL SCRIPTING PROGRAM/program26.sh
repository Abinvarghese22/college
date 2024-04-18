#!/bin/bash
num=1
row=1
while [ $row -le 4 ]; do
for (( i=1; i<=$row; i++ )); do
echo -n "$num "
num=$((num+1))
done
echo ""
row=$((row+1))
done
