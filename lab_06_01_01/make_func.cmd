@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c utils.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 --coverage -c films.c
gcc -o app.exe main.o utils.o films.o -lgcov
PUSHD func_tests
CALL ./all_test.cmd
PUSHD ..
gcov main.c
gcov utils.c
gcov films.c
del out.txt
pause
