CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror
EXEC = invader
OBJECTS = main.o 

.PHONY: default

default: $(EXEC) clean


projet.o: main.c

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $^

clean:
	rm $(OBJECTS)
