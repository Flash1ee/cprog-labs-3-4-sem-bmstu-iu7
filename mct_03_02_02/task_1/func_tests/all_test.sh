#!/bin/sh

for var in 1 2 3
do
    ./pos_test.sh 0$var
done
for var in 1
do
    ./neg_test.sh 0$var
done
rm out.txt
