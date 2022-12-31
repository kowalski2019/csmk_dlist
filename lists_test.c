#include "linkedlist/linkedList.h"
#include "doublelinkedlist/doubleLinkedList.h"

void linkedList_test(void);
void doubleLinkedList_test(void);

int list_main(void)
{
    linkedList_test();
    printf("\nDLL STEP\n\n");
    doubleLinkedList_test();
    return 0;
}

void linkedList_test(void)
{
    LinkedList *list = NULL;
    ll_append(&list,23);
    ll_append(&list,-9);
    ll_append(&list,12);
    ll_append(&list,78);
    ll_append(&list,-9);
    ll_append(&list,100);
    printf("list size must be 6. size = %d\n",ll_size(&list));
    ll_insert(&list,50,0);
    printf("list size must be 7. size = %d\n",ll_size(&list));
    ll_insert(&list,32,ll_size(&list));
    ll_insert(&list,600,5);
    printf("list size must be 8. size = %d\n",ll_size(&list));
    ll_remove(&list,0);
    ll_remove(&list,3);
    printf("list size must be 6. size = %d\n",ll_size(&list));
    ll_print(&list);
    for(int i = 0; i < ll_size(&list);i++){
        printf("list[%d] = %d\n",i,ll_get(&list,i));
    }
    ll_clear(&list);
    printf("list size must be 0. size = %d\n",ll_size(&list));
    ll_append(&list,20);
    printf("list size must be 1. size = %d\n",ll_size(&list));
    ll_print(&list);
}

void doubleLinkedList_test(void)
{
    DoubleLinkedList *dllist = NULL;
    dll_append(&dllist,12);
    dll_append(&dllist,15);
    dll_append(&dllist,-34);
    dll_append(&dllist,-24);
    dll_append(&dllist,-64);
    printf("dllist size must be 5. size = %d\n",dll_size(&dllist));
    dll_insert(&dllist,100,0);
    dll_insert(&dllist,50,5);
    dll_insert(&dllist,200,0);
    dll_insert(&dllist,45,8);
    //dll_print(&dllist);
    printf("dllist size must be 9. size = %d\n",dll_size(&dllist));
    dll_remove(&dllist,0);
    dll_remove(&dllist,4);
    printf("dllist size must be 7. size = %d\n",dll_size(&dllist));
    dll_print(&dllist);
    for(int i = 0; i < dll_size(&dllist); i++){
        printf("dllist[%d] = %d\n",i,dll_get(&dllist,i));
    }
    dll_clear(&dllist);
    printf("dllist size must be 0. size = %d\n",dll_size(&dllist));
    dll_append(&dllist,26);
    dll_append(&dllist,52);
    printf("dllist size must be 2. size = %d\n",dll_size(&dllist));
    dll_print(&dllist);
}
