#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dl_type int

#include <dlist_type.h>

#include <csmkdlist.h>

DL_APPLY_ALL(dl_type)

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

    // free memory, which we don't need anymore
    free(first);
    free(last);
}


void test_DataList(void) {
	
	DataList *dl = dl_init();
	int *el = (int*)malloc(sizeof(int));
	char c;
	while(1){
		dl_print(dl);
		printf("\n");
		printf("a: in order to push an element\n");
		printf("p: in order to pop an element\n");
		printf("t: in order to see the elment on the top\n");
		printf("e: in order to enqueue an element\n");
		printf("d: in order to dequeue an element\n");
		printf("f: in order to see the first element\n");
		printf("q: to quit!\n");

		printf("dl_size:= %d \n", dl->size);
		printf("enter option:  ");
		scanf("%c", &c);
		int data = rand() % 100;
		if (c == 'a') {
			dl_push(dl, data);
		} else if (c == 'p') {
			dl_pop(dl, el);
			printf("%d \n", *el);
		} else if (c == 't') {
			dl_peek(dl, el);
			printf("%d \n", *el);
		} else if (c == 'e') {
			dl_enqueue(dl, data);
		} else if (c == 'd') {
			dl_dequeue(dl, el);
			printf("%d \n", *el);
		} else if (c == 'f') {
			dl_first(dl, el);
			printf("%d", *el);
		} else if (c == 'q'){
			break;
		}else{
			// nothing to do
		}

	}
}


int main() {
    srand( (unsigned)time(NULL) ); //Initialize the random number generator
    test_DataList();


    return 0;
}



