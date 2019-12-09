#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h" // for makefile
//#include "../libmx/inc/libmx.h"

/*
* For ULS only.
*/

#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>

typedef struct s_uls {
	void *data;
    int len;
	struct s_uls *next;
} t_uls;

typedef struct s_file {
	char *path;
	char *filename; 	//d_name in readdir
	blkcnt_t blocks; 	//-s flag
	char *mode; 		//stat st_mode
	int links; 			//stat st_ino
    char *owner; 		//getpwuid(info.st_uid)
	char *group;  		//getgrgid(info.st_uid)
	size_t size; 		// stat st_size
	// char *a_time; 		//-u flag
	// char *m_time; 		//stat st_mtime
    // char *c_time; 		//-c flag
	char *time;
} t_file;

typedef struct s_maxlens_for_print {
	int l_links;
	int l_owner;
	int l_group;
	int l_size;
} t_maxlens_for_print;

typedef struct s_command {
	//(* print_func)(t_list *, t_command *);
	// (* sort_func)(t_list *);
	int print_func;
	int time_type;

	// bool print_hidden;			// -a
	// bool print_reverse;			// -r
	bool print_owner;			// -g
	bool print_group;			// -o
	bool print_owner_group_num;	// -n

	// bool format_h;				// -h
	// bool format_at_symbol;		// -@
	// bool format_e;				// -e
	// bool format_T;				// -T
} t_command;

enum e_time_type {
    time_mtime,			/* default */
    time_ctime,			/* -c */
    time_atime			/* -u */
};
enum e_print_type {
    long_format,
    // std_format,
    col_format
};

// -------------------------------- to mylibmx
void mx_printspaces(int count);

// ------------------ переделать
void mx_check(int argc, char **argv);
void mx_if_no_argv(DIR *entry);

// new
bool mx_isdir(char *filename, t_list *q);
bool mx_ishidden(char *filename, t_list *q);
t_command *mx_create_command(int argc, char **argv); // получаешь комманду
//t_list *mx_get_arg_f_d(int argc, char **argv, t_list **d_argv); // получаешь лист файлов и лист папок
t_file *mx_get_filesattr(char *filename, char *directory, t_command *c);
t_list *mx_get_files_list_dir(char *dir, t_command *c); // получаешь лист атрибутов содержимого директории
t_list *mx_get_files_list(t_list *files, char *dir, t_command *c); // получаешь лист атрибутов списка файлов
t_maxlens_for_print *mx_get_lens_for_print(t_list *lf);

void mx_print_all(int argc, char **argv, t_command *c); // печать
void mx_print_long_format(t_list *lf, t_command *c);
// void mx_print_std_format(DIR *dir, t_command *c); // ---------------rewrite
void mx_print_col_format(t_list *lf);

#endif
