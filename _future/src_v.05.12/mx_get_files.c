#include "uls.h"

static int count_files(int argc, int i);

char **mx_get_files(int argc, char **argv) {
	char **result = NULL;
	int k = 0, i = 1, j = 0;
	while (argv[i] && argv[i][0] == '-')
		i++;
	if (i >= argc)
		return result;
	k = count_files(argc, i);
	result = (char **)malloc((k + 1) * sizeof(char *));
	for (; i < argc; i++, j++)
		result[j] = mx_strdup(argv[i]);
	result[j] = NULL;
	return result;
}

static int count_files(int argc, int i) {
	int k = 0;
	for (; i < argc; i++) {
		k++;
	}
	return k;
}
