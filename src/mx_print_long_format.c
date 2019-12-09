#include "uls.h"

static void print(t_file *file, t_maxlens_for_print *ml, t_command *c);
//static void print_time(t_file *file);

void mx_print_long_format(t_list *lf, t_command *c) {
    t_maxlens_for_print *ml;
    
    ml = mx_get_lens_for_print(lf);
    for (t_list *q = lf; q; q = q->next) {
        //if (!mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
            print(q->data, ml, c);
    }
    // for (t_list *q = lf; q; q = q->next) {
    //     if (mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
    //         print(q->data, ml);
        
    // }

}

static void print(t_file *file, t_maxlens_for_print *ml, t_command *c) {
    mx_printstr(file->mode);
    mx_printspaces(1);
    mx_printspaces(ml->l_links - mx_strlen(mx_itoa(file->links)));
    mx_printint(file->links);
    mx_printspaces(1);
    if (c->print_owner) {
        mx_printstr(file->owner);
        mx_printspaces(ml->l_owner - mx_strlen(file->owner));
        mx_printspaces(2);
    }
    if (c->print_group) {
        mx_printstr(file->group);
        mx_printspaces(ml->l_group - mx_strlen(file->group));
    }
    mx_printspaces(2 + ml->l_size - mx_strlen(mx_itoa(file->size)));
    mx_printstr(mx_itoa(file->size));
    mx_printspaces(1);
    mx_printstr(file->time);
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
