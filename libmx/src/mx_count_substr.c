#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) 
        return -1;
    char *s = (char *)str;
    int ln = mx_strlen(sub);
    int k = 0;
    while (*s) {
        for (int i = 0; i < ln && s[i] == sub[i]; i++)
            if (sub[i + 1] == '\0')
                k++;
        s++;
    }
    return k;
}
