reverse_number() {
    local number=$1
    local reverse=0
    while (( number > 0 )); do
        reverse=$(( reverse * 10 + number % 10 ))
        number=$(( number / 10 ))
    done
    echo "$reverse"
}

echo "Enter a number:"
read number
result=$(reverse_number $number)
echo "Reverse of $number: $result"

