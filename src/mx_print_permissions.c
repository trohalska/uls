#include "uls.h"

void mx_print_permissions(t_file *file) {
    char res[11];

    res[0] = S_ISBLK(file->ffs.st_mode) ? 'b' : \
             S_ISCHR(file->ffs.st_mode) ? 'c' : \
             S_ISDIR(file->ffs.st_mode) ? 'd' : \
             S_ISSOCK(file->ffs.st_mode) ? 's' : \
             S_ISFIFO(file->ffs.st_mode) ? 'p' : \
             S_ISLNK(file->ffs.st_mode) ? 'l' : '-';
    res[1] = (S_IRUSR & file->ffs.st_mode) ? 'r' : '-';
    res[2] = (S_IWUSR & file->ffs.st_mode) ? 'w' : '-';
    res[3] = (S_IXUSR & file->ffs.st_mode) ? 'x' : '-';
    res[4] = (S_IRGRP & file->ffs.st_mode) ? 'r' : '-';
    res[5] = (S_IWGRP & file->ffs.st_mode) ? 'w' : '-';
    res[6] = (S_IXGRP & file->ffs.st_mode) ? 'x' : '-';
    res[7] = (S_IROTH & file->ffs.st_mode) ? 'r' : '-';
    res[8] = (S_IWOTH & file->ffs.st_mode) ? 'w' : '-';
    res[9] = (S_ISTXT & file->ffs.st_mode) ? 't' : \
             (S_IXOTH & file->ffs.st_mode) ? 'x' : '-';
    res[10] = '\0';
    mx_printstr(res);
}
