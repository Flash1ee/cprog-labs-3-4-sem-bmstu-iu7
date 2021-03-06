#!/bin/sh

if [ $# != 1 ]
then echo ERROR COUNT OF PARAMETERS
fi
var=$(cat ./tests/pos_$1_args.txt)
valgrind --leak-check=full ../app.exe $var<./tests/pos_$1_in.txt > out.txt
if [ $? -eq 0 ]
then echo POS TEST $1 ::SUCCESS::
else echo POS TEST $1 ::FAIL:: RETURN CODE IS NOT ZERO...
fi 
diff -Zqu ./tests/pos_$1_out.txt out.txt
