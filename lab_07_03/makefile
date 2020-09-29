CC=gcc
INCPATH=./inc/
OBJPATH=./out/
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

app.exe: dirs $(OBJPATH)main.o $(OBJPATH)filter.o $(OBJPATH)io.o $(OBJPATH)sort.o 
	$(CC) $(LFLAGS) -o app.exe $(OBJPATH)main.o $(OBJPATH)filter.o $(OBJPATH)io.o $(OBJPATH)sort.o

$(OBJPATH)filter.o: $(SRCPATH)filter.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJPATH)sort.o: $(SRCPATH)sort.c
	$(CC) $(CFLAGS) -o $@ $^
$(OBJPATH)io.o: $(SRCPATH)io.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -o $@ $^

func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCTESTSPATH) && bash all_test.sh
	@echo
	gcov -n $(OBJPATH)main.o
	gcov -n $(OBJPATH)filter.o
	gcov -n $(OBJPATH)sort.o
	gcov -n $(OBJPATH)io.o

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