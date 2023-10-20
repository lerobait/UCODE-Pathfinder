#include "../inc/pathfinder.h"

static void mx_pathfinding_setup_1(t_islnd **remaining, t_islnd **curr, t_islnd **visited, t_inf *inf) {
    *visited = NULL;
    *remaining = NULL;

    for (int i = 0; i < inf->size; i++) {
        mx_create_new_path(&(*remaining), NULL, i, 0);
    }

    for (*curr = *remaining; (*curr)->islnd_indx != inf->root; *curr = (*curr)->next) {}

    (*curr)->path = mx_create_path(inf->root, 0);
    mx_create_new_path(&(*visited), &(*curr)->path, (*curr)->islnd_indx, (*curr)->islnd_dis);
    mx_pop_isnd_mid(&(*remaining), inf->root);
    *curr = *visited;
}

static void mx_pathfinding_setup_2(t_islnd **unprocessed_islnd, t_islnd **curr_islnd, int **mat, t_islnds **mtrx_inf) {
    t_islnd *unprc = *unprocessed_islnd;
    int sum = 0;

    while (unprc != NULL) {
        (*mtrx_inf)->islnd_1 = (*curr_islnd)->islnd_indx;
        (*mtrx_inf)->islnd_2 = unprc->islnd_indx;
        (*mtrx_inf)->mat = mat[(*mtrx_inf)->islnd_1][(*mtrx_inf)->islnd_2];

        if ((*mtrx_inf)->mat != 0 && unprc->islnd_dis == 0) {
            unprc->islnd_dis = (*curr_islnd)->islnd_dis + (*mtrx_inf)->mat;
            sum += unprc->islnd_dis;

            if (sum < 0) { 
                mx_errmessage_invld_len();
            } 

            unprc->path = mx_add_path(&(*curr_islnd)->path, (*mtrx_inf)->islnd_2, (*mtrx_inf)->mat);
        } 
        else if ((*mtrx_inf)->mat != 0) {
            if ((*curr_islnd)->islnd_dis + (*mtrx_inf)->mat == unprc->islnd_dis)
            mx_push_path_back(&unprc->path, &(*curr_islnd)->path, (*mtrx_inf)->islnd_2, (*mtrx_inf)->mat);

            if ((*curr_islnd)->islnd_dis + (*mtrx_inf)->mat < unprc->islnd_dis) {
                unprc->islnd_dis = (*curr_islnd)->islnd_dis + (*mtrx_inf)->mat;
                mx_del_path(&unprc->path);
                unprc->path = mx_add_path(&(*curr_islnd)->path, (*mtrx_inf)->islnd_2, (*mtrx_inf)->mat);
            }
        }
        unprc = unprc->next;
    }
}

static void mx_pathfinding_setup_3(t_path_list **path_list, int **mtrx, char **set) {
    t_islnd *fourth_islnd = mx_find_shortest_islnd(&(*path_list)->first);
    mx_create_new_path(&(*path_list)->second, &fourth_islnd->path, fourth_islnd->islnd_indx, fourth_islnd->islnd_dis);
    mx_pop_isnd_mid(&(*path_list)->first, fourth_islnd->islnd_indx);

    (*path_list)->third = (*path_list)->third->next;

    if ((*path_list)->third->path == NULL) {
        mx_del_mtrx(&mtrx, set);
        mx_errmessage_invld_num_of_islnd();
    }
}

static void mx_algorithm(int **mtrx, char **set, t_inf *inf) {
    t_path_list *path_list = malloc(sizeof(t_path_list));
    path_list->first = NULL;
    path_list->second = NULL;
    path_list->third = NULL;
    path_list->fourth = NULL;

    t_islnds *curr_islnd = NULL;

    mx_pathfinding_setup_1(&path_list->first, &path_list->third, &path_list->second, inf);

    for (; path_list->first; mx_pathfinding_setup_3(&path_list, mtrx, set)) {
        curr_islnd = malloc(sizeof(t_islnd));
        mx_pathfinding_setup_2(&path_list->first, &path_list->third, mtrx, &curr_islnd);
        free(curr_islnd);
        curr_islnd = NULL;
    }

    mx_print_output(&path_list->second, inf->root + 1, inf->size, set);

    for (; path_list->second; mx_pop_islnd_front(&path_list->second)) {
        mx_del_path(&path_list->second->path);
    }

    free(path_list);
    path_list = NULL;
}

void mx_find_path(int **mtrx, char **set) {
    int size = 0;

    for (size = 0; set[size] != NULL; size++) {}

    t_inf *inf = malloc(sizeof(t_inf));
    inf->size = size;

    for (int i = 0; i < size - 1; i++) {
        inf->root = i;
        mx_algorithm(mtrx, set, inf);
    }

    free(inf);
    inf = NULL;
}
