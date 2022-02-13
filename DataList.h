#ifndef DATALIST_H
#define DATALIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct listElement {
    int val;
    struct listElement *prev;
    struct listElement *next;
} ListElement;


typedef struct dataList
{
    int size;
    ListElement *first;
    ListElement *last;
} DataList;

ListElement *newListElement(int value);
DataList *dl_init(void);
int dl_size(DataList*);
void dl_get(ListElement *dl_el, int n, int * el);
void dl_append(DataList*, int);
void dl_insert(DataList *dl, int value, int n);
void dl_remove(DataList *dl, int);
void dl_clear(DataList *dl);
void dl_print(DataList *dl);

/* STACK UTILITY */
void dl_push(DataList *dl, int value);
bool dl_pop(DataList *dl, int *el);
bool dl_peek(DataList *dl, int *el);

/* QUEUE UTILITY */

void dl_enqueue(DataList *dl, int value);
bool dl_dequeue(DataList *dl, int *el);
bool dl_first(DataList *dl, int *el);


#endif /* DATALIST_H */