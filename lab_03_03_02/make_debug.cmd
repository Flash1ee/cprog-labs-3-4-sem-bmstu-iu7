@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -g3 -c main.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -Wvla -g3 -c array.c
gcc -o app.exe main.o array.o