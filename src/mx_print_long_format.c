#include "uls.h"

// static void print(t_file *file);

//      void mx_print_long_format(t_list *list_files) {
//     t_length_file *length_file = mx_create_length_file(list_files);

//     t_list *current = list_files;
//     while (current) {
//         print_file(current->data, length_file);
//         current = current->next;
//     }
// }

void print_long_format(t_file *file) {
    mx_printstr(file->mode);
    mx_printstr(" ");    // mx_print_spaces(l_f->links_l - mx_numlen(file->links));
    mx_printint(file->links);
    mx_printspaces(1);
    mx_printstr(file->owner);
    // mx_print_spaces(l_f->owner_l - mx_strlen(file->owner));
    mx_printspaces(2);
    mx_printstr(file->group);
    mx_printstr(" ");     // mx_printspaces(l_f->group_l - mx_strlen(file->group));
    //mx_print_spaces(2 + l_f->size_l - mx_numlen(file->size));
    mx_printstr(mx_itoa(file->size));
    mx_printspaces(1);
    mx_printstr(file->m_time);
    mx_printspaces(1);
    mx_printstr(file->filename);
    //mx_print_link(file);
    mx_printstr("\n");
}
