#include "uls.h"

t_uls *create_node(void *data, int len);

void mx_push_back_uls(t_uls **list, void *data, int len) {
    if (!list || !data) return;
    t_uls *tmp = create_node(data, len); // create new
    if (!tmp) return;
    t_uls *p = *list;
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

t_uls *create_node(void *data, int len) {
    if (!data) return NULL;
    t_uls *temp = malloc(sizeof(t_uls));

    if (!temp) return NULL;
    temp->data = data;
    temp->len = len;
    temp->next = NULL;
    return temp;
}
