@ECHO OFF
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic --coverage -c main.c
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic --coverage -c utils.c
gcc main.o utils.o -o app.exe -lgcov



