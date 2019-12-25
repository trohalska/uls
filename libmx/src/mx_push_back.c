#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!list || !data) return;
    
    t_list *tmp = mx_create_node(data); // create new
    if (!tmp) return;
    t_list *p = *list;
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
