#include "uls.h"

// void mx_reverse_list(t_list **list, void (*f_clear)(t_list **)) {
//     t_list *result;

//     if (!(*list) || !list)
//         return;
//     for (t_list *q = *list; q; q = q->next) {
//         mx_push_front(&result, q->data);
//     }
//     f_clear(list);
//     list = &result;
// }

t_list *mx_reverse_list(t_list **list) {
    t_list *result = NULL;

    if (!(*list) || !list)
        return NULL;
    for (t_list *q = *list; q; q = q->next) {
        t_file *tmp = q->data;
        t_file *new = (t_file *)malloc(sizeof(t_file));
        new->filename = mx_strdup(tmp->filename);
        new->path = mx_strdup(tmp->path);
        new->ffs = tmp->ffs;
        new->blocks = tmp->blocks;
        new->mode = mx_strdup(tmp->mode);
        new->links = tmp->links;
        new->owner = mx_strdup(tmp->owner);
        new->group = mx_strdup(tmp->group);
        new->size = tmp->size;
        new->time = mx_strdup(tmp->time);
        mx_push_front(&result, new);
    }
    // mx_clear_filesattr_list(list);
    return result;
}
