CC=gcc
CFLAGS= -g -Wall
INC= -I./inc/
TARGET= main
OBJECT= double_linked_list.o main.o
SRC= double_linked_list.c main.c
DEPS= double_linked_list.h
%.o: %.c $(DEPS) 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
main: $(OBJECT) 
	$(CC) $(CFLAGS) $(INC) -o $@ $^
clean:
	rm -rf *.o