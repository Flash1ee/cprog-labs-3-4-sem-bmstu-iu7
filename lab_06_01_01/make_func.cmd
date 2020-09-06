@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c utils.c
gcc -o app.exe main.o utils.o -lgcov
PUSHD func_tests
CALL ./all_test.cmd
PUSHD ..
gcov main.c
gcov utils.c
del out.txt
pause
