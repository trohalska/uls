#include "uls.h"

static char get_separator(int *len, char *name, int win_col);

void mx_print_m_format(t_list *lf) {
    struct winsize win;
    t_file *tmp;
    int len = 0, i = 0;

    if (!lf)
        return;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    for (t_list *q = lf; q; q = q->next, i++) {
        tmp = q->data;
        if (i != 0) {
            mx_printchar(',');
            mx_printchar(get_separator(&len, tmp->filename, win.ws_col));
        }
        mx_printstr(tmp->filename);
        len += mx_strlen(tmp->filename);
    }
    mx_printstr("\n");
}

static char get_separator(int *len, char *name, int win_col) {
    char separator;

    if (*len + 2 + mx_strlen(name) < win_col - 1) {
        (*len) += 2;
        separator = ' ';
    }
    else {
        (*len) = 0;
        separator = '\n';
    }
    return separator;
}
