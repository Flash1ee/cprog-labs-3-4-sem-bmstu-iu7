OBJPATH := ./out/
INCPATH := ./inc/
SRCPATH := ./src/
CC := gcc
CFLAGS := -std=c99 -I$(INCPATH) -Wall -Wextra -Wpedantic
GCOV := --coverage
DEBUG := $(CFLAGS) -g3


.PHONY: clean

app.exe: $(OBJPATH)main.o $(OBJPATH)io.o $(OBJPATH)sort.o 
	$(CC) -o app.exe $(OBJPATH)main.o $(OBJPATH)io.o $(OBJPATH)sort.o

$(OBJPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OBJPATH)main.o

$(OBJPATH)io.o: $(SRCPATH)io.c
	$(CC) $(CFLAGS) -c $(SRCPATH)io.c -o $(OBJPATH)io.o
$(OBJPATH)sort.o: $(SRCPATH)sort.c
	$(CC) $(CFLAGS) -c $(SRCPATH)sort.c -o $(OBJPATH)sort.o

clean:
	rm -rf $(OBJPATH)*.o $(OBJPATH)*.gcno 
	rm app.exe