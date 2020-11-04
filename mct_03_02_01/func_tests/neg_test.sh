#!/bin/sh

if [ $# != 1 ]
then echo ERROR COUNT OF PARAMETERS
fi
valgrind --leak-check=full ../app.exe <./tests/neg_$1_in.txt > out.txt
if [ $? -eq 0 ]
then echo NEG TEST $1 ::FAIL:: RETURN CODE IS ZERO...
else echo NEG TEST $1 ::SUCCESS::
fi 
diff -Zqu ./tests/neg_$1_out.txt out.txt
