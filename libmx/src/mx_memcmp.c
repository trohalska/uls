#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const char *d = s1;
    const char *s = s2;
    size_t i = 0;
    while (i < n) {
        if (d[i] != s[i]) {
            return d[i] - s[i];
        }
        i++;
    }
    return 0;
}
