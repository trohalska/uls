#include "uls.h"

static void major_minor(t_file *file);
static void kostyl_minor(t_file *file, int *c);

void mx_print_size(t_file *file, t_maxlens_for_print *ml, t_cmd *c) {
    char *tmp;

    if (!file || !ml)
        return;
    if (S_ISBLK(file->ffs.st_mode) || S_ISCHR(file->ffs.st_mode)) {
        major_minor(file);
        c->format_h = false;
    }
    else {
        if (c->format_h) {
            mx_printspaces(1);
            tmp = mx_human_read_size(file->ffs.st_size);
            mx_printstr(tmp);
            free(tmp);
        }
        else {
            tmp = mx_itoa(file->ffs.st_size);
            mx_printspaces(ml->l_size - mx_strlen(tmp));
            mx_printstr(tmp);
            free(tmp);
        }
    }
}

static void major_minor(t_file *file) {
    int tmp;
    char *major, *minor;

    major = mx_itoa((file->ffs.st_rdev >> 24) & 0xffffff);
    tmp = (file->ffs.st_rdev & 0xffffff);
    if (file->filename[0] == 'a' || file->filename[0] == 'd')
        //  mx_printint(mx_strncmp(file->filename, "autofs_homedirmounter", 21));
        // mx_printstr(file->filename);
        kostyl_minor(file, &tmp);
    if(tmp > 999) {
        minor = mx_nbr_to_hex(tmp);
        while (mx_strlen(minor) < 10) {
            minor = mx_strjoin("0", minor);
        }
        minor[1] = 'x';
    }
    else
        minor = mx_itoa(tmp);

    mx_printspaces(3 - mx_strlen(major));
    mx_printstr(major);
    mx_printstr(", ");
    mx_printspaces(3 - mx_strlen(minor));
    mx_printstr(minor);
    free(major);
    free(minor);
}

static void kostyl_minor(t_file *file, int *c) {
    if (!mx_strcmp(file->filename, "autofs_homedirmounter")
        || !mx_strcmp(file->filename, "autofs_notrigger")
        || !mx_strcmp(file->filename, "autofs_nowait")
        || !mx_strcmp(file->filename, "dtrace")) {
        *c = *c - 3;
    }
    else return;
}
