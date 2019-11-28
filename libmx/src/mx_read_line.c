#include "libmx.h"

static char *get_last(int buf_size, char delim, const int fd);

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    if (fd < 0 || fd > 4096 || buf_size <= 0)
        return -1;
    static char *remainder[4096];
    char *last = get_last(buf_size, delim, fd);
    if (!last)
        return 0;
    char *tmp = mx_strjoin(remainder[fd], last);
    int delim_index = mx_get_char_index(tmp, delim);
    tmp[delim_index] = '\0';
    remainder[fd] = mx_strdup(tmp + delim_index + 1);
    *lineptr = mx_strdup(tmp);
    mx_strdel(&tmp);
    return mx_strlen(*lineptr);
}

static char *get_last(int buf_size, char delim, const int fd) {
    char *tmp = NULL;
    char *result_str = NULL;
    char buf[buf_size + 1];
    int read_result = 0;
    int delim_index;
    
    while ((read_result = read(fd, buf, buf_size)) > 0) {
        buf[read_result] = '\0';
        tmp = mx_strjoin(result_str, buf);
        mx_strdel(&result_str);
        result_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(result_str, delim);
        if (delim_index >= 0)
            break;
    }
    return result_str;
}
