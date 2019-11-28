#include "uls.h"

static void print_error(char *dir);
static void print_one_col(t_uls *list);

void mx_if_no_argv(char *dir) {
    DIR *entry = NULL;
    struct dirent *file = NULL;
    t_uls *result = NULL;

    entry = opendir(dir);
    if (entry == NULL) 
        print_error(dir);
    while ((file = readdir(entry)) != NULL)
        if ((file->d_name[0] == '.' ? false : true))
            mx_push_back_uls(&result, file->d_name, mx_strlen(file->d_name));
    closedir(entry);

    // mx_sort_list(result);

    if (isatty(1))
        mx_print_many_col(result);
    else
        print_one_col(result);
    
    
}

static void print_error(char *dir) {
    char *err = strerror(errno);

    mx_printerr("uls: ");
    mx_printerr(dir);
    mx_printerr(": ");
    mx_printerr(err);
    mx_printerr("\n");
    exit(1);
}

static void print_one_col(t_uls *list) {
    t_uls *i;

    for (i = list; i != NULL; i = i->next) {
        mx_printstr(i->data);
        mx_printchar('\n');
    }
}
