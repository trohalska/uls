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
	blkcnt_t blocks; 	//-s flag
	char *mode; 		//stat st_mode
	int links; 			//stat st_ino
    char *owner; 		//getpwuid(info.st_uid)
	char *group;  		//getgrgid(info.st_uid)
	size_t size; 		// stat st_size
	char *a_time; 		//-u flag
	char *m_time; 		//stat st_mtime
    char *c_time; 		//-U flag
	char *status_time; 	//-c flag
    char *filename; 	//d_name in readdir
} t_file;

typedef struct s_maxlens_for_print {
	int l_links;
	int l_owner;
	int l_group;
	int l_size;
} t_maxlens_for_print;

typedef struct s_flags {
    void (*print)(t_list *);
} t_flags;

// -------------------------------- to mylibmx
void mx_printspaces(int count);

// ------------------ переделать
void mx_check(int argc, char **argv);
void mx_if_no_argv(DIR *entry);
void mx_standart_print(DIR *dir);
void mx_push_back_uls(t_uls **list, void *data, int len);

// new
bool mx_isdir(char *filename, t_list *q);
bool mx_ishidden(char *filename, t_list *q);
char *mx_get_flags(int argc, char **argv); // получаешь строку флагов
//t_list *mx_get_arg_f_d(int argc, char **argv, t_list **d_argv); // получаешь лист файлов и лист папок
t_file *mx_get_filesattr(char *filename);
t_list *mx_get_files_list_dir(char *dir); // получаешь лист атрибудов содержимого директории
t_list *mx_get_files_list(t_list *files); // получаешь лист атрибудов списка файлов
t_maxlens_for_print *mx_get_lens_for_print(t_list *lf);

void mx_print_all(int argc, char **argv, char *flags); // печать
void mx_print_long_format(t_list *list_files);
//void mx_print_std_format(DIR *dir); // --------------------------rewrite
void mx_print_one_dir(t_list *lf);

// typedef enum e_flag { // 33 flags:
// minus,
// dog, //  -@  -- display extended attribute keys and sizes in long (-l) output 
// one, //  -1  -- single column output
// l, //  -l  -- bacik case..
// A, //  -A  -- list all except . and ..
// B, //  -B  -- print octal escapes for control characters
// C, //  -C  -- list entries in columns sorted vertically
// F, //  -F  -- append file type indicators
// H, //  -H  -- follow symlinks on the command line
// L, //  -L  -- list referenced file for sym link
// P, //  -P  -- do not follow symlinks
// R, //  -R  -- list subdirectories recursively
// S, //  -S  -- sort by size
// T, //  -T  -- show complete time information
// a, //  -a  -- list entries starting with .
// b, //  -b  -- as -B, but use C escape codes whenever possible
// c, //  -c  -- status change time
// d, //  -d  -- list directory entries instead of contents
// f, //  -f  -- output is not sorted
// g, //  -g  -- long listing but without owner information
// h, //  -h  -- print sizes in human readable form
// i, //  -i  -- print file inode numbers
// k, //  -k  -- print sizes of 1k
// m, //  -m  -- comma separated
// n, //  -n  -- numeric uid, gid
// o, //  -o  -- display file flags
// p, //  -p  -- append file type indicators for directory
// q, //  -q  -- hide control chars
// r, //  -r  -- reverse sort order
// s, //  -s  -- display size of each file in blocks
// t, //  -t  -- sort by modification time
// u, //  -u  -- access time
// w, //  -w  -- print raw characters
// x, //  -x  -- sort horizontally
// size, // number of flags
// } t_flag;

#endif
