#include "libmx.h"

static void count_hex(const char *hex, unsigned long *t, int i);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long n = 0;
    unsigned long t = 1;
    unsigned long m = 1;
    int k = 0;
    if (!hex || *hex == 0) 
        return n;
    const char *tmp = hex;
    while (*tmp != '\0') {
        k++;
        tmp++;
        m *= 16;
    }
    for (int i = 0; i < k; i++) {
        count_hex(hex, &t, i);
        m /= 16;
        n += t * m;
    }
    return n;
}

static void count_hex(const char *hex, unsigned long *t, int i) {
    if (hex[i] >= '0' && hex[i] <= '9')
        *t = hex[i] - '0';
    else if (hex[i] >= 'a' && hex[i] <= 'f')
        *t = hex[i] - 'a' + 10;
    else if (hex[i] >= 'A' && hex[i] <= 'F')
        *t = hex[i] - 'A' + 10;
    else exit(0);
}
