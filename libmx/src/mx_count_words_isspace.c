#include "libmx.h"

int mx_count_words_isspace(const char *str, int *kwl) {
	if (!str || !*str) return -1;
	int s = 0;
	int i = 0;
	while (str[i] != '\0') {
		if (mx_isspace(str[i]))
			while (mx_isspace(str[i]) && str[i] != '\0')
				i++;
		if (!mx_isspace(str[i]) && str[i] != '\0') {
			s++;
			while (!mx_isspace(str[i]) && str[i] != '\0') {
				i++;
				*kwl += 1;
			}
		}
	}
	return s;
}
