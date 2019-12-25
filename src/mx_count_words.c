#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) return -1; // в пдф повинно вертати нічого?????
    int s = 0;
    while (*str != '\0') {
        // if not word
        if (*str == c)
            while (*str == c && *str != '\0')
                str++;
        // if word
        if (*str != c && *str != '\0') {
            s++;
            while (*str != c && *str != '\0')
                str++;
        }
    }
    return s;
}
