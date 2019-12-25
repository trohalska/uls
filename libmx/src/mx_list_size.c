#include "libmx.h"

int mx_list_size(t_list *list) {
    int k = 1;
    t_list *p;

    if (list == NULL)
        return 0;
    p = list;
    while (p && p->next != NULL) {
        k++;
        p = p->next;
    }
    return k;
}
