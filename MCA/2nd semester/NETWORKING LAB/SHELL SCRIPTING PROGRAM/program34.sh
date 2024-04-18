Write a shell script to reverse the list of strings and reverse each string further in the list.
#!/bin/bash
my_list=("string1" "string2" "string3" "string4")
# Reverse the order of the list
my_list=($(echo "${my_list[@]}" | tr ' ' '\n' | tac | tr '\n' ' '))
# Reverse each string in the list
for i in "${!my_list[@]}"
do
my_list[$i]=`echo ${my_list[$i]} | rev`
done
# Print the reversed list of strings
echo "${my_list[@]}"
