#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *temp;

    if (!data)
        return NULL;
    temp = malloc(sizeof(t_list));
    if (!temp)
        return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
