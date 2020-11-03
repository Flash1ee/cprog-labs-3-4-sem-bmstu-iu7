#!/bin/sh

for var in 1 2 3 4 5
do
    ./pos_test.sh 0$var
done
rm out.txt
