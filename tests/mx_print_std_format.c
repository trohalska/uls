#include "uls.h"

static int get_maxlen_name(t_list *lf);
static char **get_names(t_list *list, int size);
static void print_filesnames(char **names, int size, int max, int rows);
static void print_fnames_isatty(char **names, int size, int max, int cols);

void mx_print_std_format(t_list *lf) {
    int maxlencol = get_maxlen_name(lf) + 8;
    int count_names = mx_list_size(lf);
    char **names = get_names(lf, count_names);
    int cols;
    struct winsize win;

    if (!lf || !names)
        return;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    cols = win.ws_col / (maxlencol - 1);
    if (isatty(STDOUT_FILENO))
        print_filesnames(names, count_names, maxlencol, cols);
    else
        print_fnames_isatty(names, count_names, maxlencol, 2);
    mx_del_strarr(&names);
}

static int get_maxlen_name(t_list *lf) {
    int max = 0;
    int tmp = 0;

    if (!lf)
        return 0;
    for (t_list *q = lf; q != NULL; q = q->next) {
        tmp = mx_strlen(((t_file *)q->data)->filename);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

static char **get_names(t_list *list, int size) {
    char **result = NULL;
    int i = 0;

    if (!list)
        return NULL;
    result = (char **)malloc((size + 1) * sizeof(char *));
    for (t_list *q = list; q != NULL; q = q->next, i++)
        result[i] = mx_strdup(((t_file *)q->data)->filename);
    result[size] = NULL;
    return result;
}

static void print_filesnames(char **names, int size, int max, int cols) {
    int rows;
    int delim;

    if (!names || !size || !cols || !max)
        return;
    rows = size / cols;
    if (size % cols)
        rows += 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < size; j += rows) {
            delim = max - mx_strlen(names[i + j]) + 2;
            mx_printstr(names[i + j]);
            if (names[i + j + 1] && (i + j + rows < size)) {
                mx_printchar('\t');
                for (; delim / 8 > 1; delim -= 8)
                    mx_printchar('\t');
            }
        }
        mx_printchar('\n');
    }
}

static void print_fnames_isatty(char **names, int size, int max, int cols) {
    int rows;

    if (!names || !size || !cols || !max)
        return;
    rows = size / cols;
    if (size % cols)
        rows += 1;
    for (int i = 0; i < size; i += 2) {
        mx_printstr(names[i]);
        if (names[i + 1]) {
            mx_printspaces(max - mx_strlen(names[i]));
            mx_printchar('\t');
            mx_printstr(names[i + 1]);
        }
        mx_printchar('\n');
    }
}
