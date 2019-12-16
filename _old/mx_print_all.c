#include "uls.h"

static void mx_prepare_list_and_print(t_list *lf, t_cmd *c);

static void print_f_d(t_list *f_names, t_list *d_names, t_cmd *c);
static void print_one_dir(t_list *lf, t_cmd *c);
static t_list *mx_get_arg_f(int argc, char **argv);
static t_list *mx_get_arg_d(int argc, char **argv);
static bool strcmp_bool(void *d1, void *d2);

void mx_print_all(int argc, char **argv, t_cmd *c)
{
	t_list *f_names = mx_get_arg_f(argc, argv);
	t_list *d_names = mx_get_arg_d(argc, argv);

	if (!f_names && !d_names) {
		print_one_dir(mx_get_files_list_dir(".", c), c);
		return;
	}
	print_f_d(f_names, d_names, c);

	// рекурсия?
}

static void print_one_dir(t_list *lf, t_cmd *c) {
    blkcnt_t res = 0;

    for (t_list *q = lf; q != NULL; q = q->next) {
        t_file *tmp = q->data;
        res += tmp->blocks;
    }
    mx_prepare_list_and_print(lf, c);
}

static void mx_prepare_list_and_print(t_list *lf, t_cmd *c) {
    // files = flags->filter(files);
    // if (!mx_list_size(files)) {
    //     return;
    // }
    // flags->sort(files, flags->sort_functions);
    // if (!mx_check_file_error(files->data)) {
    //     flags->print(files);
    // }
    // else {
    // print_error_file(files->data);
    // }

	if (c->print_func == long_format) {
		mx_print_long_format(lf, c);
	}
	else if (c->print_func == col_format) {
		mx_print_col_format(lf);
	}
}


static void print_f_d(t_list *f_names, t_list *d_names, t_cmd *c)
{
	if (f_names) {
        mx_prepare_list_and_print(mx_get_files_list(f_names, ".", c), c);
        if (mx_list_size(d_names) > 0)
            mx_printstr("\n");
    }
    if (d_names) {
		for (t_list *tmp = d_names; tmp; tmp = tmp->next) {
			if (mx_list_size(d_names) != 1 || f_names) {
	            mx_printstr(tmp->data);
	   			mx_printstr(":\n");
	        }
	        print_one_dir(mx_get_files_list_dir(tmp->data, c), c);
	        if (tmp->next != NULL)
	        	mx_printstr("\n");
		}
	}
}

static t_list *mx_get_arg_f(int argc, char **argv)
{
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

static t_list *mx_get_arg_d(int argc, char **argv)
{
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

static bool strcmp_bool(void *d1, void *d2)
{
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
