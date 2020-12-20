CC=gcc
INCPATH=./inc/
OBJPATH=./out/
SRCPATH=./src/
LIBPATH=./lib/
LIB_HEADERS=-I$(LIBPATH)
FUNCTESTSPATH:=./func_tests/
UNITTESTSPATH:=./unit_tests/
CFLAGS=-std=c99 --coverage -ggdb -I$(INCPATH) -Wall -Wpedantic -Wextra -g3 -c
LFLAGS=--coverage
UFLAGS=-lcheck -lsubunit -lrt -lm -lpthread 
DIR_CR=mkdir -p
OBJS= $(OBJPATH)key.o $(OBJPATH)io.o $(OBJPATH)sort.o $(OBJPATH)arr.o
UNITS= $(OBJPATH)check_main.o $(OBJPATH)check_key.o $(OBJPATH)check_sort.o $(OBJPATH)sort.o $(OBJPATH)key.o

inc = $(wildcard $(INCPATH)*.h)
src = $(wildcard $(SRCPATH)*.c)
obj = $(src:$(SRCPATH)%.c=$(OBJPATH)%.o)

lib_src = $(wildcard $(LIBPATH)*.c)
lib_obj= $(lib_src:.c=.o)
lib_stat = $(LIBPATH)libarr.a
lib_dyn = $(LIBPATH)libarr.so
lib_flags=
dep = $(obj:.o=.d) 
OUT := $(shell find -type f -name out)

VARIANTS=func dirs out dyn_build dyn_load release debug
.PHONY: clean func dirs out dyn_build dyn_load release debug
.NOTPARALLEL: release debug

release: CFLAGS=-std=c99 -I$(INCPATH) -o2 -c
release: LFLAGS=-o2


debug: $(OBJPATH)debug.lastbuildstate app.exe
release: $(OBJPATH)release.lastbuildstate app.exe

dyn_build: lib_flags=-fPIC
dyn_load: CFLAGS += -D DYN_LOAD

unit_tests.exe: CFLAGS=-std=c99 -I$(INCPATH) -Wall -Werror -g3 -c
unit_tests.exe: clean $(UNITS) $(lib_stat)
	$(CC) -o $@  $(UNITS) -L$(LIBPATH) -larr $(UFLAGS)
	valgrind --leak-check=full ./unit_tests.exe


$(OBJPATH)check%.o : $(UNITTESTSPATH)check%.c 
	$(CC) $(CFLAGS) -I$(LIBPATH) $< -o $@ 


func: debug | out
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


app.exe: $(obj) $(lib_stat) | out
	$(CC) -o $@ $(obj) -L$(LIBPATH) -larr $(LFLAGS) 

dyn_build: $(obj) $(lib_dyn) | out
	$(CC) -o app.exe $(obj) -L$(LIBPATH) -larr $(LFLAGS)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(LIBPATH)

dyn_load: $(obj) $(lib_dyn) | out
	$(CC) -o app.exe $(obj) -ldl $(LFLAGS)

$(lib_dyn): $(lib_obj)
	$(CC) -o $@ -shared $^

$(OBJPATH)%.o: $(SRCPATH)%.c | out
	$(CC) $(CFLAGS) $(LIB_HEADERS) -o $@ $<

$(OBJPATH)%.d : $(SRCPATH)%.c | out
	$(CC) -I$(INCPATH) $(LIB_HEADERS) -MM -MT $(patsubst %.d,%.o,$@) $< > $@

$(lib_stat): $(lib_obj) 
	ar rcs -o $@ $^ 

$(LIBPATH)%.o : $(LIBPATH)%.c $(LIBPATH)%.h
	$(CC) $(lib_flags) -c -o $@ $<

ifneq ($(MAKECMDGOALS), $(VARIANTS))
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
	rm -fv $(LIBPATH)*.o
	rm -fv $(LIBPATH)*.a
	rm -fv $(LIBPATH)*.gcno
	rm -fv $(LIBPATH)*.so
