#include "../inc/pathfinder.h"

t_path *mx_add_path(t_path **prev, int islnd, int dis) {
    t_path *new_path = NULL;
    t_path *current_path = NULL;
    t_path *fast_path = NULL;
    t_path *res_path = NULL;

    if (*prev) {
        current_path = *prev;
    }

    res_path = mx_add_single_path(&current_path, islnd, dis);
    fast_path = res_path;

    if (current_path) {
        current_path = current_path->next_path;
    }

    for (; current_path; current_path = current_path->next_path) {
        new_path = mx_add_single_path(&current_path, islnd, dis);
        mx_add_link(&fast_path, &new_path);
        fast_path = fast_path->next_path;
    }

    return res_path;
}
