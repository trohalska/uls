#include "libmx.h"

char *mx_strdup(const char *str) {
    char *p = mx_strnew(mx_strlen(str));

    /*if (p == NULL) {
        return NULL;
    }*/
    return mx_strcpy(p, str);
}
