#include "doubleLinkedList.h"

/**
 * @brief DoubleLinkedList initialiser
 * @note initializes the list with an initial value
 * @param value for the initial value of the list
 */
DoubleLinkedList *dll_init(int value) {
    DoubleLinkedList *dll = malloc(sizeof(DoubleLinkedList));
    dll->val = value;
    dll->prev = NULL;
    dll->next = NULL;
    return dll;
}

/**
 * @brief size retriever
 * @note returns the size of the doubleLinkedList
 * @param dll the address of the list
 */
int dll_size(DoubleLinkedList *dll) {
    DoubleLinkedList *tmp_dll = dll;
    int size = 0;
    while (tmp_dll != NULL) {
        size += 1;
        tmp_dll = tmp_dll->next;
    }

    /* free memory, which we don't need anymore */
    free(tmp_dll);

    return size;
}

/**
 * @brief element retriever
 * @note returns the element at the n-position of the list
 * @param dll the address of the list
 * @param n the position
 */
int dll_get(DoubleLinkedList *dll, int n) {
    if (n == 0)
        return dll->val;
    return dll_get(dll->next, --n);
}

/**
 * @brief element adder
 * @note appends at the end of the list a new element
 * @param dll the address of the list
 * @param value value to append
 */
void dll_append(DoubleLinkedList **dll, int value) {

    DoubleLinkedList *new_ell = dll_init(value);
    DoubleLinkedList *dll_ref = *dll;
    if (*dll == NULL) {
        *dll = new_ell;
        return;
    }
    while (dll_ref->next != NULL) {
        dll_ref = dll_ref->next;
    }
    new_ell->prev = dll_ref;
    dll_ref->next = new_ell;
}

/**
 * @brief element insertion
 * @note inserts an new element at the n-position of the list
 * @param dll the address of the list
 * @param value value of the new Element
 * @param n the insertion position of the new element
 */
void dll_insert(DoubleLinkedList **dll, int value, int n) {
    DoubleLinkedList *new_ell = malloc(sizeof(DoubleLinkedList));
    new_ell->val = value;
    int i = 0;
    DoubleLinkedList *dll_ref = *dll;
    int dl_size = dll_size(*dll);
    if (n < 0) {
        printf("Error: Insert position less than zero\n");
        exit(EXIT_FAILURE);
    }
    if (n > dl_size) {
        printf("Error: Insert position larger than the list size\n");
        exit(EXIT_FAILURE);
    } else if (n == dl_size) {
        dll_append(dll, value);
        return;
    } else if (n == 0) {
        new_ell->prev = NULL;
        new_ell->next = dll_ref;
        dll_ref->prev = new_ell;
        *dll = new_ell;
        return;
    }
    while (i < (n - 1)) {
        dll_ref = dll_ref->next;
        i += 1;
    }

    new_ell->next = dll_ref->next;
    dll_ref->next->prev = new_ell;

    dll_ref->next = new_ell;
    new_ell->prev = dll_ref;
}

/**
 * @brief element remover
 * @note removes an element at the n-position of the list
 * @param dll the address of the list
 * @param n the remove position of the element
 */
void dll_remove(DoubleLinkedList **dll, int n) {
    int i = 0;
    DoubleLinkedList *dll_ref = *dll;
    DoubleLinkedList *toFree;
    int dl_size = dll_size(*dll);
    if (n >= dl_size || n < 0) {
        printf("Cannot remove at this index\n");
        exit(EXIT_FAILURE);
    } else if (n == 0) {
        toFree = *dll;
        *dll = dll_ref->next;
        (*dll)->prev = NULL;

        /* free memory, which we don't need anymore */
        free(toFree);
        return;
    }
    while (i < (n - 1)) {
        dll_ref = dll_ref->next;
        i += 1;
    }
    toFree = dll_ref->next;
    dll_ref->next = dll_ref->next->next;
    dll_ref->next->prev = dll_ref;

    /* free memory, which we don't need anymore */
    free(toFree);
}

/**
 * @brief list's bouncer
 * @note this function empties completely the list
 * @param dll the address of the list
 */
void dll_clear(DoubleLinkedList **dll) {
    DoubleLinkedList *toFree;
    while (*dll != NULL) {
        toFree = *dll;
        *dll = (*dll)->next;

        /* free memory, which we don't need anymore */
        free(toFree);
    }
}

/**
 * @brief list printer
 * @note prints all element of the list in both direction(right and left)
 * @param dll the address of the list
 */
void dll_print(DoubleLinkedList **dll) {
    DoubleLinkedList *tmp_dll = *dll;
    int i = 0;
    DoubleLinkedList *last;
    printf("\nTraversal in next direction \n");
    while (tmp_dll != NULL) {
        last = tmp_dll;
        if (i == 0)
            printf("head->(%d)", tmp_dll->val);
        else
            printf("->(%d)", tmp_dll->val);
        tmp_dll = tmp_dll->next;
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
    free(tmp_dll);
    free(last);
}
bool pop(DoubleLinkedList** dll, int * el)
{

}
