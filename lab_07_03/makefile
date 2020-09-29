# Компилятор 
CC := gcc



# Пути к файлам / файлы
OBJ := ./out/
INC := ./inc/
FUNCPATH := ./func_tests/
UNITPATH := ./unit_tests/

SRC_DEP := $(wildcard $(INC)*.c)
OBJ_DEP := $(SRC_DEP:*.c = *.o)
DEP := $(OBJ_DEP:*.o = *.d)


# Флаги компиляции
CFLAGS := -std=c99 -I$(INC) -Wall -Werror -Wpedantic -Wextra -g3 -c
LFLAGS := --coverage

.PHONY : clean func unit
.NOTPARALLEL: debug release

release: 
    CFLAGS=-std=c99 -I$(INC) -o2 -c
    LFLAGS = -o2

debug: $(OBJ)debug.lastbuildstate app.exe

$(OBJ)debug.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OBJ)*.o
	rm -fv $(OBJ)*.gcno
	rm -fv $(OBJ)*.gcda
	rm -fv $(OBJ)release.lastbuildstate
	touch $(OBJ)debug.lastbuildstate

$(OBJ)release.lastbuildstate:
	rm -fv *.exe
	rm -fv $(OBJ)*.o
	rm -fv $(OBJ)*.gcno
	rm -fv $(OBJ)*.gcda
	rm -fv $(OBJ)debug.lastbuildstate
	touch $(OBJ)release.lastbuildstate

app.exe: $(OBJ_DEP)
    $(CC) $(LFLAGS) -o $@ $^

#$(OBJ_DEP): $(SRC_DEP)
 #   $(CC) $(CFLAGS) -c $<

$(DEP):$(SRC_DEP)
	$(CC) -MMD $< > $@

include $(SRC_DEP:.c=.d)

func:
	$(OBJ)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCPATH) && cmd //C all_test.cmd
	@echo
	gcov -n $(OBJ)*.o


clean:
	rm -fv *.exe
	rm -fv $(OBJ)*.o
	rm -fv $(OBJ)*.gcno
	rm -fv $(OBJ)*.gcda
	rm -fv $(OBJ)*.lastbuildstate