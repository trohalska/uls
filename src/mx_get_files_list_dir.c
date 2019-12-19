#include "uls.h"

t_list *mx_get_files_list_dir(char *dir, t_cmd *c) {
    t_list *lf = NULL;
    DIR *directory;
    struct dirent *entry;

    if(!dir || !c)
        return NULL;
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
            if(c->print_hidden == true || c->print_f == true)
                mx_push_back(&lf, mx_get_filesattr(entry->d_name, dir, c));
            else if (c->print_dots_folder == true){
                if (mx_strcmp(entry->d_name, ".") != 0
                && mx_strcmp(entry->d_name, "..") != 0)
                    mx_push_back(&lf, mx_get_filesattr(entry->d_name, dir, c));
            }
            else if (entry->d_name[0] != '.')
                mx_push_back(&lf, mx_get_filesattr(entry->d_name, dir, c));
        }
        closedir(directory);
    }
    return lf;
}
