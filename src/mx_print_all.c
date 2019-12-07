#include "uls.h"

static void print_f_d(t_list *f_names, t_list *d_names);
static t_list *mx_get_arg_f(int argc, char **argv);
static t_list *mx_get_arg_d(int argc, char **argv);
static bool strcmp_bool(void *d1, void *d2);

void mx_print_all(int argc, char **argv, char *flags) { 
	t_list *f_names = mx_get_arg_f(argc, argv);
	t_list *d_names = mx_get_arg_d(argc, argv);

	if (flags[0] == 'l') { // костыль // поки тільки для -l
		if (!f_names && !d_names) {
			mx_print_one_dir(mx_get_files_list_dir(".")); // зробити з указателем на функцію
			return;
		}
		print_f_d(f_names, d_names);

	}
	// рекурсия?
}

static void print_f_d(t_list *f_names, t_list *d_names) {
	t_list *fl_attr;

	if (f_names) {
    	fl_attr = mx_get_files_list(f_names, ".");
        mx_print_long_format(fl_attr); // зробити з указателем на функцію
        if (mx_list_size(d_names) > 0)
            mx_printstr("\n");
    }
    if (d_names) {
		for (t_list *c = d_names; c; c = c->next) {
			if (mx_list_size(d_names) != 1 || f_names) {
	            mx_printstr(c->data);
	   			mx_printstr(":\n");
	        }
	        mx_print_one_dir(mx_get_files_list_dir(c->data));
	        if (c->next != NULL)
	        	mx_printstr("\n");
		}
	}
}

static t_list *mx_get_arg_f(int argc, char **argv) {
	t_list *f_argv = NULL;
	int i = 1;

	while (argv[i] && argv[i][0] == '-')
		i++;
	for (; i < argc; i++)
		if (!mx_isdir(argv[i], NULL))
			mx_push_back(&f_argv, argv[i]);
	mx_sort_list(f_argv, strcmp_bool);
	return f_argv;
}

static t_list *mx_get_arg_d(int argc, char **argv) {
	t_list *d_argv = NULL;
	int i = 1;

	while (argv[i] && argv[i][0] == '-')
		i++;
	for (; i < argc; i++)
		if (mx_isdir(argv[i], NULL)) 
			mx_push_back(&d_argv, argv[i]);
	mx_sort_list(d_argv, strcmp_bool);
	return d_argv;
}

static bool strcmp_bool(void *d1, void *d2) {
	char *s1 = d1;
	char *s2 = d2;

    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
	if ((*s1 - *s2) > 0)
    	return true;
	else
		return false;
}
