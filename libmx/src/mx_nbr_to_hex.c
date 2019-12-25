#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) { // 495
    int count_let_hex = 0;
    unsigned long t = nbr;
    char *s = mx_strnew(count_let_hex);

    if (nbr == 0) {
        s = "0";
        return s;
    }
    while (t > 0) {
        t = t / 16;
        count_let_hex++; // found number k
    }
    for (int i = 0; i < count_let_hex; i++) {
        t = nbr % 16;
        s[i] = t < 10 ? t + '0' : t + 'a' - 10;
        nbr = nbr / 16;
    }
    mx_str_reverse(s);
    return s;
}
