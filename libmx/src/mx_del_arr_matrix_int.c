#include "libmx.h"

void mx_del_arr_matrix_int(int ***arr) {
    if (arr == NULL) return;
    int ***p = arr;
    int **pp = *arr;
    while (**p != NULL) {
        mx_del_matrix_int(*p);
        (*p)++;   
    }
    free(pp);
    *arr = NULL;
}

