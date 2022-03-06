CC=gcc
CFLAG= -gdwarf-3 -Wall
FILE_OBJ= lecture_2.o
FILE_BIN=lecture_2
FILE_BUILD=lecture_2.c
all: $(FILE_BIN)
$(FILE_BIN): $(FILE_OBJ)
	$(CC) $(CFLAG) $(FILE_OBJ) -o $(FILE_BIN)
$(FILE_OBJ): $(FILE_BUILD)
	$(CC) $(CFLAG) -c $(FILE_BUILD) -o $(FILE_OBJ)
clean:
	rm -rf $(FILE_OBJ) $(FILE_BIN)
