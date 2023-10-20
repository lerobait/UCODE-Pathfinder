#include "../inc/pathfinder.h"

void mx_pop_isnd_mid(t_islnd **remaining, int indx) {
    if (!remaining || !(*remaining)) {
        return;
    }

    t_islnd *prev = NULL;
    t_islnd *curr = *remaining;

    for (; curr != NULL && curr->islnd_indx != indx; prev = curr, curr = curr->next) {}

    if (curr && curr->islnd_indx == indx) {
        if (prev) {
            prev->next = curr->next;
        }
        else {
            *remaining = curr->next;
        }
        mx_del_path(&curr->path);
        free(curr);
    }
}
