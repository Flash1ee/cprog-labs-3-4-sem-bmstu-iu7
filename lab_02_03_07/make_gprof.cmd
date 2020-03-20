@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -g -pg main.c -o app.exe
python make_massivs.py
.\app.exe < pos_010_in.txt > pos_010_out.txt
gprof app.exe > report1.txt
.\app.exe < pos_01000_in.txt > pos_01000_out.txt
gprof app.exe > report2.txt
.\app.exe < pos_010000_in.txt > pos_010000_out.txt
gprof app.exe > report3.txt
.\app.exe < pos_015000_in.txt > pos_015000_out.txt
gprof app.exe > report4.txt
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -O0 -g -pg main.c -o app.exe
.\app.exe < pos_015000_in.txt
gprof app.exe > report4_O0.txt
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -O1 -g -pg main.c -o app.exe
.\app.exe < pos_015000_in.txt
gprof app.exe > report4_O1.txt
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -O2 -g -pg main.c -o app.exe
.\app.exe < pos_15000_in.txt
gprof app.exe > report4_O2.txt
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -O3 -g -pg main.c -o app.exe
.\app.exe < pos_015000_in.txt
gprof app.exe > report4_O3.txt
pause