#include "uls.h"

static void get_mode(t_file *file, struct stat fs);
static char get_acl(char *file);
static void get_owner(t_file *file, struct stat fs);
static void get_group(t_file *file, struct stat fs);
static void mx_get_time_attr(t_file *file, struct stat fs);

t_file *mx_get_filesattr(char *filename) {
    t_file *file = malloc(sizeof(t_file));
	struct stat fs;

	stat(filename, &fs);

	file->filename = filename;
	file->blocks = fs.st_blocks;
	get_mode(file, fs);
	file->links = fs.st_nlink;
	get_owner(file, fs);
	get_group(file, fs);
	file->size = fs.st_size;
	mx_get_time_attr(file, fs);
    return file;
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
	res[10] = get_acl(file->filename);
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

static void get_owner(t_file *file, struct stat fs) {
    struct passwd *pw;

    pw = getpwuid(fs.st_uid);
    if (pw->pw_name != NULL)
        file->owner = mx_strdup(pw->pw_name);
    else
    	file->owner = mx_itoa(fs.st_uid);
}

static void get_group(t_file *file, struct stat fs) {
    struct group *grp;

    grp = getgrgid(fs.st_gid);
    if (grp != NULL)
        file->group = mx_strdup(grp->gr_name);
    else
		file->group = mx_itoa(fs.st_gid);
}

// static void get_old_time(t_file *file, char *str, int length);

// void mx_get_modified_time(t_file *file, struct stat file_stat) {
//     char *str;
//     int length_str;

//     file->d_modf_time = file_stat.st_mtime;
//     str = ctime(&file_stat.st_mtime);
//     length_str = mx_strlen(str);
//     file->full_modf_time = mx_strdup(str);

//     if (time(NULL) - file->d_modf_time < 31556926 / 2
//             && ((time(NULL) - file->d_modf_time >= 0))) {
//         file->modf_time = mx_strnew(length_str - 13);
//         file->modf_time = mx_strncpy(file->modf_time,
//                 str + 4, length_str - 13);
//         return;
//     }
//     get_old_time(file, str, length_str);
// }

// static void get_old_time(t_file *file, char *str, int length) {
//     int k = 0;

//     file->modf_time = mx_strnew(length - 13);
//     for (int i = 0; i < length - 1; i++) {
//         if ((i > 3 && i < 11) || i > 19) {
//             file->modf_time[k] = str[i];
//             k++;
//         }
//         if (i == 11) {
//             file->modf_time[k] = ' ';
//             k++;
//         }
//     }
// }

static void mx_get_time_attr(t_file *file, struct stat fs) {
    //get_m_time(file, fs);
	
	file->a_time = ctime(&fs.st_atime); // malloc?
    file->m_time = ctime(&fs.st_mtime);
    file->c_time = ctime(&fs.st_ctime);
}

    // mx_get_modified_time(file, fs);
    // mx_get_status_time(file, fs);
    // mx_get_creation_time(file, fs);
    // mx_get_access_time(file, fs);


