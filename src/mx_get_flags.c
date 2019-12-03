#include "uls.h"

static char *initialize(int len);

char *mx_get_flags(int argc, char **argv) {
	char *flags, *result = NULL;
	int len;

	if (argv[1][0] != '-')
		return NULL;
	flags = "lRaAGh@eT1CrtucS";
	len = mx_strlen(flags);
	result = initialize(len);
	for (int i = 1; i < argc; i++)
		if (argv[i][0] == '-') {
			for (int j = 1; j < mx_strlen(argv[i]); j++)
				for (int k = 0; k < len; k++)
					if (flags[k] == argv[i][j])
						result[k] = argv[i][j];
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
