CC=gcc
INCPATH=./inc/
OBJPATH=./obj/
SRCPATH=./src/
FUNCTESTSPATH=./func_tests/
UNITTESTSPATH=./unit_tests/
CFLAGS=-std=c99 --coverage -I$(INCPATH) -Wall -Wpedantic -Wextra -g3 -c
LFLAGS=--coverage
.PHONY: clean
.NOTPARALLEL: release debug

release: CFLAGS=-std=c99 -I$(INCPATH) -o2 -c
release: LFLAGS=-o2
release: $(OBJPATH)release.lastbuildstate app.exe

debug:$(OBJPATH)debug.lastbuildstate app.exe

$(OBJPATH)debug.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)release.lastbuildstate
	touch $(OBJPATH)debug.lastbuildstate

$(OBJPATH)release.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)debug.lastbuildstate
	touch $(OBJPATH)release.lastbuildstate

app.exe: $(OBJPATH)main.o $(OBJPATH)unit1.o $(OBJPATH)unit2.o $(OBJPATH)unit3.o
	$(CC) $(LFLAGS) -o app.exe $(OBJPATH)main.o $(OBJPATH)unit1.o $(OBJPATH)unit2.o $(OBJPATH)unit3.o

$(OBJPATH)unit1.o: $(SRCPATH)unit1.c
	$(CC) $(CFLAGS) -o$(OBJPATH)unit1.o $(SRCPATH)unit1.c

$(OBJPATH)unit2.o: $(SRCPATH)unit2.c
	$(CC) $(CFLAGS) -o$(OBJPATH)unit2.o $(SRCPATH)unit2.c

$(OBJPATH)unit3.o: $(SRCPATH)unit3.c
	$(CC) $(CFLAGS) -o$(OBJPATH)unit3.o $(SRCPATH)unit3.c

$(OBJPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -o$(OBJPATH)main.o $(SRCPATH)main.c

func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCTESTSPATH) && cmd //C all_test.cmd
	@echo
	gcov -n $(OBJPATH)main.o
	gcov -n $(OBJPATH)unit1.o
	gcov -n $(OBJPATH)unit2.o
	gcov -n $(OBJPATH)unit3.o

dirs: $(INCPATH) $(OBJPATH) $(SRCPATH)

$(OBJPATH):
	mkdir $(OBJPATH)

$(INCPATH):
	mkdir $(INCPATH)

$(SRCPATH):
	mkdir $(SRCPATH)

clean:
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)*.lastbuildstate