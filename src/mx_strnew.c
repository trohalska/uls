#include "libmx.h"

char *mx_strnew(const int size) {
    // check
    if (size < 0) {
        return NULL;
    }
    // all good
    char *new = (char *) malloc((size + 1) * sizeof (char));
    // check creation malloc
    if (new == NULL) {
        return NULL;
    }
    for (int i = 0; i < size + 1; i++) {
        new[i] = '\0';        
    }
    return new;
}
