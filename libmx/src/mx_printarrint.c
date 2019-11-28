#include "libmx.h"

void mx_printarrint(int *arr, int G) 
{
    if (!arr) return;

    for (int i = 0; i < G; i++){        
        mx_printint(arr[i]);
        mx_printstr(" ");
    }
    mx_printstr("\n");
}
