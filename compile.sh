#!/bin/bash

cd $(dirname $0)

if test $# -ne 1
then
    echo "usage: $0 index_number"
    exit 1
fi

idx=$1

cppfile=$(find . -name "${idx}_*")
exefile=test
echo g++ -o ./$exefile $cppfile
echo

g++ -o ./$exefile $cppfile

exit 0

