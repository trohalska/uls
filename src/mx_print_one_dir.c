#include "uls.h"

void mx_print_one_dir(t_list *lf) {
    blkcnt_t res = 0;

    for (t_list *q = lf; q != NULL; q = q->next) {
        t_file *tmp = q->data;
        res += tmp->blocks;
    }
    mx_printstr("total ");
    mx_printint((int)res);
    mx_printstr("\n");

    mx_print_long_format(lf); // make with pointer to function
}

// void mx_print_ready_files(t_list *files, t_flags *flags) {
//     files = flags->filter(files);
//     if (!mx_list_size(files)) {
//         return;
//     }
//     flags->sort(files, flags->sort_functions);
//     if (!mx_check_file_error(files->data)) {
//         flags->print(files);
//     }
//     else {
//         print_error_file(files->data);
//     }
// }

// static void set_print_flag(t_flags *flags, bool *flags_arr) {
//     if (flags_arr[0]) {
//         flags->print = mx_print_o_format;
//     }
//     else if (flags_arr[1]) {
//         flags->print = mx_print_g_format;
//     }
//     else if (flags_arr[2]) {
//         flags->print = mx_print_long_format;
//     }
//     else {
//         flags->print = mx_print_std_format;
//     }
// }

