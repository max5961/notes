#!/bin/bash

# Definitions
#
# blank - a space or tab character
# builtin - a command that is implemented interanlly by the shell itself, rather than
# an executable program somewhere in the file system
# control operator - a token that performs a control function.  it is either a new line or one of the following:
#   ||, &&, &, ;, ;;, ;&, ;;&, |, |&, (, )
# exit status - the value returned by a command to its caller.  THe maximum value is 255
# field - a unit of text that is the result of one of the shell expansions.  After expansion, when executing
# a command, the resulting fields are used as the command name and arguments
# filename = a string of chars used to indentify a file
# job - a set of processes comprising a pipeline, and any processes descended from it, that are
# all in the same process group
# job control - a mechanism by which users can selectively stop and result execution of processes
# metacharacter - a character that, when unquoted separates words.  A metacharacter is a space, tab, newline, or 
# one of the following: |, &, ;, ,, (, ), <, >
# name: a word consisting solely of letters, numbers, and underscores, and beginning with a letter or underscore
# names are used as shell variable and function names.  Can also be referred to as an identifier
# operator - a control operator OR a redirection operator
# process group - a collection of relates processes each having the same process group ID
# process group ID - a unique identifier that represents a process group during its lifetime
# reserve word - a word with special meaning to the shell such as 'for' and 'while'
# return status - the same thing as exit status
# signal - a mechanism by which a process may be notified by the kernal of an event occuring in the system
# special builtin - a shell builtin command that has been classified as special by the POSIX standard
# token - a sequence of characters considered a single unit by the shell.  Its either a word or an operator
# word - a sequence of chars treated as a unit by the shell.  Words may not include unquoted maracharacters
#
# Shell Syntax
# quoting is used to remove the special meaning of certain characters or words to the shell
# quoting can be used to disable special treatment for special chars, to prevent reserved words from being recognized as such,
# and to prevent parameter expansion
# there are 3 quoting mechanisms: single quotes, double quotes, and the escape character which is a backslash (\)
#
# Escape Character
# a backslash is the Bash escape character.
# printf "hello world\nyeah buddy\n"
#
# Reserved words
# these words have special meaning to the shell.  They are used to begin and end the shell's compound commands
# The following are recognized as reserved when unquoted and the first word of a commmand
# if, then, elif, else, fi, time, for, in, until, while, do, done, case, esac, coproc, select, function { } [[  ]] !
#
# Simple Commands:
# a simple command is the kind fo command encountered most often.  Its just a sequence of words separated by blanks
# the first word generally specifies a command to be executed, witht he rest of the words being the commands args
#
# Pipelines
# the output of each command in the pipeline is connected via a pipe to the input of the next command
# if |& is used, command1's std error and std output is connected to command2's std input through the pipe 
# this is shorthand for 2>&1
#
# List of commands
# command1 && command2 (command2 is executed if, and only if, command1 returns an exit status of 0 for success)
# c1 || c2 (c2 is executed if, and only if, c1 returns a non-zero exit status)
#
# Compound Commands
# looping constructs, conditional constructs, grouping commands
# until: until test-commands; do consequent-commands; done
    # execute consequent-commands as long as test-commands has an exit status other than zero
# while: while test-commands; do consequent-commands; done
#   # execute consequent-commands as long as the test-commands has an exit status of zero..the opposite of until
# the return status of until and while is the exit of status of the last command executed in consequent-commands, or zero if none
# was exectued
# 
# until and while loop examples

count=0
until [ "$count" -ge 5 ]; do
    echo "Doing this until count is greater than or equal 5. Count is: $count"
    # (()) syntax is used for arithmetic expansion
    ((count++))
done

count=0
while [ "$count" -le 10 ]; do
    echo "Doing this while count is less than 10. Count is: $count"
    ((count++))
done

# for loops
# word expansion
fruits=("apple" "banana" "cherry")
for fruit in "${fruits[@]}"; do
    echo "Fruit: $fruit"
done

# using the set command to use positional parameters
set -- "hello" "world"
for word; do
    echo "word: $word"
done

# C-style syntax
for ((i=0; i<5;i++)); do
    echo "Number is $i"
done

# Conditional Statements
# if command
value=10
if [ "$value" -eq 10 ]; then
    echo "Value is 10"
elif [ "$value" -eq 20 ]; then
    echo "Value is 20"
else
    echo "Value isn't 10 or 20"
fi

# case command
# the ;; operator causes no subsequent matches to be attempted after the first pattern match
echo -n "Enter the name of an animal: "
read ANIMAL
echo -n "The $ANIMAL has "
case $ANIMAL in 
    horse | dog | cat) echo -n "four";;
    man | kangaroo) echo -n "two";;
    *) echo -n "an unknown number of";;
esac
echo " legs"

# 3.2.53 Grouping Commands







