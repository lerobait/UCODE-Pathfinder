#include "../inc/pathfinder.h"

static void mx_print_brige(t_islnd_names **prd) {
    t_islnd_names *islnd = *prd;
    char *seprt = mx_strdup("========================================");

    mx_printstr(seprt);
    mx_printchar('\n');
    mx_printstr(islnd->name_1);
    mx_printstr(islnd->name_2);
    mx_printstr(islnd->name_3);
    mx_printstr(seprt);
    mx_printchar('\n');

    mx_strdel(&islnd->name_1);
    mx_strdel(&islnd->name_1);
    mx_strdel(&islnd->name_1);
    mx_strdel(&seprt);
    free(islnd);
    *prd = NULL;
}

static t_islnd_names *mx_create_path_info(t_path *bond, char **set) {
    t_islnd_names *prd = malloc(sizeof(t_islnd_names));

    if (!prd) {
        return NULL;
    }

    prd->name_1 = mx_strdup("Path: ");
    mx_join(&prd->name_1, set[bond->id]);

    prd->name_2 = mx_strdup("Route: ");
    mx_join(&prd->name_2, set[bond->id]);

    prd->name_3 = mx_strdup("Distance: ");

    int path_len = 0;

    for (; bond; bond = bond->next_connect) {
        path_len++;
    }

    prd->num = path_len;
    return prd;
}

static void mx_add_new_bond(t_islnd_names **prd, t_path *bond, char *dis_to, char **set) {
    char *dist = mx_itoa(bond->dis);

    mx_join(&(*prd)->name_2, " -> ");
    mx_join(&(*prd)->name_2, set[bond->id]);

    if (mx_strlen((*prd)->name_3) != 10) {
        mx_join(&(*prd)->name_3, " + ");
    }

    mx_join(&(*prd)->name_3, dist);
    mx_strdel(&dist);

    if (bond->next_connect == NULL) {
        mx_join(&(*prd)->name_1, " -> ");
        mx_join(&(*prd)->name_1, set[bond->id]);

        if ((*prd)->num != 2) {
            mx_join(&(*prd)->name_3, " = ");
            mx_join(&(*prd)->name_3, dis_to);
        }

        mx_join(&(*prd)->name_2, "\n");
        mx_join(&(*prd)->name_1, "\n");
        mx_join(&(*prd)->name_3, "\n");
    } 
}

static void mx_disp_path(t_path **disp, int dis_to, char **set) {
    t_path *curr_path = *disp;
    t_islnd_names *prd = NULL;
    char *dist = mx_itoa(dis_to);

    while (curr_path) {
        prd = mx_create_path_info(curr_path, set);
        curr_path = curr_path->next_connect;

        while (curr_path->next_connect) {
            mx_add_new_bond(&prd, curr_path, dist, set);
            curr_path = curr_path->next_connect;
        }

        mx_add_new_bond(&prd, curr_path, dist, set);
        mx_print_brige(&prd);
        curr_path = curr_path->next_path;
    }

    mx_strdel(&dist);
}

void mx_print_output(t_islnd **visited, int root, int size, char **set) {
    t_islnd *curr = NULL;
    int size_p;

    for (; root < size; root++) {
        curr = *visited;

        while (curr->islnd_indx != root) {
            curr = curr->next;
        }
        
        t_path *indxed = curr->path;
        t_path *bonds = NULL;
        int i = 0;

        for (; indxed; indxed = indxed->next_path) {
            bonds = indxed;

            while (bonds) {
                bonds->indx = i;
                bonds = bonds->next_connect;
            }
            
            i++;
        }

        size_p = i;

        mx_path_sort(&curr->path, size_p);
        mx_disp_path(&curr->path, curr->islnd_dis, set);
    }
}
