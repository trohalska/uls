#include "uls.h"

static int mx_check_flags(int argc, char **argv);
static void print_error_flag(char c, char *ex);
static void mx_check_arguments(int argc, char **argv, int p);
static void print_error_arguments(char *v);

int mx_check(int argc, char **argv) {
	int position = mx_check_flags(argc, argv);

	if (argv[position] && mx_strcmp(argv[position], "--") == 0)
		position++;

	mx_check_arguments(argc, argv, position);

	return position;
}

static int mx_check_flags(int argc, char **argv) {
	char *ex = ULS_FLAGS;
	int len_ex = mx_strlen(ex);
	int i = 1, j;

	for (; i < argc; i++)
		if (argv[1][0] == '-' && argv[i][0] == '-') {
			if (mx_strcmp(argv[i], "--") == 0)
				break;
			for (int j = 1; j < mx_strlen(argv[i]); j++)
				for (int k = 0; k < len_ex && argv[i][j] != ex[k]; k++)
					if (k == len_ex - 1) {
						print_error_flag(argv[i][j], ex);
						exit(1);
					}
		}
		else
			break;
	for (j = i; i < argc && argv[j][0] == '-' && argv[j][1] != '-'; i++)
		mx_check_arguments(1, &argv[j], 0);
	return i;
}

static void print_error_flag(char c, char *ex) {
	mx_printerr("uls: illegal option -- ");
    write(2, &c, 1);
    mx_printerr("\nusage: uls [-");
    mx_printerr(ex);
    mx_printerr("] [file ...]\n");
}

static void mx_check_arguments(int argc, char **argv, int p) {
    struct stat buff;

    for (int i = p; i < argc; i++) {
    	if (argv[i])
	        if (lstat(argv[i], &buff) != 0) {
	            print_error_arguments(argv[i]);
	            argv[i] = NULL;
	        }
	}
}

static void print_error_arguments(char *v) {
    mx_printerr("uls: ");
    mx_printerr(v);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}
