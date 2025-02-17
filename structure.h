#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Array
 */

typedef struct Array Array;
struct Array {
    void *val;
    size_t size;
    size_t capacity;
    size_t element_size;
};

Array *array();
void push(Array *arr, void *val);
void pop(Array *arr);
void *get(Array *arr, size_t idx);