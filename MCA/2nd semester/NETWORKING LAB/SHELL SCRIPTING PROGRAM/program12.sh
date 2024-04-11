echo "Enter a line of text:"
read line
vowel_count=0
for (( i=0; i<${#line}; i++ )); do
    char=${line:i:1}
    case $char in
        [aeiouAEIOU])
            vowel_count=$((vowel_count + 1))
            ;;
    esac
done
echo "The number of vowels in the line of text is: $vowel_count"

