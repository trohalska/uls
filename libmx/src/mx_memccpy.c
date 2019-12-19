#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *d = dst;
    const char *s = src;
    size_t i = 0;
    while (i < n) {
        d[i] = s[i];
        if (d[i] == (char) c) return &d[i + 1];
        i++;
    }
    if (i == n) return NULL;
    return dst;
}
