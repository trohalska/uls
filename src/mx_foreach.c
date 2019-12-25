#include "libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) {
    // check
    if (!arr || size < 1) {
        return;
    }
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}
