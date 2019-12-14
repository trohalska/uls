#include "uls.h"

void mx_clear_list_new(t_list **list) {
    t_list *q = *list;
    t_list *tmp = NULL;

    if (!(*list) || !list)
        return;
    while (q) {
        // mx_strdel((char **)&q->data);
        tmp = q->next;
        free(q);
        q = tmp;
    }
    *list = NULL;
}
