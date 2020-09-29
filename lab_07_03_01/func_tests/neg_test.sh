#!/bin/sh

if [ $# != 1 ]
then echo ERROR COUNT OF PARAMETERS
fi
var=<./tests/neg_$1_args
../app.exe $var <./tests/pos_$1_in > out.txt
if [ $? -eq 0 ]
then echo NEG TEST $1 ::FAIL:: RETURN CODE IS ZERO...
else echo NEG TEST $1 ::SUCCESS::
fi 
diff -u ./shared/neg_$1_res ./shared/neg_$1_out
