#include "uls.h"

static char *initialize(int len);
static void check_print_flags(char *result, char flag);

char *mx_get_flags(int argc, char **argv) {
	char *flags, *result = NULL;
	int len;

	if (argv[1][0] != '_')
		return NULL;
	flags = "lC1"; // "lC1RaAGh@eTrtucS"
	len = mx_strlen(flags);
	result = initialize(len);
	for (int i = 1; i < argc; i++)
		if (argv[i][0] == '-') {
			for (int j = 1; j < mx_strlen(argv[i]); j++)
				for (int k = 0; k < len; k++)
					if (flags[k] == argv[i][j]) {
						result[k] = argv[i][j];
						check_print_flags(result, result[k]);
					}
		}
		else break;
	return result;
}

static char *initialize(int len) {
	char *r = mx_strnew(len);
	for (int i = 0; i < len; i++)
		r[i] = '0';
	return r;
}

static void check_print_flags(char *result, char flag) {
	if (flag == 'l' || flag == 'C' || flag == '1') {
		if (flag == 'l') {
			result[1] = '_'; // -C
			result[2] = '_'; // -1
		}
		else if (flag == 'C') {
			result[0] = '_'; // -l
			result[2] = '_'; // -1
		}
		else {
			result[0] = '_'; // -l
			result[1] = '_'; // -C
		}
	}
}
