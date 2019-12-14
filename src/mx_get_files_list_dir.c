#include "uls.h"

static t_list *mx_sort_ls_list(t_list *list, bool (*cmp)(void *a, void *b));
static bool strcmp_names_bool(void *d1, void *d2);

t_list *mx_get_files_list_dir(char *dir, t_command *c) {
    // char *str = NULL;
    t_list *lf = NULL;
    DIR *directory;
    struct dirent *entry;

    if (!(directory = opendir(dir))) {
        int i = mx_strlen(dir) - 1;

        if (dir[i] == '/')
            perror("uls: ");
        else {
            while (dir[i] != '/')
                i--;
            mx_printerr("uls: ");
            perror(&dir[i + 1]);
        }
    }
    else {
        while ((entry = readdir(directory))) {
            if (entry->d_name[0] != '.')
                mx_push_back(&lf, mx_get_filesattr(entry->d_name, dir, c));
        }
        closedir(directory);
    }
    mx_sort_ls_list(lf, strcmp_names_bool);
    return lf;
}

static t_list *mx_sort_ls_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    t_list *help = NULL, *store = list, *tmp = list;
    void *swap_data;

    while (list) {
        help = store;
        while (help) {
            t_file *q = help->data;
            if (help->next &&
                cmp(q->filename, ((t_file *)help->next->data)->filename)) {
                swap_data = help->data;
                help->data = help->next->data;
                help->next->data = swap_data;
            }
            help = help->next;
        }
        list = list->next;
    }
    return tmp;
}

static bool strcmp_names_bool(void *d1, void *d2) {
	char *s1 = d1;
	char *s2 = d2;

    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
	if ((*s1 - *s2) > 0)
    	return true;
	else
		return false;
}
