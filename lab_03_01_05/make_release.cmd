@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -c main.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror -c array.c
gcc -o app.exe main.o array.o
