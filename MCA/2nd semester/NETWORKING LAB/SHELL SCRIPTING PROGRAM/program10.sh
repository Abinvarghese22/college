echo "Prime numbers between 1 and 50 are:"
for (( number=2; number<=50; number++ )); do
    flag=1
    for (( i=2; i<=number/2; i++ )); do
        if [ $((number%i)) -eq 0 ]; then
            flag=0
            break
        fi
    done
    if [ $flag -eq 1 ]; then
        echo $number
    fi
done

