CC=gcc
INCPATH=./inc/
OBJPATH=./out/
SRCPATH=./src/
FUNCTESTSPATH:=./func_tests/
CFLAGS=-std=c99 --coverage -ggdb -I$(INCPATH) -Wall -Wpedantic -Wextra -g -c 
LFLAGS=--coverage -lm
DIR_CR=mkdir -p
INC:=$(wildcard $(INCPATH)*.h)
SRCS := $(wildcard $(SRCPATH)*.c)
OBJS:=$(patsubst $(SRCPATH)%.c,$(OBJPATH)%.o, $(SRCS))
dep = $(OBJS:.o=.d) 
OUT := $(shell find -type f -name out)

.PHONY: run build func dirs out

build: app.exe | out
	@echo BUILD SUCCESS

run: app.exe | out
	./app.exe

func: cppcheck build
	@echo
	cd $(FUNCTESTSPATH) && bash all_test.sh
	@echo
	gcov -n $(OBJPATH)main.o
	gcov -n $(OBJPATH)matrix.o


cppcheck: $(SRCS)
	cppcheck --std=c99 -q --enable=all -I./inc --inconclusive --suppress=missingIncludeSystem .

app.exe : $(OBJS)
	$(CC) -o app.exe $(OBJS) $(LFLAGS) 

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
