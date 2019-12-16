#include "uls.h"

static void get_mode(t_file *file, struct stat fs);
static char get_acl(char *file);
static void get_owner_group(t_file *file, struct stat fs, t_cmd *c);
static void get_time(t_file *file, struct stat fs, t_cmd *c);
static void get_path(t_file *file, char *dir);

t_file *mx_get_filesattr(char *filename, char *directory, t_cmd *c) {
    t_file *file = NULL;
	struct stat fs;

	if (!filename || !directory || !c)
		return file;
	file = malloc(sizeof(t_file));
	// stat(filename, &fs);
	file->filename = mx_strdup(filename);
	get_path(file, directory);
    lstat(file->path, &fs);
    file->ffs = fs;
	file->blocks = fs.st_blocks;
	get_mode(file, fs);
	file->links = fs.st_nlink;
	get_owner_group(file, fs, c);
	file->size = fs.st_size;
	get_time(file, fs, c);
    return file;
}

static void get_path(t_file *file, char *dir) {
    int len = mx_strlen(dir);
	char *tmp = NULL;

	if (!file || !dir)
		return;
	// if (file->filename[0] != '/') {
    // 	tmp = mx_strjoin(dir, "/");
	// 	file->path = mx_strjoin(tmp, file->filename);
	// 	free(tmp);
	// }
	// else {
    //     file->path = mx_strjoin(dir, file->filename + 1);
    // }


	if (dir[len - 1] != '/' && file->filename[0] != '/') {
    	tmp = mx_strjoin(dir, "/");
		file->path = mx_strjoin(tmp, file->filename);
		free(tmp);
	}
	else if ((dir[len - 1] == '/' && file->filename[0] != '/')
			|| (dir[len - 1] != '/' && file->filename[0] == '/')) {
		file->path = mx_strjoin(dir, file->filename);
	}
	else if (dir[len] == '/' && file->filename[0] == '/') {
        file->path = mx_strjoin(dir, file->filename + 1);
    }
}

static void get_mode(t_file *file, struct stat fs) {
	char *res = mx_strnew(11);

	res[0] = S_ISBLK(fs.st_mode) ? 'b' : \
			 S_ISCHR(fs.st_mode) ? 'c' : \
			 S_ISDIR(fs.st_mode) ? 'd' : \
			 S_ISSOCK(fs.st_mode) ? 's' : \
			 S_ISFIFO(fs.st_mode) ? 'p' : \
			 S_ISLNK(fs.st_mode) ? 'l' : '-';
	res[1] = (S_IRUSR & fs.st_mode) ? 'r' : '-';
	res[2] = (S_IWUSR & fs.st_mode) ? 'w' : '-';
	res[3] = (S_IXUSR & fs.st_mode) ? 'x' : '-';
	res[4] = (S_IRGRP & fs.st_mode) ? 'r' : '-';
	res[5] = (S_IWGRP & fs.st_mode) ? 'w' : '-';
	res[6] = (S_IXGRP & fs.st_mode) ? 'x' : '-';
	res[7] = (S_IROTH & fs.st_mode) ? 'r' : '-';
	res[8] = (S_IWOTH & fs.st_mode) ? 'w' : '-';
	res[9] = (S_ISTXT & fs.st_mode) ? 't' : \
			 (S_IXOTH & fs.st_mode) ? 'x' : '-';
	res[10] = get_acl(file->path);
	file->mode = res;
}

static char get_acl(char *file) {
	char character;
	ssize_t xattr;
	acl_t acl;

	xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(file, ACL_TYPE_EXTENDED);
    if (xattr > 0)
        character = '@';
    else if (acl == NULL)
        character = ' ';
    else
        character = '+';
	acl_free(acl);
    return character;
}

static void get_owner_group(t_file *file, struct stat fs, t_cmd *c) {
    struct passwd *pw;
	struct group *grp;
	char *tmp;

    pw = getpwuid(fs.st_uid);
    if (pw->pw_name != NULL && !(c->print_owner_group_num))
        file->owner = mx_strdup(pw->pw_name);
    else {
		tmp = mx_itoa(fs.st_uid);
    	file->owner = mx_strdup(tmp);
		free(tmp);
	}
    grp = getgrgid(fs.st_gid);
    if (grp != NULL && !(c->print_owner_group_num))
        file->group = mx_strdup(grp->gr_name);
    else {
		tmp = mx_itoa(fs.st_gid);
		file->group = mx_strdup(tmp);
		free(tmp);
	}
}

static void get_time(t_file *file, struct stat fs, t_cmd *c) {
	char *str = NULL;
    int len;

    if (c->time_type == time_mtime) {
		str = ctime(&fs.st_mtime);
	    len = mx_strlen(str);
		file->time = mx_strnew(len - 13);
		file->time = mx_strncpy(file->time, str + 4, len - 13);
	}
	else if (c->time_type == time_atime) {
		str = ctime(&fs.st_atime);
	    len = mx_strlen(str);
		file->time = mx_strnew(len - 13);
		file->time = mx_strncpy(file->time, str + 4, len - 13);
	}
	else {
		str = ctime(&fs.st_ctime);
	    len = mx_strlen(str);
		file->time = mx_strnew(len - 13);
		file->time = mx_strncpy(file->time, str + 4, len - 13);
	}
}
