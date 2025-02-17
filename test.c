#include "structure.h"

int main() {
    Array *arr = array(sizeof(int));

    int a = 10, b = 20;
    push(arr, &a);
    push(arr, &b);

    printf("arr[0]: %d\n", *(int*)get(arr, 0));  // 出力: 10
    printf("arr[1]: %d\n", *(int*)get(arr, 1));  // 出力: 20

    pop(arr);
    printf("After pop, arr size: %zu\n", arr->size);  // 出力: 1

    return 0;
}
