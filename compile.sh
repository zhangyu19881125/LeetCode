#!/bin/bash

cd $(dirname $0)

if test $# -ne 1
then
    echo "usage: $0 index_number"
    exit 1
fi

idx=$1

cppfile=$(find . -name "${idx}_*")
exefile=$(echo $cppfile | cut -d '/' -f 3 | cut -d . -f 1)

echo g++ -o ./$exefile $cppfile
g++ -o ./$exefile $cppfile

exit 0

