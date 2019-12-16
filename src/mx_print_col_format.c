#include "uls.h"

void mx_print_col_format(t_list *lf) {
    t_file *tmp;

    for (t_list *q = lf; q; q = q->next) {
        tmp = q->data;
        mx_printstr(tmp->filename);
        mx_printchar('\n');
    }
}
