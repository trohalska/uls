#include "uls.h"

static void mx_prepare_list_and_print(t_list *lf, t_command *c);
static void print_directories(t_list *d_names, t_command *c);
static void print_one_dir(char *dir, t_command *c);
static t_list *mx_get_arg_f(int argc, char **argv);
static t_list *mx_get_arg_d(int argc, char **argv);
static bool strcmp_bool(void *d1, void *d2);

int main(int argc, char **argv) {
	t_command *c = mx_create_command(argc, argv);
	//t_list *errors
	t_list *f_names = mx_get_arg_f(argc, argv);
	t_list *d_names = mx_get_arg_d(argc, argv);

	if (!f_names && !d_names)
		mx_push_back(&d_names, ".");

	if (f_names) {
		t_list *tmp;
		for (t_list *q = f_names; q; q = q->next) {
			mx_push_back(&tmp, mx_get_filesattr(q->data, ".", c));
		}
        mx_prepare_list_and_print(tmp, c);
        if (mx_list_size(d_names) > 0)
            mx_printstr("\n");
		if (d_names && mx_list_size(d_names) == 1) {
			mx_printstr(d_names->data);
	   		mx_printstr(":\n");
		}
    }
    print_directories(d_names, c);
	// system("leaks -q uls");
	return 0;	
}

static void print_directories(t_list *d_names, t_command *c) {
	if (d_names) {
		for (t_list *tmp = d_names; tmp; tmp = tmp->next) {
			if (mx_list_size(d_names) != 1) {
	            mx_printstr(tmp->data);
	   			mx_printstr(":\n");
	        }
	        print_one_dir(tmp->data, c);
	        if (tmp->next != NULL){
	        	mx_printstr("\n");
			}
		}
	}
}

static void print_one_dir(char *dir, t_command *c) {
    
	t_list *files_list = mx_get_files_list_dir(dir, c);
	// sort and filter
    mx_prepare_list_and_print(files_list, c);

	if (c->print_recursion) // recursion
		for (t_list *q = files_list; q; q = q->next) {
			if (mx_isdir(NULL, q)) {
				t_file *tmp = q->data;
				// if (!mx_strcmp(tmp->filename, ".") && !mx_strcmp(tmp->filename, "..")) { // ??????????????
					mx_printstr("\n");
					mx_printstr(tmp->path);
					mx_printstr(":\n");
					print_one_dir(tmp->path, c);
				// }
			}
		}

	// free(files_list);
}

static void mx_prepare_list_and_print(t_list *lf, t_command *c) {
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
	else if (c->print_func == std_format) {
		mx_print_std_format(lf);
	}
	else if (c->print_func == col_format) {
		mx_print_col_format(lf);
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
