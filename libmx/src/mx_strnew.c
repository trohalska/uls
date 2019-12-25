#include "libmx.h"

char *mx_strnew(const int size) {
    char *new;

    if (size < 0)
        return NULL;
    new = (char *) malloc((size + 1) * sizeof (char));
    if (new == NULL)
        return NULL;
    for (int i = 0; i < size + 1; i++)
        new[i] = '\0';
    return new;
}
