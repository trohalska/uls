#include "uls.h"

t_list *mx_get_files_list_dir(char *dir) {
    t_list *lf = NULL;
    DIR *directory;
    struct dirent *entry;

    if (!(directory = opendir(dir))) {
        //mx_printerr(get_opendir_error(dir));
        mx_printerr("uls: : Permission denied (дописать)\n");
    }
    else {
        while ((entry = readdir(directory))) {
            if (entry->d_name[0] != '.')
                mx_push_back(&lf, mx_get_filesattr(entry->d_name));
        }
        closedir(directory);
    }
    return lf;
}
