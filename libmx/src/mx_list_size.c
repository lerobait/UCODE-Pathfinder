#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    if (list == NULL) return 0;

    int size = 0;
    t_list *tmp = list;

    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}
