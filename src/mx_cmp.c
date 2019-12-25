#include "libmx.h"

bool mx_cmp(void *a, void *b) {
	if (*(char *)a > *(char *)b)
		return true;
	else return false;
}
