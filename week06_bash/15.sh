#! /bin/bash

file_wordcnt() {
    files=$(ls *.txt)
    for f in $files; do
        echo "$f 파일의 단어는 $(cat $f | wc -w) 개 입니다."
    done
}

file_wordcnt