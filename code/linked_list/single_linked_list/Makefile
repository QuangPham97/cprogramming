CC=gcc
CFLAGS= -g -Wall
INC= -I.
TARGET= main
OBJECT= single_linked_list.o main.o
SRC= single_linked_list.c main.c
DEPS= single_linked_list.h
%.o: %.c $(DEPS) 
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)
main: $(OBJECT) 
	$(CC) $(CFLAGS) -o $@ $^ $(INC)
clean:
	rm -rf *.o