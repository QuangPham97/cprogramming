CC=gcc
CFLAG= -gdwarf-3 -Wall
FILE_OBJ= lecture_1.o
FILE_BIN=lecture_1
FILE_BUILD=lecture_1.c
all: $(FILE_BIN)
$(FILE_BIN): $(FILE_OBJ)
	$(CC) $(CFLAG) $(FILE_OBJ) -o $(FILE_BIN)
$(FILE_OBJ): $(FILE_BUILD)
	$(CC) -c $(FILE_BUILD) -o $(FILE_OBJ)
clean:
	rm -rf $(FILE_OBJ) $(FILE_BIN)
