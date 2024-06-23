#!/bin/bash

target="$HOME/notes/bash/tldp.txt"
cd "$HOME/notes/bash"

function myfunc() {
    for file in *; do
        if [ -d "$file" ]; then
            cd "$file"
            myfunc
        else
            myfunc "$file" >>"$target"
        fi
    done
}

myfunc
