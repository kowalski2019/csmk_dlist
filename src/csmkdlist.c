/**
  ******************************************************************************
  * @file     csmkdlist.c
  * @author   Claude Stephane M. Kouame <claude.kouame@csmk59.de>
  * @version  V1.0.0
  * @date     Oct 10, 2021
  * @ref      https://github.com/kowalski2019/csmk_dlist
  * @brief
  * feel free to use it as you wish ;-)
  ******************************************************************************
*/

#include "csmkdlist.h"

DataList *dl_init(void) {
    DataList *dl = (DataList *) malloc(sizeof(DataList));
    dl->size = 0;
    dl->first = NULL;
    dl->last = NULL;
    return dl;
}

int dl_size(DataList *dl) {
    return dl->size;
}

void dl_remove_at(DataList *dl, int n) {
    int i = 0;
    ListElement *dl_ref = dl->first;
    ListElement *toFree;
    int size = dl_size(dl);
    if (n >= size || n < 0) {
        printf("Error: Cannot remove at this index\n");
        exit(EXIT_FAILURE);
    } else if (n == 0) {
        toFree = dl->first;
        dl->first = dl_ref->next;
        if (dl->first != NULL)
            dl->first->prev = NULL;
        else {
            dl->last = NULL;
        }
        dl->size -= 1;
        /* free memory, which we don't need anymore */
        free(toFree);
        return;
    }
    while (i < (n - 1)) {
        dl_ref = dl_ref->next;
        i += 1;
    }
    toFree = dl_ref->next;
    dl_ref->next = dl_ref->next->next;
    if (dl_ref->next != NULL)
        dl_ref->next->prev = dl_ref;
    else {
        dl->last = dl_ref;
    }
    dl->size -= 1;
    /* free memory, which we don't need anymore */
    free(toFree);
}

void dl_clear(DataList *dl) {
    ListElement *toFree;
    ListElement *dl_el = dl->first;
    while (dl_el != NULL) {
        toFree = dl_el;
        dl_el = dl_el->next;

        /* free memory, which we don't need anymore */
        free(toFree);
        dl->size -= 1;
    }
}


