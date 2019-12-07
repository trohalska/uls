#include "uls.h"

t_list *mx_get_files_list(t_list *files, char *dir) {
    t_list *fl = NULL;
   
    for (t_list *q = files; q; q = q->next) {
        mx_push_back(&fl, mx_get_filesattr(q->data, dir));
    }
    return fl;
}
