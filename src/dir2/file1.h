#ifndef LIBMX_H
#define LIBMX_H

//#include "inc/libmx.h" // for makefile
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>

//#include "../libmx/inc/libmx.h"
//#include <string.h>

    /*
    * For ULS only.
    */
typedef struct s_fileattr {
    int number;
    int count;
    int* path;
    int distance;
    struct s_all_paths *next;
} t_fileattr;

void mx_pf_errors(int c, char *v[]);
char **mx_get_arr_islands(int G, char **strarr);
int **mx_get_matrix(int G, char *str, char **arr_islands);
char **mx_pf_split(const char *s);
int **mx_create_dex_matrix(int **matrix, int g);
int **mx_alg_deijkstra(int **dex, int *distance, int g, int startnode);
t_all_paths *mx_get_all_paths(int **dex, int G);
void mx_printpaths(t_all_paths *paths, int **matrix, char **arr_islands);

#endif
