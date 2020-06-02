@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c array.c
gcc -o app.exe main.o array.o -lgcov
PUSHD func
CALL ./all_test.cmd
PUSHD ..
gcov main.c
gcov array.c
pause