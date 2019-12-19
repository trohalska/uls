#include "uls.h"

bool mx_islink(char *filename, t_list *q) {
	struct stat fs;

    if (filename && !q) {
        lstat(filename, &fs);
        return (S_ISLNK(fs.st_mode) ? true : false);
    }
    else if (!filename && q){
        lstat(((t_file *)q->data)->path, &fs);
        return (S_ISLNK(fs.st_mode) ? true : false);
    }
    else
        return false;
}
