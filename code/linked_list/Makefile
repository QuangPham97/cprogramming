OUTPUT_DIR = $(PWD)/bin
BINARY = $(PWD)/bin/main
ARFLAGS = rcs
AR = ar 
CC = gcc
CLAGS = -c -Wall -g
CLAG = -g -Wall -Werror -Wstrict-prototypes -lgcov -fprofile-arcs -ftest-coverage --coverage -fstack-protector-all
SRC = $(PWD)/src
INC = 	-I$(PWD)/inc \
		-I$(PWD)/../common/inc/

OUTPUT_LIB = $(PWD)/lib/
TARGET_OUTPUT_LIB = -L$(OUTPUT_LIB) -llinkedlist \
					-L$(PWD)/../common/lib/ -lcommon
TARGET = $(OUTPUT_LIB)liblinkedlist.a 
TARGET_STATIC_LIB = $(TARGET) \
					$(PWD)/../common/lib/libcommon.a
SRCS = $(wildcard $(SRC)/*.c)
OBJECTS	= $(patsubst %.c, $(OUTPUT_LIB)/%.o, $(notdir $(SRCS)))

all: create_dir $(TARGET) $(BINARY) 

create_dir:
	mkdir -p $(OUTPUT_LIB)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
$(OUTPUT_LIB)/%.o: $(SRC)/%.c
	$(CC) $(CLAGS) $< -o $@ $(INC)
$(BINARY):
	$(CC) $(CLAG) $(TARGET_STATIC_LIB) $(TARGET_OUTPUT_LIB) $(INC) -o $(BINARY)
	
.PHONY: clean
clean:
	rm -f $(OUTPUT_LIB)/*
	rm -f $(TARGET)
	rm -f $(BINARY)
print-%:
	@echo $($(subst print-,,$@))
