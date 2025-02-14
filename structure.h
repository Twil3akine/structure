#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct array array;

struct array {
    void *val;
    size_t size;
    size_t capacity;
};