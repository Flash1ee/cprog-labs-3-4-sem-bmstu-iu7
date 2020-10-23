#!/bin/sh

for var in 1 2 3 4 5 6 7 8 
do
    ./pos_test.sh 0$var
done
echo ++++++++++++++++++++++++++++++++++
for var in 1 2 3 6 7 8 10 11 12 14
do
    ./neg_test.sh 0$var
done
rm out.txt
