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

#define ULS_FLAGS "ACRSacfglnortu1" // [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]

typedef struct s_uls {
	void *data;
    int len;
	struct s_uls *next;
} t_uls;

typedef struct s_file {
	char *path;			// = dir/filename
	char *filename; 	// d_name in readdir
	struct stat ffs; 	// stat
	char *owner;
	char *group;
} t_file;

typedef struct s_maxlens_for_print {
	int l_links;
	int l_owner;
	int l_group;
	int l_size;
} t_maxlens_for_print;

typedef struct s_cmd {
	int print_func;
	int sort_type;
	int time_type;

	bool error_null_args; 		// if one of them NULL
	bool print_recursion;		// -R
	bool print_reverse;			// -r

	bool print_dots_folder;		// -A
	bool print_hidden;			// -a
	bool print_f;				// enable -A, -a disable all sortings, -t, -r

	bool print_owner;			// -g
	bool print_group;			// -o
	bool print_owner_group_num;	// -n

	// bool format_h;				// -h
	// bool format_at_symbol;		// -@
	// bool format_e;				// -e
	// bool format_T;				// -T


} t_cmd;

enum e_time_type {
    time_mtime,			/* default */
    time_ctime,			/* -c */
    time_atime			/* -u */
};
enum e_print_type {
    long_format,		// -l
    std_format,			// -C
    col_format			// -1
};

enum sort_type{
	sort_none,			// -f
    sort_name,			/* default */
    sort_size,			/* -S */
    sort_time,			/* -t */
};

// -------------------------------- to mylibmx
void mx_printspaces(int count);
void mx_clear_list(t_list **list);

int mx_check(int argc, char **argv);
bool mx_isdir(char *filename, t_list *q);
bool mx_ishidden(char *filename, t_list *q);
t_cmd *mx_create_command(int argc, char **argv); // получаешь комманду
t_file *mx_get_filesattr(char *filename, char *directory, t_cmd *c);
t_list *mx_get_files_list_dir(char *dir, t_cmd *c); // получаешь лист атрибутов содержимого директории
t_maxlens_for_print *mx_get_lens_for_print(t_list *lf);

// ---------------------------------------- print functions
void mx_print_long_format(t_list *lf, t_cmd *c);
void mx_print_std_format(t_list *lf);
void mx_print_col_format(t_list *lf);

// ---------------------------------------- for long print
void mx_print_permissions(t_file *file);
void mx_print_acl(char *file);
void mx_print_nlink(t_file *file, t_maxlens_for_print *ml);
void mx_print_size(t_file *file, t_maxlens_for_print *ml);
void mx_print_time(t_file *file, t_cmd *c);
void mx_print_linkname(t_file *file);

// ---------------------------------------- sort functions
t_list *mx_sort_uls_list(t_list *list, t_cmd *c, bool (*cmp)(void *a, void *b, t_cmd *c));
bool mx_strcmp_names(void *d1, void *d2, t_cmd *c);
bool mx_strcmp_size(void *d1, void *d2, t_cmd *c);
bool mx_strcmp_mtime(void *d1, void *d2, t_cmd *c);
bool mx_strcmp_atime(void *d1, void *d2, t_cmd *c);
bool mx_strcmp_ctime(void *d1, void *d2, t_cmd *c);

// ---------------------------------------- clear leaks
void mx_clear_filesattr_list(t_list **fl);

#endif
