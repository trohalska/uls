#include "uls.h"

t_list *mx_get_files_list(t_list *files) {
    t_list *fl = NULL;
   
    for (t_list *q = files; q; q = q->next) {
        mx_push_back(&fl, mx_get_filesattr(q->data));
    }
    return fl;
}