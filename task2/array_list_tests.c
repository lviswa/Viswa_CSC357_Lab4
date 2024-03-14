#include "array_list.h"
#include "checkit.h"

void test_array_list_new_and_add() {
    ArrayList *list = array_list_new();
    checkit_int(list->length, 0);
    checkit_int(list->capacity, 10); 

    array_list_add_to_end(list, "Hello");
    checkit_int(list->length, 1);
    checkit_string(list->array[0], "Hello");

    free(list->array);
    free(list);
}

void test_array_list_initialization() {
    ArrayList *list = array_list_new();
    checkit_int(list->length, 0);
    checkit_int(list->capacity, 10); 

    free(list->array);
    free(list);
}

void test_array_list_add_within_capacity() {
    ArrayList *list = array_list_new();
    
    for (int i = 0; i < 10; ++i) {
        char *sampleStr = "Test"; 
        array_list_add_to_end(list, sampleStr);
        checkit_int(list->length, i + 1);
        checkit_string(list->array[i], sampleStr);
    }

    free(list->array);
    free(list);
}

void test_array_list_resize() {
    ArrayList *list = array_list_new();
    
    for (int i = 0; i < 11; ++i) {
        char *sampleStr = "Test"; 
        array_list_add_to_end(list, sampleStr);
    }

    checkit_int(list->length, 11);
    checkit_int(list->capacity >= 11, 1); 

    free(list->array);
    free(list);
}

void test_array_list_values_after_resize() {
    ArrayList *list = array_list_new();
    
    for (int i = 0; i < 12; ++i) {
        char sampleStr[20];
        sprintf(sampleStr, "Test%d", i);
        array_list_add_to_end(list, strdup(sampleStr)); 
    }

    for (int i = 0; i < 12; ++i) {
        char expectedStr[20];
        sprintf(expectedStr, "Test%d", i);
        checkit_string(list->array[i], expectedStr);
    }

    for (int i = 0; i < 12; ++i) {
        free(list->array[i]);
    }
    free(list->array);
    free(list);
}

int main() {
    test_array_list_new_and_add();
    test_array_list_initialization();
    test_array_list_add_within_capacity();
    test_array_list_resize();
    test_array_list_values_after_resize();
    return 0;
}