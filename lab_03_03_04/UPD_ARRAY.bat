FOR /R %%A IN ("*array.c") DO (
ECHO %%A
COPY /Y "C:\C_funcs\arrays\array.c" "%%A"
)
FOR /R %%A IN ("*array.h") DO (
ECHO %%A
COPY /Y "C:\C_funcs\arrays\array.h" "%%A"
)