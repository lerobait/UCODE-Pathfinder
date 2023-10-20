#include "../inc/pathfinder.h"

static void mx_pop_all(t_path **head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    while ((*head)->next_connect != NULL) {
        t_path *next_path = (*head)->next_connect;
        free(*head);
        (*head) = next_path;
    }

    if ((*head)->next_connect == NULL && (*head)->next_path == NULL) {
        free(*head);
        *head = NULL;
    }
}

static void mx_pop_next(t_path **head) {
    if (!head || !(*head)) {
        return;
    }

    if ((*head)->next_path == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        t_path *tmp = (*head)->next_path;
        free(*head);
        *head = tmp;
    }
}

void mx_del_path(t_path **head) {
    if (!head || !(*head)) {
        return;
    }

    while (*head) {
        mx_pop_all(&(*head));
        mx_pop_next(&(*head));
    }
}
