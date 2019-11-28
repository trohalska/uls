#include "libmx.h"

void mx_del_matrix_int(int **str) {
	if (*str && str) {
		free(*str);
		*str = NULL;
	}
}
