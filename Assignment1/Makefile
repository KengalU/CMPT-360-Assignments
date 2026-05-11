#/* -----------------------------------------
#    Contributors: Kevin Usuanlele / Scott Weaver
#    ID's: 3103649 / 3144661
#    Date: May 10, 2026
#------------------------------------------*/

# Variables
CC := gcc-13          # C Compiler
CFLAGS := -std=c11 -Wall -Wextra -pedantic -O2 -g # Compiler flags
LDFLAGS :=

# Valgrind
VALGRIND ?= valgrind
VGFLAGS ?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1

.PHONY: all clean check valgrind vg

all: userclean

userclean: userclean.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

userclean.o: userclean.c
	$(CC) $(CFLAGS) -c $<

check: userclean
	@echo 'Bob123' | ./userclean
	@echo 'a!' | ./userclean
	@echo 'Admin 42' | ./userclean
	@echo 'root user' | ./userclean
	@echo '_99' | ./userclean

valgrind: userclean
	$(VALGRIND) $(VGFLAGS) ./userclean < tests/input.txt

vg: valgrind

clean:
	rm -f userclean userclean.o
