@ECHO OFF
IF "%1"=="" ECHO NOT ENOUGH PARAMETERS... & GOTO :END
SET /P var=<.\tests\neg_%~1_args.txt
..\app.exe %var% <.\tests\neg_%~1_in.txt >out.txt
IF %ERRORLEVEL% EQU 0 ECHO NEG TEST %~1 ::FAIL:: RETURN CODE IS ZERO... & GOTO :END
FC /N .\tests\neg_%~1_out.txt out.txt
:END