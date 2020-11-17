CC=gcc
INCPATH=./inc/
OBJPATH=./out/
SRCPATH=./src/
FUNCTESTSPATH:=./func_tests/
UNITTESTSPATH:=./unit_tests/
CFLAGS=-std=c99 --coverage -ggdb -I$(INCPATH) -Wall -Wpedantic -Wextra -g -c
LFLAGS=--coverage -g -ggdb
UFLAGS=-lcheck
DIR_CR=mkdir -p
INC:=$(wildcard $(INCPATH)*.h)
SRCS := $(wildcard $(SRCPATH)*.c)
OBJS:=$(patsubst $(SRCPATH)%.c,$(OBJPATH)%.o, $(SRCS))
UNITS:=$(patsubst $(UNITTESTSPATH)check%.c, $(OBJPATH)check%.o, $(wildcard $(UNITTESTSPATH)*.c))
UNITS= $(OBJPATH)check_main.o $(OBJPATH)check_insert.o $(OBJPATH)check_sort.o $(OBJPATH)node.o
dep = $(OBJS:.o=.d) 
OUT := $(shell find -type f -name out)


.PHONY: clean func dirs out cppcheck
.NOTPARALLEL: release debug

release: CFLAGS=-std=c99 -I$(INCPATH) -o2 -c
release: LFLAGS=-o2


debug: $(OBJPATH)debug.lastbuildstate app.exe
release: $(OBJPATH)release.lastbuildstate app.exe


unit_tests.exe: CFLAGS=-std=c99 -I$(INCPATH) -Wall -Werror -g3 -c
unit_tests.exe: clean $(UNITS)
	$(CC) -o $@  $(UNITS) $(UFLAGS)
	# valgrind --leak-check=full --show-leak-kinds=all ./unit_tests.exe
	valgrind ./unit_tests.exe


$(OBJPATH)check%.o : $(UNITTESTSPATH)check%.c 
	$(CC) $(CFLAGS) $< -o $@ 

cppcheck: $(SRCS) | out
	cppcheck --std=c99 -q --enable=all -I./inc/ --inconclusive --suppress=missingIncludeSystem ./src/

func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCTESTSPATH) && bash all_test.sh
	@echo
	gcov -n $(OBJPATH)*.o

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


app.exe: $(OBJS) | out
	$(CC) -o $@ $(OBJS) $(LFLAGS) 

$(OBJPATH)%.o: $(SRCPATH)%.c | out
	$(CC) $(CFLAGS) -o $@ $<

$(OBJPATH)%.d : $(SRCPATH)%.c | out
	$(CC) -I$(INCPATH) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

ifneq ($(MAKECMDGOALS), clean)
-include $(dep)
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
