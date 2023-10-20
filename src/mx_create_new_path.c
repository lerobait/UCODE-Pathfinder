#include "../inc/pathfinder.h"

void mx_create_new_path(t_islnd **islnd, t_path **path, int indx, int dis) {
    t_islnd *new_islnd = (t_islnd *)malloc(sizeof(t_islnd));
    new_islnd->islnd_dis = dis;
    new_islnd->islnd_indx = indx;
    new_islnd->next = NULL;
    new_islnd->path = NULL;

    if (path && *path) {
        new_islnd->path = mx_cpy_path(&(*path));
    }

    if (*islnd == NULL) {
        *islnd = new_islnd;
        return;
    }

    t_islnd *curr_islnd = *islnd;

    for (; curr_islnd->next != NULL; curr_islnd = curr_islnd->next) {}

    curr_islnd->next = new_islnd;
}
