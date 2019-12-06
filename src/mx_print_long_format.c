#include "uls.h"

static void print(t_file *file, t_maxlens_for_print *ml);
//static void print_time(t_file *file);

void mx_print_long_format(t_list *lf) {
    t_maxlens_for_print *ml;
    
    ml = mx_get_lens_for_print(lf);
    for (t_list *q = lf; q; q = q->next) {
        if (!mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
            print(q->data, ml);
    }
    for (t_list *q = lf; q; q = q->next) {
        if (mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
            print(q->data, ml);
        // if (!mx_strcmp((((t_file *)q->data)->filename), "uls"))
        //     mx_printstr();
    }

}

static void print(t_file *file, t_maxlens_for_print *ml) {
    mx_printstr(file->mode);
    mx_printspaces(1);
    mx_printspaces(ml->l_links - mx_strlen(mx_itoa(file->links)));
    mx_printint(file->links);
    mx_printspaces(1);
    mx_printstr(file->owner);
    mx_printspaces(ml->l_owner - mx_strlen(file->owner));
    mx_printspaces(2);
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