#include "../inc/pathfinder.h"

void mx_push_path_back(t_path **path, t_path **prev, int islnd, int dis) {
    t_path *new_path = NULL;
    t_path *last_path = *path;
    t_path *current_path = *prev;

    for (; last_path->next_path != NULL; last_path = last_path->next_path) {}

    for (; current_path; current_path = current_path->next_path) {
        new_path = mx_add_single_path(&current_path, islnd, dis);

        if (mx_unique_path(&new_path, &(*path)) == 1) {
            mx_add_link(&last_path, &new_path);
            last_path = last_path->next_path;
        }
    }
}
