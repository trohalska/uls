#include "libmx.h"

int **mx_create_matrix(int G, int fillin)
{
    int **str = (int **) malloc(G * sizeof(int *));
    for (int i = 0; i < G; i++) {
        int *s = malloc(G * sizeof(int));
        for (int j = 0; j < G; j++) {
            s[j] = fillin;
        }
        str[i] = s;
    }
    return str;
}

