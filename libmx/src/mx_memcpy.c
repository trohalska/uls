#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *d = dst;
    const char *s = src;
    mx_strncpy(d, s, n);
    return dst;
}
