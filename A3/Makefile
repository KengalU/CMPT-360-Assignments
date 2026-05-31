#/*
 #* Student Name: Kevin Usuanlele / Scott Weaver
 #* Student ID:   3103649 / 3144661
 #* Date:         May 18, 2026
 #* File:         Makefile
 #* Description:  Makefile for A2 - CPU vsimuling Simulator
 #*/

# Variables
CC := gcc-13          # C Compiler
CFLAGS := -std=c11 -Wall -Wextra -pedantic -O2 -g # Compiler flags
LDFLAGS :=

# Valgrind
VALGRIND ?= valgrind
VGFLAGS ?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1

.PHONY: all clean checkbb checkseg valgrind vg

all: vsim 

vsim: vsim.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

vsim.o: vsim.c vsim.h
	$(CC) $(CFLAGS) -c $<

checkbb: vsim
	./vsim --mode=bb  --base=1000 --limit=2000 --trace=t1.txt

checkseg: vsim
	./vsim --mode=seg --config=three-seg.ini --trace=t2.txt

valgrind: vsim
	$(VALGRIND) $(VGFLAGS) ./vsim --mode=bb  --base=1000 --limit=2000 --trace=t1.txt
	$(VALGRIND) $(VGFLAGS) ./vsim --mode=seg --config=three-seg.ini --trace=t2.txt

vg: valgrind

clean:
	rm -f vsim vsim.o
