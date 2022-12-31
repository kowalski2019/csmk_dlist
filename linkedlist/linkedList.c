/**
  ******************************************************************************
  * @file    	LinkedList.c
  * @author		Claude Stephane M. Kouame
  * @version 	V1.0
  * @date		Oct 10, 2021
  * @brief
  * feel free to use it as you wish ;-)
  ******************************************************************************
*/
#include "linkedList.h"

/**
 * @brief LinkedList initialiser
 * @note initializes the list with an initial value
 * @param value for the initial value of the list
 * @retval returns pointer on a LinkedList
 */
LinkedList *ll_init(int value)
{
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->val = value;
    return ll;
}

/**
 * @brief size retriver
 * @note calculate the size of the linkedList
 * @param ll the address of the list
 * @retval returns the size of the linkedlist
 */
int ll_size(LinkedList *ll)
{
    LinkedList *tmp_ll = ll;
    int size = 0;
    while(tmp_ll != NULL){
        size += 1;
        tmp_ll = tmp_ll->next;
    }
    free(tmp_ll);
    return size;
}

/**
 * @brief element retriver
 * @note
 * @param n the position
 * @retval returns the element at the n-position of the list
 */
int ll_get(LinkedList *ll, int n)
{
    if(n == 0)
        return ll->val;
    return ll_get(ll->next,--n);
}

/**
 * @brief element adder
 * @note appends at the end of the list a new element
 * @param ll the address of the list
 * @param value value to append
 */
void ll_append(LinkedList **ll, int value)
{
    LinkedList *new_ell = malloc(sizeof(LinkedList));
    new_ell->val = value;
    LinkedList *ll_ref = *ll;
    if(*ll == NULL)
    {
        *ll = new_ell;
        return;
    }
    while(ll_ref->next != NULL)
    {
        ll_ref = ll_ref->next;
    }
    ll_ref->next = new_ell;
}

/**
 * @brief element insertion
 * @note inserts an new element at the n-position of the list
 * @param ll the address of the list
 * @param value value of the new Element
 * @param n the insertion position of the new element
 */
void ll_insert(LinkedList* ll, int value, int n){
    LinkedList *new_ell = malloc(sizeof(LinkedList));
    new_ell->val = value;
    int i = 0;
    int l_size = ll_size(ll);
    LinkedList *ll_ref = ll;
    if(n < 0)
    {
        printf("Error: Insert position less than zero\n");
        exit(EXIT_FAILURE);
    }
    if(n > l_size)
    {
        printf("Error: Insert position larger than the list size\n");
        exit(EXIT_FAILURE);
    }
    if(n == l_size)
    {
        ll_append(&ll,value);
        return;
    }
    else if(n == 0)
    {
        new_ell->next = ll;
        ll = new_ell;
        return;
    }
    while(i < (n-1))
    {
        ll_ref = ll_ref->next;
        i += 1;
    }
    new_ell->next = ll_ref->next->next;
    ll_ref->next = new_ell;

}

/**
 * @brief element remover
 * @note removes an element at the n-position of the list
 * @param ll the address of the list
 * @param n the remove position of the element
 */
void ll_remove(LinkedList** ll, int n)
{
    int i = 0;
    LinkedList* ll_ref = *ll;
    LinkedList *toFree;
    int l_size = ll_size(*ll);
    if(n >= l_size || n < 0)
    {
        printf("Cannot remove at this index\n");
        exit(EXIT_FAILURE);
    }
    else if(n == 0)
    {
        toFree = *ll;
        *ll = ll_ref->next;
        free(toFree);
        return;
    }
    while(i < (n-1))
    {
        ll_ref = ll_ref->next;
        i += 1;
    }
    toFree = ll_ref->next;
    ll_ref->next = ll_ref->next->next;
    free(toFree);
}

/**
 * @brief list's bouncer
 * @note this function empties completely the list
 * @param ll the address of the list
 */
void ll_clear(LinkedList* ll)
{
    LinkedList *toFree;
    while(ll != NULL)
    {
        toFree = ll;
        ll = ll->next;
        free(toFree);
    }
}

/**
 * @brief list printer
 * @note prints all element of the list
 * @param ll the address of the list
 * @retval none
 */
void ll_print(LinkedList* ll)
{
    LinkedList *tmp_ll = ll;
    int i = 0;
    while(tmp_ll != NULL)
    {
        if(i == 0)
            printf("head->(%d)",tmp_ll->val);
        else
            printf("->next(%d)",tmp_ll->val);
        tmp_ll = tmp_ll->next;
        i += 1;
    }
    printf("->next(NULL)\n");
    free(tmp_ll);
}
