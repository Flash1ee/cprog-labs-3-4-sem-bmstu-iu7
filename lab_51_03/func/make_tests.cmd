@echo off
gcc -Wall -Wextra -Wpedantic -Wvla -o test.exe do_bin.c
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror --coverage -c ..\main.c	
gcc -std=c99 -Wall -Wpedantic -Wextra -Werror --coverage -c ..\utils.c	
gcc -o app.exe main.o utils.o -lgcov
python make_tests.py
for /l %%b IN (1,1,3) DO (.\test.exe pos_0%%b_in.txt pos_0%%b_in.bin)
ECHO POS_TESTS
.\app.exe c 10 pos.bin

for /l %%b in (1,1,3) DO (
	.\app.exe s pos_0%%b_in.bin
	.\app.exe p pos_0%%b_in.bin >output.txt
	IF %ERRORLEVEL% NEQ 0 ECHO posTEST Failed
	FC /N output.txt pos_0%%b_out.txt 
)

ECHO NEG_TEST
@echo off>pos_err.txt
.\app.exe s pos_err.bin
.\app.exe p pos_err.bin > out.txt
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
FC /N out.txt pos_err.txt

.\app.exe c ds pos_err.bin
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::
.\app.exe m pos_err.bin

.\app.exe c 0 pos_err.bin
.\app.exe s pos_err.bin
IF %ERRORLEVEL% NEQ 0 ECHO NEG TEST ::PASSED::

for /l %%b IN (1,1,3) DO (
del pos_0%%b_in.txt; 
del pos_0%%b_in.bin;
del pos_0%%b_out.txt;
)
del pos.bin
del *.txt *.exe *.o
gcov main.c
gcov utils.c
del *gcov *gcda *gcno *gcdo

pause

	 

