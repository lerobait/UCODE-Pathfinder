#include "../inc/pathfinder.h"

t_path *mx_add_single_path(t_path **prev, int islnd, int dist) {
    t_path *new_path = NULL;
    t_path *last_path = *prev;
    t_path *res = NULL;

    if (!last_path) return res = mx_create_path(islnd, dist);

    res = mx_create_path(last_path->id, last_path->dis);
    new_path = res;
    last_path = last_path->next_connect;

    while (last_path) {
        new_path->next_connect = mx_create_path(last_path->id, last_path->dis);
        last_path = last_path->next_connect;
        new_path = new_path->next_connect;
    }

    new_path->next_connect = mx_create_path(islnd, dist);

    return res;
}
