#include "../inc/pathfinder.h"

static t_path *mx_add_single(t_path **prev) {
    t_path *last_path = *prev;
    t_path *res = NULL;
    t_path *new_path = NULL;

    res = mx_create_path(last_path->id, last_path->dis);
    new_path = res;
    last_path = last_path->next_connect;

    for (; last_path; last_path = last_path->next_connect) {
        new_path->next_connect = mx_create_path(last_path->id, last_path->dis);
        new_path = new_path->next_connect;
    }

    return res;
}

t_path *mx_cpy_path(t_path **data) {
    t_path *new_path = NULL;
    t_path *current_path = NULL;
    t_path *fast_path = NULL;
    t_path *res_path = NULL;

    if (*data) {
        current_path = *data;
    }

    res_path = mx_add_single(&current_path);
    fast_path = res_path;
    current_path = current_path->next_path;

    for (; current_path; current_path = current_path->next_path) {
        new_path = mx_add_single(&current_path);
        mx_add_link(&fast_path, &new_path);
        fast_path = fast_path->next_path;
    }

    return res_path;
}
