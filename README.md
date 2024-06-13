This folder contains mainly data structures that are intended to handle chained lists, double chained lists and another special type of list called "csmk dataList or dlist" that works a bit like a polymorph data structure for lists

# What is DataList ?
DataList as the name says a data structure that works more or less like an ArrayList in java. DataList is generic but a bit limited. It can be used as a Stack, Queue and a normal List.

# How to use the dlist Library ? 

- You must first choose the type of data by replacing the value of "dl_type" in the "DataListType.h" header file
- And finally use the "APPLY_DATATYPE(dataType)" macro with the previously chosen type at the very beginning of your code before you can use the data list

# Get Started

## Build the csmkdlist library (make)

```
make
```

## Write a C - code
```
#include <stdio.h>

#define dl_type int

#include <dlist_type.h>

#include <csmkdlist.h>

DL_APPLY_ALL(dl_type)

int main() {
    DataList *dl = dl_init();
    int el;

    dl_push(dl, 23);
    dl_enqueue(dl, 24);

    dl_pop(dl, &el);

    printf("%d\n", el);

    dl_faster_append(dl, 12);

    dl_dequeue(dl, &el);

    printf("%d\n", el);

    return 0;
}

...

```

## Compile your C-code
```
gcc -std=c11 -g -Wall -I../build/include -L../build/lib -o code code.c -lcsmkdlist
```