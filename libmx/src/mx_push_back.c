#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *tmp;
    t_list *p;

    if (!list || !data)
        return;
    tmp = mx_create_node(data); // create new
    if (!tmp)
        return;
    p = *list;
    if (*list == NULL) { // find Null-node
        *list = tmp;
        return;
    }
    else {
        while (p->next != NULL) // find Null-node
            p = p->next;
        p->next = tmp;
    }
}
