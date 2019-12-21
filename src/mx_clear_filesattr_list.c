#include "uls.h"

void mx_clear_filesattr(t_file *file);

void mx_clear_filesattr_list(t_list **fl) {
    t_list *q = *fl;
    t_list *tmp = NULL;

    if (!(*fl) || !fl)
        return;
    while (q) {
        mx_clear_filesattr(q->data);
        tmp = q->next;
        free(q);
        q = tmp;
    }
    *fl = NULL;
}

void mx_clear_filesattr(t_file *file) {
    if (!file)
        return;
    mx_strdel(&file->path);
    mx_strdel(&file->filename);
    mx_strdel(&file->owner);
    mx_strdel(&file->group);
    free(file);
    file = NULL;
}
