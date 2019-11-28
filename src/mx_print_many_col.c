#include "uls.h"

int get_maxlen_name(t_uls *list);
int mx_get_uls_list_size(t_uls *list);
char **get_filesnames(t_uls *list, int size);
void print_filesnames(char **names, int size, int max, int rows);
void print_spaces(int count);

void mx_print_many_col(t_uls *list) {
    int maxlencol = get_maxlen_name(list);
    int count_names = mx_get_uls_list_size(list);
    int rows = 0, cols = 0;
    char **filesnames = get_filesnames(list, count_names);
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    cols = win.ws_col / (maxlencol + 1);
    rows = count_names / cols;
    if (count_names % cols) 
        rows += 1;        
    print_filesnames(filesnames, count_names, maxlencol, rows);
    mx_del_strarr(&filesnames);
}

int get_maxlen_name(t_uls *list) {
    int max = 0;
    t_uls *i;
    
    for (i = list; i != NULL; i = i->next)
        if (i->len > max)
            max = i->len;
    return max;
}

int mx_get_uls_list_size(t_uls *list) {
	int k = 1;

	if (list == NULL)
		return 0;
	for (t_uls *p = list; p && p->next != NULL; p = p->next)
		k++;
	return k;
}

char **get_filesnames(t_uls *list, int size){
    char **result = (char **)malloc((size + 1) * sizeof(char *));
    int i = 0;    
    for (t_uls *j = list; j != NULL; j = j->next, i++)
        result[i] = mx_strdup(j->data);
    result[size] = NULL;
    return result;
}

void print_filesnames(char **names, int size, int max, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < size; j += rows) {
            mx_printstr(names[i + j]);
            if (mx_strlen(names[i + j]) < max) {
                if (i + j < size - rows)
                    print_spaces(max - mx_strlen(names[i + j]));
            }
            else {
                if (i + j < size - rows)
                    mx_printchar(' ');
            }          
        }
        mx_printchar('\n');
    }
}

void print_spaces(int count) {
    for (int i = 0; i <= count; i++)
        mx_printchar(' ');
}
