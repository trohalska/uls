#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int f = 0;
    int l = size - 1;
    int m = 0;
    int res = -1;
    if (!arr || size < 1 || !s || !count)
        return res;
    while (f <= l) {
        *count += 1;
        m = f + (l - f) / 2;
        if (mx_strcmp(arr[m], s) == 0)
            return m;
        else if (mx_strcmp(arr[m], s) > 0)
            l = m - 1;
        else f = m + 1;
    }
    *count = 0;
    return res;
}
