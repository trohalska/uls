#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double p = n;

    if (n == 0) {
        return 0;
    }
    if (pow == 0) {
        return 1;
    }
    while (pow > 1) {
        p *= n;
        pow -= 1;
    }
    return p;
}
