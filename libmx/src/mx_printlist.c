#include "libmx.h"

void mx_printlist(t_list *list) {
    t_list *q = list;
    while (q->next != NULL) {    
        mx_printstr(q->data);
        mx_printstr(" ");
        q = q->next;
    }
    mx_printstr(q->data); 
}
