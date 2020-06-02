@echo off
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror --coverage -c ..\main.c	
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror --coverage -c ..\utils.c	
gcc -o app.exe main.o utils.o -lgcov


FOR /L %%B IN (1,1,7) DO (
	.\app.exe sb pos_0%%B_in.bin pos_0%%B_out.bin
	.\app.exe pr pos_0%5B_out.bin > out.txt
	IF %ERRORLEVEL% EQU 0 ECHO POS TEST %%B ::PASSED::
	)
.\app.exe fb pos_08_in.bin ma > out.txt
FC /N pos_08_out.txt out.txt
.\app.exe fb pos_09_in.bin ma > out.txt
FC /N pos_09_out.txt out.txt
.\app.exe fb pos_10_in.bin lom > out.txt
FC /N pos_10_out.txt out.txt
.\app.exe do pos_11_in.bin < out.txt
.\app.exe pr pos_09_in.bin > out.txt

	
rem не противоречит порядку новая структура
.\app.exe ab pos_21_in.bin < pos21.txt
IF %ERRORLEVEL% EQU 0 ECHO POS TEST ::PASSED::
.\app.exe ab pos_22_in.bin < pos22.txt
IF %ERRORLEVEL% EQU 0 ECHO POS TEST ::PASSED::
.\app.exe ab pos_23_in.bin < pos23.txt
IF %ERRORLEVEL% EQU 0 ECHO POS TEST ::PASSED::		





ECHO NEG_TEST
@echo off>pos_err.txt
rem неверное количесвто аргументов
.\app.exe pr pos.bin out.txt exe.bin
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
rem неверный режим c 3 аргументами
.\app.exe pq pos_err.bin 
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
rem неверный режим с 4 аргументами
.\app.exe pro pos_err.bin exe.bin
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
rem битый файл err.bin
.\app.exe pr pos_err.bin 
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
.\app.exe ab pos_err.bin 
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
.\app.exe fb pos_err.bin my
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
rem открытие несуществующего файла
.\app.exe fb pos_err.bin my
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
.\app.exe sb pos_err.bin my
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
rem вывод пуст
.\app.exe fb neg_08_in.bin qwerty
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
gcov main.c
gcov utils.c
del out.txt 
del my
del *.gcda *.gcno *.gcov *.o *.exe


pause

	 

