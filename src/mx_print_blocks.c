#include "uls.h"

void mx_print_blocks(char *name, t_maxlens_for_print *ml, t_cmd *c) {
	t_list *files_list = NULL;
	blkcnt_t res = 0;
    t_file *tmp;

	mx_printspaces(1);
    if (mx_isdir(name, NULL))
    	files_list = mx_get_files_list_dir(name, c);
    else
    	mx_push_back(&files_list, mx_get_filesattr(name, ".", c));

    for (t_list *q = files_list; q != NULL; q = q->next) {
        tmp = q->data;
        res += tmp->ffs.st_blocks;
    }
    mx_printint((int)res);
    mx_printspaces(1);

    if(ml) {}
}
