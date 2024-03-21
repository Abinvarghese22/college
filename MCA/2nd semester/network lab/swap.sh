#!/bin/bash
echo "Enter the two numbers"
read x y
a=$x
b=$y
echo " Using Temporary Variable"
echo "Before swap"
echo "x=$x"
echo "y=$y"
t=$y
y=$x
x=$t
echo "After swap"
echo "x=$x"
echo "y=$y"
echo " Without Using Temporary Variable"
echo "Before swap"
echo "x=$a"
echo "y=$b"
b=$((a+b))
a=$((b-a))
b=$((b-a))
echo "After swap"
echo "x=$a"
echo "y=$b"
