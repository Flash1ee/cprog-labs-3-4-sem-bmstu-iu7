#!/bin/sh

for var in 1 2 3 4 5 6
do
    ./pos_test.sh 0$var
done
echo ++++++++++++++++++++++++++++++++++
for var in 1 2 3 4 5
do
    ./neg_test.sh 0$var
done
