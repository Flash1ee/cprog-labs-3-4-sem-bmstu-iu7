CC=gcc
INCPATH=./inc/
OBJPATH=./out/
SRCPATH=./src/
FUNCTESTSPATH:=./func_tests/
UNITTESTSPATH:=./unit_tests/
CFLAGS=-std=c99 --coverage -I$(INCPATH) -Wall -Wpedantic -Wextra -g3 -c
LFLAGS=--coverage
UFLAGS= -lcheck -lpthread -lrt
OBJS= $(OBJPATH)filter.o $(OBJPATH)io.o $(OBJPATH)sort.o $(OBJPATH)arr.o
UNITS= $(OBJPATH)check_main.o $(OBJPATH)check_filter.o $(OBJPATH)check_sort.o $(OBJPATH)sort.o $(OBJPATH)filter.o

.PHONY: clean unit func
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

app.exe: dirs $(OBJPATH)main.o  $(OBJS) 
	$(CC) -o $@ $(OBJPATH)main.o $(OBJS) $(LFLAGS) 

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) -o $@ $^


func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCTESTSPATH) && bash all_test.sh
	@echo
	gcov -n $(OBJPATH)main.o
	gcov -n $(OBJPATH)filter.o
	gcov -n $(OBJPATH)sort.o
	gcov -n $(OBJPATH)io.o

unit: unit_tests.exe app.exe
	valgrind --leak-check=full ./unit_tests.exe

unit_tests.exe: CFLAGS=-std=c99 -I$(INCPATH) -Wall -Wpedantic -Wextra -g3 -c -lpthread -lrt -ggdb
unit_tests.exe: $(UNITS)
	$(CC) -o $@  $^ $(UFLAGS)

$(OBJPATH)check%.o : $(UNITTESTSPATH)check%.c 
	$(CC) $(CFLAGS) $< -o $@ 

dirs: $(INCPATH) $(OBJPATH) $(SRCPATH)

$(OBJPATH):
	mkdir $(OBJPATH)

$(INCPATH):
	mkdir $(INCPATH)

$(SRCPATH):
	mkdir $(SRCPATH)
$(FUNCTESTSPATH):
	mkdir $(FUNCTESTSPATH)
$(UNITTESTSPATH):
	mkdir $(UNITTESTSPATH)

clean: 
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)*.lastbuildstate
