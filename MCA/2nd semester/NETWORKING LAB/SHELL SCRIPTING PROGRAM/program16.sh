sum=0
for (( i=50; i<=100; i++ )); do
    if (( i % 3 == 0 )) && (( i % 5 != 0 )); then
        sum=$(( sum + i ))
    fi
done
echo "Sum of numbers between 50 and 100, which are divisible by 3 and not divisible by 5: $sum"

