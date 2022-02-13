#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList
{
    int val;
    struct linkedList *next;
    int ll_size;
    int ll_get;
    /*void ll_append;
    void ll_insert;
    void ll_remove;
    void ll_clear;
    void ll_print;*/

} LinkedList;


LinkedList *ll_init(int);
int ll_size(LinkedList*);
int ll_get(LinkedList*, int);
void ll_append(LinkedList**, int);
void ll_insert(LinkedList*, int, int);
void ll_remove(LinkedList**, int);
void ll_clear(LinkedList*);
void ll_print(LinkedList*);


#endif /* LINKEDLIST_H */
