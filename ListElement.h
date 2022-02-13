#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_
typedef struct listElement {
    int val;
    struct listElement *prev;
    struct listElement *next;
} ListElement;


#endif /* LISTELEMENT_H_ */