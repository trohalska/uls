#include "uls.h"

t_list *mx_get_arg_d(int argc, char **argv, int i) {
	t_list *d_argv = NULL;

	for (; i < argc; i++)
		if (argv[i] && mx_isdir(argv[i], NULL))
			mx_push_back(&d_argv, argv[i]);
	mx_sort_list(d_argv, mx_strcmp_f_d_bool);
	return d_argv;
}
