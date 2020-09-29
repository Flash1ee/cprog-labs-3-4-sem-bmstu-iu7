#!/bin/sh
echo off
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c ./src/filter.c -o ./out/filter.o
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c ./src/main.c -o ./out/main.o
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c ./src/io.c -o ./out/io.o
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c ./src/sort.c -o ./out/sort.o
gcc -o app.exe ./out/filter.o ./out/main.o ./out/io.o ./out/sort.o -lgcov
cd func_tests
bash ./all_test.sh
rm out.txt
cd ..
cd ./out
gcov ../src/main.c -o ../out/ -n
gcov ../src/sort.c -o ../out/ -n
gcov ../src/filter.c  -o ../out/ -n
gcov ../src/io.c -o ../out/ -n



