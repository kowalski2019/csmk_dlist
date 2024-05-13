#
# Makefile for csmkdlist test
#

BUILD = ../build

CC = gcc
CFLAGS = -std=c11 -g -Wall -I$(BUILD)/include
LDFLAGS = -g -std=c11 -Wall -L$(BUILD)/lib
LDLIBS = -lcsmkdlist

all:	test

install:	all
		mkdir -p $(BUILD)/bin
		cp test $(BUILD)/bin

test:	test.o 
		$(CC) $(LDFLAGS) -o test test.o $(LDLIBS)

test.o:	test.c
		$(CC) $(CFLAGS) -o test.o -c test.c

clean:
		rm -f *~ test.o test
