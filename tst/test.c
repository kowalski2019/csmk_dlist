#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "csmkdlist.h"

APPLY_DATATYPE(int);


void test_DataList(void) {
	return;
	/*DataList *dl = dl_init();

	char c ;
	DLIST_Integer el;
	while(1){
		dl_print(dl);
		printf("\n");
		printf("a: in order to push an element\n");
		printf("b: in order to pop an element\n");
		printf("c: in order to see the elment on the top\n");
		printf("d: in order to enqueue an element\n");
		printf("e: in order to dequeue an element\n");
		printf("f: in order to see the first element\n");
		printf("q: to quit!\n");

		printf("dl_size:= %d \n", dl->size);
		printf("enter option:  ");
		scanf("%c", &c);
        DLIST_Integer data = dlist_new_integer(rand() % 100);
		if (c == 'a') {
			dl_push(dl, (void*)data);
		} else if (c == 'b') {
			dl_pop(dl, (void**)&el);
			printf("%d \n", el->value);
		} else if (c == 'c') {
			dl_peek(dl, (void**)&el);
			printf("%d \n", el->value);
		} else if (c == 'd') {
			dl_enqueue(dl, (void*)data);
		} else if (c == 'e') {
			dl_dequeue(dl, (void**)&el);
			printf("%d \n", el->value);
		} else if (c == 'f') {
			dl_first(dl, (void**)&el);
			printf("%d", el->value);
		} else if (c == 'q'){
			break;
		}else{
			// nothing to do
		}

	}*/
}


int main() {
    srand( (unsigned)time(NULL) ); //Initialize the random number generator
    test_DataList();


    return 0;
}



