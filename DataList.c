#include "DataList.h"

ListElement *newListElement(int value)
{
    ListElement *el = (ListElement*) malloc(sizeof(ListElement));
    el->val = value;
    el->next = NULL;
    el->prev = NULL;

    return el;
}
DataList *dl_init(void) {
    DataList *dl = (DataList*) malloc(sizeof(DataList));
    dl->size = 0;
    dl->first = NULL;
    dl->last = NULL;
}

int dl_size(DataList* dl) {
    return dl->size;
}
void dl_get(ListElement *dl_el, int n, int *el) {
    if(dl_el == NULL && n != 0) {
        printf("Error: ArrayIndexOutOfBoundsException\n");
        exit (EXIT_FAILURE);
    }
    if (n == 0) {
        *el = dl_el->val;
        return;
    }
    dl_get(dl_el->next, --n, el);
}

void dl_append(DataList* dl, int value) {
    ListElement *new_el = newListElement(value);
    ListElement *dl_ref = dl->first;
    if (dl_ref == NULL) {
        dl->first = new_el;
        dl->last = new_el;
        dl->size += 1;
        return;
    }
    while (dl_ref->next != NULL) {
        dl_ref = dl_ref->next;
    }
    new_el->prev = dl_ref;
    dl_ref->next = new_el;
    dl->last = new_el;
    dl->size += 1;
}

void dl_insert(DataList *dl, int value, int n) {
    ListElement *new_el = newListElement(value);
    ListElement *dl_ref = dl->first;
    int size = dl_size(dl);
    int i = 0;
    if (n < 0) {
        printf("Error: Insert position less than zero\n");
        exit(EXIT_FAILURE);
    }
    if (n > size) {
        printf("Error: Insert position larger than the list size\n");
        exit(EXIT_FAILURE);
    } else if (n == size) {
        dl_append(dl, value);
        return;
    } else if (n == 0) {
        new_el->prev = NULL;
        new_el->next = dl_ref;
        dl_ref->prev = new_el;
        dl->first = new_el;
        dl->size += 1;
        return;
    }
    while (i < (n - 1)) {
        dl_ref = dl_ref->next;
        i += 1;
    }

    new_el->next = dl_ref->next;
    dl_ref->next->prev = new_el;

    dl_ref->next = new_el;
    new_el->prev = dl_ref;
    dl->size += 1;
}

void dl_remove(DataList *dl, int n) {
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
        dl->first->prev = NULL;
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
            printf("head->(%d)", first->val);
        else
            printf("->(%d)", first->val);
        first = first->next;
        i += 1;
    }
    printf("->(NULL)\n");
    printf("\nTraversal in prev direction \n");
    i = 0;
    while (last != NULL) {
        if (i == 0)
            printf("head->(%d)", last->val);
        else
            printf("->(%d)", last->val);
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

void dl_push(DataList *dl, int value)
{
    dl_append(dl, value);
}

bool dl_pop(DataList *dl, int * el)
{
    if (dl->size == 0) {
        return false;
    }
    dl_get(dl->first, dl->size - 1, el);
    dl_remove(dl, dl->size - 1);
    return true;
}

bool dl_peek(DataList *dl, int *el)
{
    if(dl->last == NULL) {
        return false;
    }
    *el = dl->last->val;
    return true;
}

void dl_enqueue(DataList *dl, int value)
{
    dl_insert(dl, value, 0);
}

bool dl_dequeue(DataList *dl, int *el)
{
    if (dl->size == 0) {
        return false;
    }
    *el = dl->first->val;
    dl_remove(dl, 0);
    return true;
}

bool dl_first(DataList *dl, int *el)
{
    if (dl->size == 0) {
        return false;
    }
    *el = dl->first->val;
    return true;
}

