#include "uls.h"

void mx_get_time_attr(t_file *file, struct stat file_stat) {
    file->a_time = ctime(&file_stat.st_atime); // malloc?
    file->m_time = ctime(&file_stat.st_mtime);
    file->c_time = ctime(&file_stat.st_ctime);
    
}


    // mx_get_modified_time(file, file_stat);
    // mx_get_status_time(file, file_stat);
    // mx_get_creation_time(file, file_stat);
    // mx_get_access_time(file, file_stat);
