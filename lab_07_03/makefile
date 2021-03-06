CC=gcc
INCPATH=./inc/
OBJPATH=./out/
SRCPATH=./src/
FUNCTESTSPATH:=./func_tests/
UNITTESTSPATH:=./unit_tests/
CFLAGS=-std=c99 --coverage -ggdb -I$(INCPATH) -Wall -Wpedantic -Wextra -g3 -c
LFLAGS=--coverage
UFLAGS=-lcheck
DIR_CR=mkdir -p
OBJS= $(OBJPATH)key.o $(OBJPATH)io.o $(OBJPATH)sort.o $(OBJPATH)arr.o
UNITS= $(OBJPATH)check_main.o $(OBJPATH)check_key.o $(OBJPATH)check_sort.o $(OBJPATH)sort.o $(OBJPATH)key.o

inc = $(wildcard $(INCPATH)*.h)
src = $(wildcard $(SRCPATH)*.c)
obj = $(src:$(SRCPATH)%.c=$(OBJPATH)%.o)
dep = $(obj:.o=.d) 
OUT := $(shell find -type f -name out)


.PHONY: clean func dirs out
.NOTPARALLEL: release debug

release: CFLAGS=-std=c99 -I$(INCPATH) -o2 -c
release: LFLAGS=-o2


debug: $(OBJPATH)debug.lastbuildstate app.exe
release: $(OBJPATH)release.lastbuildstate app.exe


unit_tests.exe: CFLAGS=-std=c99 -I$(INCPATH) -Wall -Werror -g3 -c
unit_tests.exe: clean $(UNITS)
	$(CC) -o $@  $(UNITS) $(UFLAGS)
	valgrind --leak-check=full ./unit_tests.exe


$(OBJPATH)check%.o : $(UNITTESTSPATH)check%.c 
	$(CC) $(CFLAGS) $< -o $@ 


func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCTESTSPATH) && bash all_test.sh
	@echo
	gcov -n $(OBJPATH)main.o
	gcov -n $(OBJPATH)key.o
	gcov -n $(OBJPATH)sort.o
	gcov -n $(OBJPATH)io.o

$(OBJPATH)debug.lastbuildstate: | out
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)release.lastbuildstate
	touch $(OBJPATH)debug.lastbuildstate

$(OBJPATH)release.lastbuildstate: | out
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)debug.lastbuildstate
	touch $(OBJPATH)release.lastbuildstate


app.exe: $(obj) | out
	$(CC) -o $@ $(obj) $(LFLAGS) 

$(OBJPATH)%.o: $(SRCPATH)%.c | out
	$(CC) $(CFLAGS) -o $@ $<

$(OBJPATH)%.d : $(SRCPATH)%.c | out
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifneq ($(MAKECMDGOALS), clean)
include $(dep)
endif

out:
ifneq ($(OUT),)
	rm -rf ./out
endif
	$(DIR_CR) $(OBJPATH)

dirs: $(OBJPATH) $(INCPATH) $(SRCPATH) $(UNITTESTSPATH) $(FUNCTESTSPATH)
$(OBJPATH):
	$(DIR_CR) $@
$(INCPATH):
	$(DIR_CR) $@
$(SRCPATH):
	$(DIR_CR) $@
$(FUNCTESTSPATH):
	$(DIR_CR) $@
$(UNITTESTSPATH):
	$(DIR_CR) $@
clean: 
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.d
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	rm -fv $(OBJPATH)*.lastbuildstate
