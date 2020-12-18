CC=gcc
CFLAGS=-std=c99 -Wall -Werror
LIBPATH=./lib/
lib_src=$(wildcard $(LIBPATH)*.c)
lib_obj=$(lib_src:.c=.o)

.PHONY: clean lib

lib: $(lib_obj)
	$(CC) -shared -o $(LIBPATH)libarr.so $^

$(LIBPATH)%.o : $(LIBPATH)%.c $(LIBPATH)%.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@


clean:
	rm -fv $(LIBPATH)*.o
	rm -fv $(LIBPATH)*.so
