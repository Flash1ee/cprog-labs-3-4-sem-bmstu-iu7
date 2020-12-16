#!/bin/sh

if [ $# != 1 ]
then echo ERROR COUNT OF PARAMETERS
fi
var=$(cat ./tests/pos_$1_args.txt)
../app.exe $var<./tests/pos_$1_in.txt > out.txt
if [ $? -eq 0 ]
then echo POS TEST $1 ::SUCCESS::
else echo POS TEST $1 ::FAIL:: RETURN CODE IS NOT ZERO...
fi 
diff -u ./shared/pos_$1_res.txt ./shared/pos_$1_out.txt
