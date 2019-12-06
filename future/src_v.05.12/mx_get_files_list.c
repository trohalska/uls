#include "uls.h"

static t_list *get_files_dir(char *dir);

t_list *mx_get_files_list(char **files) {
    t_list *files_list = NULL;
    int i = 0;
    
    if (*files == NULL) {
        files_list = get_files_dir(".");
    }
    while (files[i]) {
        mx_push_back(&files_list, mx_get_filesattr(files[i]));
        i++;
    }
    return files_list;
}

static t_list *get_files_dir(char *dir) {
    t_list *list_files = NULL;
    DIR *directory;
    struct dirent *entry;

    if (!(directory = opendir(dir))) {
        //mx_printerr(get_opendir_error(dir));
        mx_printerr("uls: : Permission denied (дописать)\n");
    }
    else {
        while ((entry = readdir(directory))) {
            mx_push_back(&list_files, mx_get_filesattr(entry->d_name));
        }
        closedir(directory);
    }
    return list_files;
}
