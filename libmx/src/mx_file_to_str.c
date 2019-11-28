#include "libmx.h"

static int count_bytes_and_checks(const char *file);

char *mx_file_to_str(const char *file) {
    if (!file) return NULL;
    char buf[1];
    int f = open(file, O_RDONLY);
    if (f < 0)
        return NULL;
    int n = read(f, buf, sizeof(buf));
    if (n <= 0) 
        return NULL;
    char *s = mx_strnew(count_bytes_and_checks(file));
    char *p = s;
    while (n > 0) {
    	*s = *buf;
        n = read(f, buf, sizeof(buf));
    	s++;
    }
    close(f);
	return p;
}

static int count_bytes_and_checks (const char *file) {
    char buf[1];
    int k = 0;
    int f = open(file, O_RDONLY);
    while (read(f, buf, sizeof(buf)) > 0)
    	k++;
    close(f);
    return k;
}
