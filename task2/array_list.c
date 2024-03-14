#include "array_list.h"
#include <string.h>

ArrayList *array_list_new() {
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        return NULL; 
    }
    list->capacity = 10; 
    list->length = 0;
    list->array = malloc(sizeof(char *) * list->capacity);
    if (list->array == NULL) {
        free(list); 
        return NULL;
    }
    return list;
}
void array_list_add_to_end(ArrayList *list, char *str) {
    if (list->length == list->capacity) {
        int newCapacity = list->capacity * 2;
        char **newArray = realloc(list->array, newCapacity * sizeof(char *));
        if (newArray == NULL) {
            return;
        }
        list->array = newArray;
        list->capacity = newCapacity;
    }
    list->array[list->length] = str;
    list->length++;
}
