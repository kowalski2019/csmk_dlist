//
// Created by csmk on 7/19/2022.
//
#include "dlist_types.h"



DLIST_Integer dlist_new_integer(int32_t val)
{
    DLIST_Integer integer = (DLIST_Integer)malloc(sizeof (int) * 1);
    integer->value = val;
    return integer;
}

DLIST_Character dlist_new_character(char val)
{
    DLIST_Character character = (DLIST_Character)malloc(sizeof (int) * 1);
    character->value = val;
    return character;
}