//
// Created by csmk on 7/19/2022.
//

#ifndef CSMK_DLIST_DLIST_TYPES_H
#define CSMK_DLIST_DLIST_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int32_t value;
}*DLIST_Integer;

typedef struct {
    char value;
}*DLIST_Character;

DLIST_Integer dlist_new_integer(int32_t val);
DLIST_Character dlist_new_character(char val);

#endif //CSMK_DLIST_DLIST_TYPES_H
