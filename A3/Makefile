#/*
 #* Student Name: Kevin Usuanlele / Scott Weaver
 #* Student ID:   3103649 / 3144661
 #* Date:         May 18, 2026
 #* File:         Makefile
 #* Description:  Makefile for A3 - CPU vmsimuling Simulator
 #*/

# Variables
CC := gcc-13          # C Compiler
CFLAGS := -std=c11 -Wall -Wextra -pedantic -O2 -g # Compiler flags
LDFLAGS :=

# Valgrind
VALGRIND ?= valgrind
VGFLAGS ?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1

.PHONY: all clean checkbb checkseg valgrind vg

all: vmsim 

vmsim: vmsim.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

vmsim.o: vmsim.c vmsim.h
	$(CC) $(CFLAGS) -c $<

checkbb: vmsim
	./vmsim --mode=bb  --base=4096 --limit=64 --trace=t1.txt

checkseg: vmsim
	./vmsim --mode=seg --config=three-seg.ini --trace=t2.txt

valgrind: vmsim
	$(VALGRIND) $(VGFLAGS) ./vmsim --mode=bb  --base=4096 --limit=64 --trace=t1.txt
	$(VALGRIND) $(VGFLAGS) ./vmsim --mode=seg --config=three-seg.ini --trace=t2.txt

vg: valgrind

clean:
	rm -f vmsim vmsim.o
