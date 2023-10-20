#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int rigth) {
    if (arr == NULL)
        return -1;

    int count = 0;

    if (left < rigth) {
        int first = left;
        int last = rigth;
        int mid = (first + last) / 2;

        while (first <= last) {
            while (mx_strlen(arr[first]) < mx_strlen(arr[mid]))
                first++;

            while (mx_strlen(arr[last]) < mx_strlen(arr[mid]))
                last--;

            if (first <= last) {
                if (mx_strlen(arr[last]) != mx_strlen(arr[first])) {
                    char *tmp = arr[first];
                    arr[first] = arr[last];
                    arr[last] = tmp;
                    count++;
                }
                last--;
                first++;
            }
        }
        count += mx_quicksort(arr, left, last);
        count += mx_quicksort(arr, first, rigth);
    }
    return count;
}
