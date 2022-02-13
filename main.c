#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataList.h"

void test_DataList(void) {

}

int main() {
    srand( (unsigned)time(NULL) ); //Initialize the random number generator

    DataList *dl = dl_init();
    for ( int i=0; i < 10; i ++)
        dl_push(dl,rand( ) % 100);

    dl_print(dl);
    int l;
    dl_first(dl, &l);
    dl_print(dl);
    printf("fi := %d \n", l);
    //dl_print(dl);
    int index = 5;
    printf("dl size := %d \n", dl_size(dl));
    int res;
    dl_get(dl->first, index, &res);
    printf("dl[%d] := %d \n", index, res);
    return 0;
}



