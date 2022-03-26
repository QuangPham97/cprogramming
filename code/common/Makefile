CLAGS = -c -Wall -g
CLAG = -g -Wall -Werror -Wstrict-prototypes -lgcov -fprofile-arcs -ftest-coverage --coverage -fstack-protector-all
SRC = $(PWD)/src
INC = 	-I$(PWD)/inc 
OUTPUT_LIB = $(PWD)/lib/
SRCS = $(wildcard $(SRC)/*.c)
OBJECTS	= $(patsubst %.c, $(OUTPUT_LIB)/%.o, $(notdir $(SRCS)))

TARGET = $(OUTPUT_LIB)libcommon.a 
all: create_dir $(TARGET)

create_dir:
	mkdir -p $(OUTPUT_LIB)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
$(OUTPUT_LIB)/%.o: $(SRC)/%.c
	$(CC) $(CLAGS) $< -o $@ $(INC)
