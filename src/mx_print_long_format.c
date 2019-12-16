#include "uls.h"

static void print_total(t_list *lf);
static void print_line(t_file *file, t_maxlens_for_print *ml, t_cmd *c);
static void print_size(t_file *file, t_maxlens_for_print *ml);
static void print_link(t_file *file);
//static void print_time(t_file *file);

void mx_print_long_format(t_list *lf, t_cmd *c) {
    t_maxlens_for_print *ml;

    if (!lf || !c)
        return;
    ml = mx_get_lens_for_print(lf);
    print_total(lf);
    for (t_list *q = lf; q; q = q->next) {
        // --------------- if (!mx_isdir(NULL, q) && !mx_ishidden(NULL, q))
            print_line(q->data, ml, c);
    }
    free(ml);
    ml = NULL;
}

static void print_total(t_list *lf) {
    blkcnt_t res = 0;
    t_file *tmp;

    for (t_list *q = lf; q != NULL; q = q->next) {
        tmp = q->data;
        res += tmp->blocks;
    }
    mx_printstr("total ");
    mx_printint((int)res);
    mx_printstr("\n");
}

static void print_line(t_file *file, t_maxlens_for_print *ml, t_cmd *c) {
    char *tmp;

    if (!file || !ml || !c)
        return;
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

    mx_printspaces(2);
    print_size(file, ml);

    mx_printspaces(1);
    mx_printstr(file->time);
    mx_printspaces(1);
    mx_printstr(file->filename);
    if (file->mode[0] == 'l')
        print_link(file);
    mx_printstr("\n");
}

static void print_size(t_file *file, t_maxlens_for_print *ml) {
    char *major, *minor, *tmp;

    if (!file || !ml)
        return;
    if (S_ISBLK(file->ffs.st_mode) || S_ISCHR(file->ffs.st_mode)) {
        major = mx_itoa((file->ffs.st_rdev >> 24) & 0xffffff);
        minor = mx_itoa(file->ffs.st_rdev & 0xffffff);
        if((file->ffs.st_rdev & 0xffffff) > 999) {
            minor = mx_nbr_to_hex(file->ffs.st_rdev & 0xffffff);
            while (mx_strlen(minor) < 10) {
                minor = mx_strjoin("0", minor);
            }
            minor[1] = 'x';
        }
        mx_printspaces(3 - mx_strlen(major));
        mx_printstr(major);
        mx_printstr(", ");
        mx_printspaces(3 - mx_strlen(minor));
        mx_printstr(minor);
        free(major);
        free(minor);
    }
    else {
        tmp = mx_itoa(file->size);
        mx_printspaces(ml->l_size - mx_strlen(tmp));
        mx_printstr(tmp);
        free(tmp);
    }
}

static void print_link(t_file *file) {
    char link[1024];
    int size = 0;

    if (!file)
        return;
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
