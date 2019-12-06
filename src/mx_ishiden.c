#include "uls.h"

bool mx_ishidden(char *filename, t_list *q) {
    if (filename && !q) {
        if (filename[0] =='.') {
            return true;
        }
        return false;
    }
    else if (!filename && q)
        return (((t_file *)q->data)->filename[0] == '.' ? true : false);
    else
        return false;
}
