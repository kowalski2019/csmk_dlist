#
# Makefile for csmk data list library
#

BUILD = ../build

CC = gcc
CFLAGS = -g -Wall -std=c11

all:		dlist_type.h csmkdlist.h libcsmkdlist.a

install:	all
		mkdir -p $(BUILD)/include
		cp dlist_type.h $(BUILD)/include
		cp csmkdlist.h $(BUILD)/include
		mkdir -p $(BUILD)/lib
		cp libcsmkdlist.a $(BUILD)/lib

libcsmkdlist.a:	csmkdlist.o
		ar -crs libcsmkdlist.a csmkdlist.o

csmkdlist.o:	csmkdlist.c csmkdlist.h dlist_type.h
		$(CC) $(CFLAGS) -o csmkdlist.o -c csmkdlist.c

clean:
		rm -f *~ csmkdlist.o libcsmkdlist.a
