echo "Enter an integer: "
read number
n=$number
count=0
sum=0

# Count number of digits
while [ $n -gt 0 ]; do
    n=$((n / 10))
    count=$((count + 1))
done

n=$number

# Calculate Armstrong number
while [ $n -gt 0 ]; do
    digit=$((n % 10))
    sum=$((sum + digit ** count))
    n=$((n / 10))
done

if [ $sum -eq $number ]; then
    echo "The number $number is an Armstrong number."
else
    echo "The number $number is not an Armstrong number."
fi

