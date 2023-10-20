#include "../inc/pathfinder.h"

static int mx_cmp(t_path *bond, t_path *fast) {
    for (; bond && fast; bond = bond->next_connect, fast = fast->next_connect) {
        if (bond->id > fast->id) {
            return 1;
        }
        else if (bond->id < fast->id) {
            return 0;
        }
    }

    return (bond != NULL);
}

static void mx_swp(t_path **disp, t_path **bond, t_path **fast) {
    t_path *tmp = (*bond)->next_path;
    t_path *curr;

    for (curr = *disp; curr->next_path != *bond; curr = curr->next_path) {}

    mx_add_link(&curr, &(*bond));
    curr = *disp;

    if (*disp == *bond) {
        *disp = *fast;
    }
    else {
        for (curr = *disp; curr && curr->next_path != *bond; curr = curr->next_path) {}

        mx_add_link(&curr, &(*bond));
    }

    mx_add_link(&(*bond), &(*fast)->next_path);
    mx_add_link(&(*fast), &tmp);
}

static void mx_swap_path(t_path **disp, t_path **bond, t_path **fast) {
    t_path *tmp = (*fast)->next_path;
    t_path *curr = *disp;

    if ((*bond)->next_path == *fast) {
            mx_add_link(&(*fast), &(*bond));
            mx_add_link(&(*bond), &tmp);
        if (*disp == *bond) {
            *disp = *fast;
        }
        else {
            while (curr && curr->next_path != *bond) {
                curr = curr->next_path;
            }
            mx_add_link(&curr, &(*fast));
        }
    }
    else {
        mx_swp(&(*disp), &(*bond), &(*fast));
    }
}

void mx_path_sort(t_path **disp, int size_p) {
    t_path *bond = *disp;
    t_path *fast = (*disp)->next_path;

    for (int i = 0; i < size_p; i++) {
        bond = *disp;
        fast = bond->next_path;

        for (; bond->indx != i; bond = bond->next_path) {
            fast = bond->next_path;
        }

        while (fast) {
            if (mx_cmp(bond, fast) == 1) {
                mx_swap_path(&(*disp), &bond, &fast);

                for (bond = *disp; bond->indx != i; bond = bond->next_path)
                    fast = bond->next_path;
            }
            else 
                fast = fast->next_path;
        }
    }
}
