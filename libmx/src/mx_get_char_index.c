#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str || !*str) return -2;
    char *s = (char *)str;
    int i = 0;
    while (s[i]) {
        if (s[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}
