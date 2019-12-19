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
    char *temp_time = ctime(&t);
    char *result = mx_strnew(12);
    time_t now = time(NULL);

    if ((now - 15778463) > t || now < t) {
        result = mx_strncpy(result, temp_time + 4, 6);
        mx_strcpy(result + 6, "  ");
        mx_strncpy(result + 8, temp_time + 20, 4);
        mx_printstr(result);
        free(result);
    }
    else {
        result = mx_strncpy(result, temp_time + 4, 12);
        mx_printstr(result);
        free(result);
    }
}

// static void print_specific_time_T(time_t t) {
//     char *temp_time = ctime(&t);
//     char *result = mx_strnew(20);
//     result = mx_strncpy(result, temp_time + 4, 20);
//     mx_printstr(result);
//     free(result);
// }
