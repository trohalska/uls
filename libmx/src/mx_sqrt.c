#include "libmx.h"

int mx_sqrt(int x) {
    if (x < 0)
        return 0;
    int i = 0;
    int j = x / 2 + 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (m * m == x)
            return m;
        else if (m * m > x || m > 46340)
            j = m - 1;
        else
            i = m + 1;
    }
    return 0;
}
