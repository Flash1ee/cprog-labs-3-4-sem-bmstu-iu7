FOR /R %%A IN ("*make_clean.cmd") DO (
ECHO %%A
COPY /Y "C:\C_funcs\make_matrix\make_clean.cmd" "%%A"
)
FOR /R %%A IN ("*make_func.cmd") DO (
ECHO %%A
COPY /Y "C:\C_funcs\make_matrix\make_func.cmd" "%%A"
)
FOR /R %%A IN ("*make_debug.cmd") DO (
ECHO %%A
COPY /Y "C:\C_funcs\make_matrix\make_debug.cmd" "%%A"
)
FOR /R %%A IN ("*make_release.cmd") DO (
ECHO %%A
COPY /Y "C:\C_funcs\make_matrix\make_release.cmd" "%%A"
)