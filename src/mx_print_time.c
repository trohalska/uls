#include "uls.h"

static void print_specific_time(time_t t);

void mx_print_time(t_file *file, t_cmd *c) {

    if (c->time_type == time_mtime) {
        print_specific_time(file->ffs.st_mtime);
    }
    else if (c->time_type == time_atime) {
        print_specific_time(file->ffs.st_atime);
    }
    else {
        print_specific_time(file->ffs.st_ctime);
    }
}

static void print_specific_time(time_t t) {
    char *str = NULL;
    char *result;

    str = ctime(&t);
    result = mx_strncpy(mx_strnew(12), str + 4, 12);
    mx_printstr(result);
    free(result);
}
