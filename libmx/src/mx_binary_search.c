#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int mid;
    int first = 0;
    int last = size - 1;

    for (; first <= last;) {
        (*count)++;
        
        mid = (last + first) / 2;

        if (mx_strcmp(arr[mid], s) > 0) {
            last = mid - 1;
        }
        else if (mx_strcmp(arr[mid], s) == 0) {
            return mid;
        }
        else
            first = mid + 1;
    }
    *count = 0;
    return -1;
}
