#include "uls.h"

static void print_reg_file(t_file *file);
static void print_dir(t_file *file);

void mx_print_color_name(t_file *file) {
    if (S_ISDIR(file->ffs.st_mode))             //dir
        print_dir(file);
    else if (S_ISLNK(file->ffs.st_mode))        //link
        mx_printstr(MAG);
    else if (S_ISBLK(file->ffs.st_mode))        //block
        mx_printstr(BLOCK);
    else if (S_ISCHR(file->ffs.st_mode))        //character special
        mx_printstr(CHR);
    else if (S_ISFIFO(file->ffs.st_mode))       //fifo
        mx_printstr(YEL);
    else if (S_ISSOCK(file->ffs.st_mode))       //socket
        mx_printstr(GRN);
    else if (S_ISREG(file->ffs.st_mode)) {
        print_reg_file(file);
    }
    mx_printstr(file->filename);
    mx_printstr(RESET);
}

static void print_dir(t_file *file) {
    if (file->perm[8] == 'w' && ((file->perm[9] == 't')
        || (file->perm[9] == 'T')))           //a-dir_writeothers_sticky
        mx_printstr(DIR_T);
    else if (file->perm[8] == 'w' && (file->perm[9] == 'x'))
        mx_printstr(DIR_X);                   //dir_writeothers_NOsticky
    else
        mx_printstr(BLU);                    //dir
}

static void print_reg_file(t_file *file) {
    if ((file->perm[3] == 's') || (file->perm[3] == 'S'))
        mx_printstr(BLK_F_RED_B );
    else if ((file->perm[6] == 's') || (file->perm[6] == 'S'))
        mx_printstr(BLK_F_CYAN_B);
    else if (file->perm[3] == 'x')
        mx_printstr(RED);
    else
        mx_printstr(RESET);
}
