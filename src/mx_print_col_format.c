#include "uls.h"

void mx_print_col_format(t_list *lf) {
    t_list *q;
    t_file *tmp;

    for (q = lf; q; q = q->next) {
        tmp = q->data;
        mx_printstr(tmp->filename);
        mx_printchar('\n');
    }
}
