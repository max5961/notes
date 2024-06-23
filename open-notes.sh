#!/bin/bash

notes_dir="$HOME/notes"

num=1
for dir in $notes_dir/*; do
    if [ -d "$dir" ]; then
        echo "$num: $(basename "$dir")"
        ((num++))
    fi
done

read -p "Enter one of the above: " chosen

num=1
for dir in $notes_dir/*; do
    if [ -d "$dir" ]; then
        dir=$(basename "$dir")

        if [ "$chosen" == "$dir" ] || [ "$chosen" == "$num" ]; then
            echo ""
            bat "$notes_dir/$dir/notes.txt"

            exit 0
        fi

        ((num++))
    fi
done
