#include "../inc/pathfinder.h"

static void mx_cmp_paths(t_path **new_path, t_path **current_path, int *flag) {
    if (*new_path && *current_path) {
        if ((*new_path)->id != (*current_path)->id || (*new_path)->dis != (*current_path)->dis) {
            *flag = 1;
        }
    }
    if (!(*new_path) || !(*current_path)) {
        *flag = 1;
    }
}

static void mx_step_to_next_path(t_path **old_path, t_path **path, t_path **new) {
    *path = *new;
    *old_path = (*old_path)->next_path;
}

int mx_unique_path(t_path **new, t_path **current) {
    t_path *path = *new;
    t_path *old_path = *current;
    int flag = -1;

    while (old_path) {
        if (old_path->next_connect == NULL || !path) {
            mx_cmp_paths(&path, &old_path, &flag);
            mx_step_to_next_path(&old_path, &path, &(*new));

            if (flag == -1) {
                return -1;
            }
            
            if (old_path) {
                flag = -1;
            }
            continue;
        }

        mx_cmp_paths(&path, &old_path, &flag);
        path = path->next_connect;
        old_path = old_path->next_connect;
    }

    return flag;
}
