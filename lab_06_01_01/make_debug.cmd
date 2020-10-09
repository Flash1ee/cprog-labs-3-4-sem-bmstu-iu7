@ECHO OFF
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic --coverage -c main.c
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic --coverage -c utils.c
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic --coverage -c films.c
gcc main.o utils.o films.o -o app.exe -lgcov



