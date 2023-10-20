#include "../inc/pathfinder.h"

void mx_add_link(t_path **current_path, t_path **new_path) {
    t_path *curr = *current_path;

    for (; curr->next_connect; curr = curr->next_connect) {
        curr->next_path = *new_path;
    }

    curr->next_path = *new_path;
}
