#include "../structure.h"

Array *array(size_t element_size) {
    Array *arr = (Array*)malloc(sizeof(Array));
    
    if (arr == NULL) {
        perror("Failed to allocate memory for array.");
        exit(1);
    }

    arr->val = NULL;
    arr->size = 0;
    arr->capacity = 0;
    arr->element_size = element_size;

    return arr;
}

/*
 push value in designed array

 @param arr -> pushed array
 @param val -> pushed value

 */
void push(Array *arr, void *val) {
    // case -> array is empty
    if (arr->capacity == 0) {
        arr->capacity = 1;
        arr->val = malloc(sizeof(arr->element_size));
        if (arr->val == NULL) {
            perror("Failed to allocate memory for array elements.");
            exit(1);
        }
    }

    // case -> array is full
    if (arr->capacity == arr->size) {
        arr->capacity *= 2;
        arr->val = realloc(arr->val, arr->capacity*sizeof(arr->element_size));
        if (arr->val == NULL) {
            perror("Failed to reallocate memory for array elements.");
            exit(1);
        }
    }

    // push new element in array
    memcpy((char*)arr->val + (arr->size++)*arr->element_size, val, arr->element_size);
}

void pop(Array *arr) {
    if (arr->size-- == 0) {
        fprintf(stderr, "Array is already empty.");
        return;
    }
}

void *get(Array *arr, size_t idx) {
    if (idx >= arr->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(1);
    }

    return (char*)arr->val + idx*arr->element_size;
}