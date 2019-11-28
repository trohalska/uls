#include "uls.h"

int main(int argc, char *argv[]) {
    if (argc < 2)
		mx_if_no_argv(".");

    if(argv[0]) {}
    

    // else if (mx_strcmp(argv[1], "-l") != 0)
    //     for_each_argv(argc, argv);
	// else if (mx_strcmp(argv[1], "-l") == 0) {
	// 	DIR *d = opendir(".");
	// 	get_contents(d);
	// 	closedir(d);
	// }

	// system("leaks -q uls");
    return 0;
}

// если нет аргументов
/* если есть аргументы */
/* -||-   первый не флаг*/
/* -||-   первый флаг*/


 //---------errors
    // while ((entry = readdir(dir)) != NULL) {
    //     if (mx_strcmp(v[1], entry->d_name) )
    // }


    // if (c == 1) {
    //     while ((entry = readdir(dir)) != NULL) {
    //         mx_printstr(entry->d_name);
    //         // printf("%d - %s [%d] %d\n", entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    //     }
    // }

    // struct stat *s;
    // stat("uls.h", s);

    // printf("%lld\n", s->st_size);
    
    // closedir(dir);

// #include <stdio.h>
// #include <string.h>
// #include <dirent.h> // opendir, closedir, readdir, rewinddir и Co.
// #include <regex.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include "dirlist.h"
// #include <time.h>
 
// int main(int argc, char *argv[])
// {
//     struct stat dir_stat_info;
 
// .../*
// ...Получаем имя папки.
// ...*/
 
//     if(lstat(dir_name, &dir_stat_info) < 0)
//     {
//         perror(dir_name);
//         return 1;
//     }
 
//     if (!S_ISDIR(dir_stat_info.st_mode))
//     {
//         puts("It is not a dir!");
//     }
// return 0;
// }
