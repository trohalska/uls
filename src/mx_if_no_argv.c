#include "uls.h"

static void mx_ls_wf(DIR *dir);

void mx_if_no_argv() {
    DIR *entry = opendir(".");
    
    if (isatty(1))
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
