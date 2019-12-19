#include "uls.h"

void mx_print_col_m_format(t_list *lf, char *delim) {
    t_file *tmp;

    for (t_list *q = lf; q; q = q->next) {
        tmp = q->data;
        mx_printstr(tmp->filename);
        if (q->next == NULL)
        	break;
        mx_printstr(delim);
    }
    mx_printchar('\n');
}
