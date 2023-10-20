#include "../inc/pathfinder.h"

void mx_pop_islnd_front(t_islnd **head) {
    if (!head || !(*head)) {
        return;
    }

    t_islnd *next_isl = (*head)->next;
    free(*head);
    *head = next_isl;   
}
