CC=gcc
TARGET=main
OBJECT=bubble_sort.o
SRC=bubble_sort.c

all: $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) -g -Wall -o $@ $^
$(OBJECT): $(SRC)
	$(CC) -c $<

clean:
	rm -rf $(OBJECT) $(TARGET)
