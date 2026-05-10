/* -----------------------------------------
    Contributors: Kevin Usuanlele / Scott Weaver
    ID's: 3103649 / 3144661
    Date: May 7, 2026
    Program: userclean.c
    Description:
    Reference(s):
------------------------------------------*/

# Variables
CC = gcc          # C Compiler
CFLAGS = -Wall -g # Compiler flags
FILES = userclean.c

TARGET = userclean
SRC = userclean.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
    
