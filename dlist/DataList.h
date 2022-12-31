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

#define DECLARE_LIST_ELEMENT_STRUCT(dataType)  \
    typedef struct listElement {           \
        dataType data;                       \
        struct listElement *prev;             \
        struct listElement *next;             \
    } ListElement;

#define DECLARE_DATALIST_STRUCT \
    typedef struct { \
        int size; \
        ListElement * first; \
        ListElement *last; \
    } DataList; \


#include "DataListType.h"

DECLARE_LIST_ELEMENT_STRUCT(dl_type)
DECLARE_DATALIST_STRUCT


//ListElement *newListData(int value);
#define DEFINE_NEW_LIST_DATA_FUNCTION(dataType) \
ListElement *newListData(dataType value) { \
    ListElement *el = (ListElement *) malloc(sizeof(ListElement)); \
    el->data = value; \
    el->next = NULL; \
    el->prev = NULL; \
    return el; \
}

DataList *dl_init(void);

int dl_size(DataList *);

//void dl_get(ListElement *dl_el, int n, int * el);
#define DEFINE_DL_GET_FUNCTION(dataType) \
void dl_get(ListElement *dl_el, int n, dataType *el) { \
    if (dl_el == NULL && n != 0) { \
        printf("Error: ArrayIndexOutOfBoundsException\n"); \
        exit(EXIT_FAILURE);                  \
    }                                    \
    if (n == 0) {                        \
        *el = dl_el->data;  \
        return; \
    } \
    dl_get(dl_el->next, --n, el); \
}

//void dl_append(DataList*, int);
#define DEFINE_DL_APPEND_FUNCTION(dataType) \
    void dl_append(DataList *dl, dataType value) { \
        ListElement *new_el = newListData(value); \
        ListElement *dl_ref = dl->first; \
        if (dl_ref == NULL) {   \
            dl->first = new_el; \
            dl->last = new_el;  \
            dl->size += 1;  \
            return; \
        } \
        while (dl_ref->next != NULL) { \
            dl_ref = dl_ref->next; \
        } \
        new_el->prev = dl_ref; \
        dl_ref->next = new_el; \
        dl->last = new_el; \
        dl->size += 1; \
    }

#define DEFINE_DL_FASTER_APPEND_FUNCTION(dataType) \
    void dl_faster_append(DataList *dl, dataType value) { \
        ListElement *new_el = newListData(value);  \
        if (dl->first == NULL) {                   \
         dl->first = new_el;                       \
         dl->last = new_el;                        \
         dl->size += 1;                            \
         return;\
        }\
        dl->last->next = new_el;                   \
        new_el->prev = dl->last;                                           \
        dl->last = new_el;                          \
        dl->size += 1; \
    }

//void dl_insert(DataList *dl, int value, int n);
#define DEFINE_DL_INSERT_FUNCTION(dataType) \
 void dl_insert(DataList *dl, dataType value, int n) { \
    ListElement *new_el = newListData(value); \
    ListElement *dl_ref = dl->first; \
    int size = dl_size(dl); \
    int i = 0; \
    if (n < 0) { \
        printf("Error: Insert position less than zero\n"); \
        exit(EXIT_FAILURE); \
    } \
    if (n > size) { \
        printf("Error: Insert position larger than the list size\n"); \
        exit(EXIT_FAILURE); \
    } else if (n == size) { \
        dl_faster_append(dl, value); \
        return; \
    } else if (n == 0) { \
        new_el->prev = NULL; \
        new_el->next = dl_ref; \
        dl_ref->prev = new_el; \
        dl->first = new_el; \
        dl->size += 1; \
        return; \
    } \
    while (i < (n - 1)) { \
        dl_ref = dl_ref->next; \
        i += 1; \
    }                                       \
    new_el->next = dl_ref->next; \
    dl_ref->next->prev = new_el; \
        \
    dl_ref->next = new_el; \
    new_el->prev = dl_ref; \
    dl->size += 1; \
}


void dl_remove_at(DataList *dl, int);
#define DEFINE_DL_REMOVE(dataType) \
    void dl_remove(DataList *dl, dataType){ \
    }

#define DEFINE_DL_INDEX_OF(dataType) \
    int dl_index_of(DataList *dl, dataType){ \
        return -1                                 \
    }\

void dl_clear(DataList *dl);

void dl_print(DataList *dl);


/* STACK UTILITY */

//void dl_push(DataList *dl, int value);
#define DEFINE_DL_PUSH_FUNCTION(dataType) \
    void dl_push(DataList *dl, dataType value) { \
        dl_faster_append(dl, value); \
}


//bool dl_pop(DataList *dl, int *el);
#define DEFINE_DL_TOP_FUNCTION(dataType) \
    bool dl_pop(DataList *dl, dataType *el) { \
        if (dl->size == 0) { \
            return false; \
        } \
        dl_get(dl->first, dl->size - 1, el); \
        dl_remove_at(dl, dl->size - 1); \
        return true; \
}

//bool dl_peek(DataList *dl, int *el);
#define DEFINE_DL_PEEK_FUNCTION(dataType) \
    bool dl_peek(DataList *dl, dataType *el) { \
        if (dl->last == NULL) { \
            return false; \
        } \
        *el = dl->last->data; \
        return true; \
}

/* QUEUE UTILITY */

//void dl_enqueue(DataList *dl, int value);
#define DEFINE_DL_ENQUEUE_FUNCTION(dataType) \
    void dl_enqueue(DataList *dl, dataType value) { \
        dl_insert(dl, value, 0); \
    }


// bool dl_dequeue(DataList *dl, int *el);
#define DEFINE_DL_DEQUEUE_FUNCTION(dataType) \
    bool dl_dequeue(DataList *dl, dataType *el) { \
        if (dl->size == 0) { \
            return false; \
        } \
        *el = dl->first->data; \
        dl_remove_at(dl, 0); \
        return true; \
}

//bool dl_first(DataList *dl, int *el);
#define DEFINE_DL_FIRST_FUNCTION(dataType) \
    bool dl_first(DataList *dl, dataType *el) { \
        if (dl->size == 0) { \
            return false; \
        } \
        *el = dl->first->data; \
        return true; \
}

#define APPLY_DATATYPE(dataType) \
    DEFINE_NEW_LIST_DATA_FUNCTION(dataType) \
    DEFINE_DL_GET_FUNCTION(dataType) \
    DEFINE_DL_APPEND_FUNCTION(dataType) \
    DEFINE_DL_FASTER_APPEND_FUNCTION(dataType) \
    DEFINE_DL_INSERT_FUNCTION(dataType) \
    DEFINE_DL_PUSH_FUNCTION(dataType) \
    DEFINE_DL_TOP_FUNCTION(dataType) \
    DEFINE_DL_PEEK_FUNCTION(dataType) \
    DEFINE_DL_ENQUEUE_FUNCTION(dataType) \
    DEFINE_DL_DEQUEUE_FUNCTION(dataType) \
    DEFINE_DL_FIRST_FUNCTION(dataType) \


#endif /* DATALIST_H */
