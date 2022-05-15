#include "DataList.h"

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

void dl_print(DataList *dl) {
    ListElement *first = dl->first;
    ListElement *last = dl->last;
    int i = 0;
    printf("\nTraversal in next direction \n");
    while (first != NULL) {
        if (i == 0)
            printf("head->(%d)", first->data);
        else
            printf("->(%d)", first->data);
        first = first->next;
        i += 1;
    }
    printf("->(NULL)\n");
    printf("\nTraversal in prev direction \n");
    i = 0;
    while (last != NULL) {
        if (i == 0)
            printf("head->(%d)", last->data);
        else
            printf("->(%d)", last->data);
        last = last->prev;
        i += 1;
    }
    printf("->(NULL)\n");

    /* free memory, which we don't need anymore */
    free(first);
    free(last);
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


