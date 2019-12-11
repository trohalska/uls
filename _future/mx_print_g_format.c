#include "uls.h"

static void print(t_file *file);
//static void print_time(t_file *file);

void mx_print_g_format(t_list *list_file) {
    t_maxlens_for_print *ml;
    ml = mx_get_lens_for_print(list_file);
    
    for (t_list *q = list_fils; q; q = q->next) {
        print(q->data, ml);
    }
}

static void print(t_file *file, t_maxlens_for_print *ml) {
    mx_printstr(file->mode);
    mx_printspaces(ml->l_links - mx_strlen(mx_itoa(file->links)));
    mx_printint(file->links);
    mx_printspaces(1);
    mx_printstr(file->group);
    mx_printspaces(ml->l_group - mx_strlen(file->group));
    mx_printspaces(2 + ml->l_size - mx_strlen(mx_itoa(file->size)));
    mx_printstr(mx_itoa(file->size));
    mx_printspaces(1);
    mx_printstr(file->m_time);
    mx_printspaces(1);
    mx_printstr(file->filename);
    //mx_print_link(file);
    mx_printstr("\n");
}

// static void print_time(t_file *file) {
//     mx_printstr("\n");
//     mx_printstr(file->a_time);
//     mx_printstr("\n");
//     mx_printstr(file->m_time);
//     mx_printstr("\n");
//     mx_printstr(file->c_time);
// }