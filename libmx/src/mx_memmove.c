#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *d = dst;
    const char *s = src;
    char tmp[len];

    for (size_t i = 0; i < len; i++)
        tmp[i] = s[i];
    for (size_t i = 0; i < len; i++)
        d[i] = tmp[i];
    return dst;
}
