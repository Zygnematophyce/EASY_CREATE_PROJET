CC = gcc
CFLAGS = -std=c11 -W -Wall
objects = $(patsubst %.c, %.o, $(wildcard *.c))

create_project : $(objects)
	gcc $(CFLAGS) -o create_project $(objects)

create_project.o : create_project.c
	gcc $(CFLAGS) -c create_project.c

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o create_project
