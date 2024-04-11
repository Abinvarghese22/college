read num
reverse=$(echo "$num" | rev)
if [ "$num" -eq "$reverse" ]; then
    echo "$num is same when reversed."
else
    echo "$num is not same when reversed."
fi

