#include "libmx.h"

void mx_str_reverse(char *s) {
    int i = 0;
    int len;

    if (!s || !*s)
        return;
    len = mx_strlen(s);
    while (i < len / 2){
        mx_swap_char(&s[i], &s[len - i - 1]);
        i++;
    }
}
