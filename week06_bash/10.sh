#! /bin/bash

print_parma() {
    echo "script name: $0"
    echo "first param: $1"
    echo "second param: $2"
    echo "all params$@"
    echo "the number of params: $#"
}

# print_parma Hello World !

print_txt_num() {
    name="$(ls | grep ".txt")"
    for n in $name; do
        echo $(cat $n | wc -w)
    done 
}

print_txt_num