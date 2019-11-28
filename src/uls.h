#ifndef ULS_H
#define ULS_H

//#include "inc/libmx.h" // for makefile
#include "../libmx/inc/libmx.h"

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

void mx_if_no_argv(char *dir);
void mx_print_many_col(t_uls *list);
void mx_push_back_uls(t_uls **list, void *data, int len);



#endif
