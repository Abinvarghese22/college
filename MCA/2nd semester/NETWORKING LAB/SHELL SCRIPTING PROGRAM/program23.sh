#!/bin/bash

while true; do
    clear
    echo "Menu:"
    echo "1. List current directory"
    echo "2. Print working directory"
    echo "3. Display date"
    echo "4. Display users logged in"
    echo "5. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1)
            ls -l
            read -p "Press enter to continue"
            ;;
        2)
            pwd
            read -p "Press enter to continue"
            ;;
        3)
            date
            read -p "Press enter to continue"
            ;;
        4)
            who
            read -p "Press enter to continue"
            ;;
        5)
            exit 0
            ;;
        *)
            echo "Invalid choice. Press enter to try again"
            read
            ;;
    esac
done

