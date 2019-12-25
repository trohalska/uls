#include "libmx.h"

char *mx_strtrim(const char *str) {
	if (!str) return NULL;
	int i = 0;
	int j = mx_strlen(str) - 1;
	while (mx_isspace(str[i])) // check chars from start
		i++;
	while (mx_isspace(str[j]))
		j--;
	if (i <= j) {
		char *n;
		n = mx_strncpy(mx_strnew(j + 1 - i), &str[i], j + 1 - i);
		return n;
	}
	else return malloc(0);
}
