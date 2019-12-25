#include "uls.h"

static void print_reg_file(t_file *file);
static void print_dir(t_file *file);

void mx_print_color_name(t_file *file) {
    if (S_ISDIR(file->ffs.st_mode))             //print if dir
        print_dir(file);
    else if (S_ISLNK(file->ffs.st_mode))           //link
        mx_printstr(MAG);
    else if (S_ISBLK(file->ffs.st_mode))           //block
        mx_printstr(BLOCK);
    else if (S_ISCHR(file->ffs.st_mode))           //c - character special file
        mx_printstr(CHR);
    else if (S_ISFIFO(file->ffs.st_mode))           //fifo yellow
        mx_printstr(YEL);
    else if (S_ISSOCK(file->ffs.st_mode))           //сокет!!!!!
        mx_printstr(MAG); //!!!!!!
    else if (S_ISREG(file->ffs.st_mode)) {
        print_reg_file(file);
    }
    mx_printstr(file->filename);
    mx_printstr(RESET);
}

static void print_dir(t_file *file) {
    if (file->perm[8] == 'w' && file->perm[9] == 't')
        mx_printstr(DIR_T);
    else
        mx_printstr(BLU);
}

static void print_reg_file(t_file *file) {
    if (file->perm[3] == 's')                   ///    [1;31m  Bold Red
        mx_printstr(BLK_F_RED_B );
    else if (file->perm[6] == 's')
        mx_printstr(BLK_F_CYAN_B);
    else if (file->perm[3] == 'x')               //red
        mx_printstr(RED);
    else
        mx_printstr(RESET);                     // default
}
