#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>

typedef struct {
    char **array;    
    int capacity;    
    int length;     
} ArrayList;

ArrayList *array_list_new();
void array_list_add_to_end(ArrayList *list, char *str);

#endif
