#include "uls.h"

bool mx_isdir(char *filename, t_list *q) {	
    if (filename && !q) {
        struct stat fs;
        stat(filename, &fs);
        if (S_ISDIR(fs.st_mode)) {
            return true;
        }
        return false;
    }
    else if (!filename && q)
        return (((t_file *)q->data)->mode[0] == 'd' ? true : false);
    else
        return false;    
}
