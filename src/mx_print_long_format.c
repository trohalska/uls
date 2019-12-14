#include "uls.h"

static void print(t_file *file, t_maxlens_for_print *ml, t_command *c);
static void print_link(t_file *file);
//static void print_time(t_file *file);

void mx_print_long_format(t_list *lf, t_command *c) {
    t_maxlens_for_print *ml = mx_get_lens_for_print(lf);

    blkcnt_t res = 0;
    for (t_list *q = lf; q != NULL; q = q->next) {
        t_file *tmp = q->data;
        res += tmp->blocks;
    }
	mx_printstr("total ");
    mx_printint((int)res);
    mx_printstr("\n");

    for (t_list *q = lf; q; q = q->next) {
        // --------------- if (!mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
            print(q->data, ml, c);
    }
    free(ml);
    ml = NULL;
}

static void print(t_file *file, t_maxlens_for_print *ml, t_command *c) {
    char *tmp = NULL;

    mx_printstr(file->mode);
    tmp = mx_itoa(file->links);
    mx_printspaces(1 + ml->l_links - mx_strlen(tmp));
    free(tmp);
    mx_printint(file->links);
    mx_printspaces(1);
    if (c->print_owner) {
        mx_printstr(file->owner);
        mx_printspaces(ml->l_owner - mx_strlen(file->owner) + 2);
    }
    if (c->print_group) {
        mx_printstr(file->group);
        mx_printspaces(ml->l_group - mx_strlen(file->group));
    }
    tmp = mx_itoa(file->size);
    mx_printspaces(2 + ml->l_size - mx_strlen(tmp));
    mx_printstr(tmp);
    free(tmp);
    mx_printspaces(1);
    mx_printstr(file->time);
    mx_printspaces(1);
    mx_printstr(file->filename);
    if (file->mode[0] == 'l')
        print_link(file);
    mx_printstr("\n");

}

static void print_link(t_file *file) {
    char link[1024];
    int size = 0;

    size = readlink(file->path, link, sizeof(link) - 1);
    link[size] = '\0';
    mx_printstr(" -> ");
    mx_printstr(link);
}



// static void print_time(t_file *file) {
//     mx_printstr("\n");
//     mx_printstr(file->a_time);
//     mx_printstr("\n");
//     mx_printstr(file->m_time);
//     mx_printstr("\n");
//     mx_printstr(file->c_time);
// }
