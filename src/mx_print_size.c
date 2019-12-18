#include "uls.h"

static void major_minor(t_file *file);

void mx_print_size(t_file *file, t_maxlens_for_print *ml) {
    char *tmp;

    if (!file || !ml)
        return;
    if (S_ISBLK(file->ffs.st_mode) || S_ISCHR(file->ffs.st_mode)) {
        major_minor(file);
    }
    else {
        tmp = mx_itoa(file->ffs.st_size);
        mx_printspaces(ml->l_size - mx_strlen(tmp));
        mx_printstr(tmp);
        free(tmp);
    }
}

static void major_minor(t_file *file){
    char *major, *minor;

    major = mx_itoa((file->ffs.st_rdev >> 24) & 0xffffff);
    minor = mx_itoa(file->ffs.st_rdev & 0xffffff);
    if((file->ffs.st_rdev & 0xffffff) > 999) {
        minor = mx_nbr_to_hex(file->ffs.st_rdev & 0xffffff);
        while (mx_strlen(minor) < 10) {
            minor = mx_strjoin("0", minor);
        }
        minor[1] = 'x';
    }
    mx_printspaces(3 - mx_strlen(major));
    mx_printstr(major);
    mx_printstr(", ");
    mx_printspaces(3 - mx_strlen(minor));
    mx_printstr(minor);
    free(major);
    free(minor);
}
