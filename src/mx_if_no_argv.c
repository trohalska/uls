#include "uls.h"

static void mx_ls_wf(DIR *dir);
int get_maxlen_name(t_uls *list);
int mx_get_uls_list_size(t_uls *list);
char **get_filesnames(t_uls *list, int size);
void print_filesnames(char **names, int size, int max, int rows);
void mx_standart_print(DIR *dir);
t_uls *create_node(void *data, int len);
void mx_push_back_uls(t_uls **list, void *data, int len);

void mx_if_no_argv(DIR *entry) {
    if (isatty(STDOUT_FILENO))
        mx_standart_print(entry);
    else
        mx_ls_wf(entry);
        //print_one_col(result);
    closedir(entry);
}

static void mx_ls_wf(DIR *dir) {
	struct dirent *entry1;

	while ((entry1 = readdir(dir)) != NULL) {
		if (entry1->d_name[0] != '.') {  // != 1 || mx_strcmp(entry1->d_name, "..") != 0)
			mx_printstr(entry1->d_name);
			mx_printchar('\n');
		}	
	}
}

void mx_standart_print(DIR *dir) {
    struct dirent *entry = NULL;
    t_uls *list = NULL;
    char **filesnames = NULL;
    int maxlencol = 0, count_names = 0, rows = 0, cols = 0;

    while ((entry = readdir(dir)) != NULL)
        if ((entry->d_name[0] == '.' ? false : true))
            mx_push_back_uls(&list, entry->d_name, mx_strlen(entry->d_name));
    maxlencol = get_maxlen_name(list);
    count_names = mx_get_uls_list_size(list);
    filesnames = get_filesnames(list, count_names);
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    cols = win.ws_col / (maxlencol + 2);
    rows = count_names / cols;
    if (count_names % cols) 
        rows += 1;        
    print_filesnames(filesnames, count_names, maxlencol + 1, rows);
    mx_del_strarr(&filesnames);
}

void mx_push_back_uls(t_uls **list, void *data, int len) {
    if (!list || !data) return;
    t_uls *tmp = create_node(data, len); // create new
    if (!tmp) return;
    t_uls *p = *list;
    if (*list == NULL) { // find Null-node
        *list = tmp;
        return;
    }
    else {
        while (p->next != NULL) // find Null-node
            p = p->next;
        p->next = tmp;
    }
}

t_uls *create_node(void *data, int len) {
    if (!data) return NULL;
    t_uls *temp = malloc(sizeof(t_uls));

    if (!temp) return NULL;
    temp->data = data;
    temp->len = len;
    temp->next = NULL;
    return temp;
}

char **get_filesnames(t_uls *list, int size){
    char **result = NULL;
    int i = 0;
    t_uls *j;

    result = (char **)malloc((size + 1) * sizeof(char *));
    for (j = list; j != NULL; j = j->next, i++)
        result[i] = mx_strdup(j->data);
    result[size] = NULL;
    return result;
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
    t_uls *p;

	if (list == NULL)
		return 0;
	for (p = list; p && p->next != NULL; p = p->next)
		k++;
	return k;
}

void print_filesnames(char **names, int size, int max, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < size; j += rows) {
            mx_printstr(names[i + j]);
            if (mx_strlen(names[i + j]) < max) {
                if (i + j < size - rows)
                    mx_printspaces(max - mx_strlen(names[i + j]));
            }
            else {
                if (i + j < size - rows)
                    mx_printstr(" ");
            }          
        }
        mx_printchar('\n');
    }
}
