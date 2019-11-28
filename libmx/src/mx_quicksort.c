#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int sum = 0;
    if (!arr) return -1;
    if (left < right)
    {
        int first = left, last = right;
        char *middle = arr[(first + last) / 2];
        for (; mx_strlen(arr[first]) < mx_strlen(middle); first++);
        for (; mx_strlen(arr[last]) > mx_strlen(middle); last--);
        if (first <= last)
        {
            if (mx_strlen(arr[first]) != mx_strlen(arr[last]) 
                    && arr[first] != arr[last]) sum++; 
            char *tmp = arr[first];
            arr[first] = arr[last];
            arr[last] = tmp;
            first++;
            last--;
        }
        while (first <= last) {
            while (mx_strlen(arr[first]) < mx_strlen(middle)) first++;
            while (mx_strlen(arr[last]) > mx_strlen(middle)) last--;
            if (first <= last)
            {
                if (mx_strlen(arr[first]) != mx_strlen(arr[last]) 
                    && arr[first] != arr[last]) sum++; 
                char *tmp = arr[first];
                arr[first] = arr[last];
                arr[last] = tmp;
                first++;
                last--;
            }
        }
        sum += mx_quicksort(arr, left, last);
        sum += mx_quicksort(arr, first, right);
    }
    return sum;
}
