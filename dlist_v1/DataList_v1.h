/**
  ******************************************************************************
  * @file    	DataList.h
  * @author		Claude Stephane M. Kouame
  * @version 	V1.0
  * @date		Oct 10, 2021
  * @brief
  * feel free to use it as you wish ;-)
  ******************************************************************************
*/

#ifndef DATALIST_H
#define DATALIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "dlist_types.h"


typedef struct listElement {
    void *data;
    struct listElement *prev;
    struct listElement *next;
} ListElement;


typedef struct {
    int size;
    ListElement *first;
    ListElement *last;
} *DataList;


ListElement *newListData(void *value);

DataList dl_init(void);

int dl_size(DataList);

void dl_get(ListElement *dl_el, int n, void **el);

void dl_append(DataList, void *);

void dl_faster_append(DataList dl, void *value);

void dl_insert(DataList dl, void *value, int n);

void dl_remove_at(DataList dl, int);

void dl_remove(DataList dl, void *el);

int dl_index_of(DataList dl, void *el);

void dl_clear(DataList dl);

void dl_print(DataList dl);


/* STACK UTILITY */
void dl_push(DataList dl, void *value);

bool dl_pop(DataList dl, void **el);

bool dl_peek(DataList dl, void **el);

/* QUEUE UTILITY */

void dl_enqueue(DataList dl, void *value);

bool dl_dequeue(DataList dl, void **el);

bool dl_first(DataList dl, void **el);


#endif /* DATALIST_H */
