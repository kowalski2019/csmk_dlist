#include <stdlib.h>
#include "list.h"

List * list_append(void * element, List * tail){
    /*
     * exchange only the list itself
     *
     */
    List * lst = malloc(sizeof(List));
    lst->head=element;
    lst->tail=tail;
    return lst;
}
