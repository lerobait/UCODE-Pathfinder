#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst && cmp) {

        for (t_list *tmp1 = lst; tmp1; tmp1 = tmp1->next) {

            for (t_list *tmp2 = lst; tmp2->next; tmp2 = tmp2->next) {

                if (cmp(tmp2->data, tmp2->next->data))
                    mx_swap(&tmp2->data, &tmp2->next->data);
            }
        }
    }
    return lst;
}
