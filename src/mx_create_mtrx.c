#include "../inc/pathfinder.h"

static void mx_new_mtrx_value(char **set, char **resarr, int ***matrix, t_inf *inf) {
    int **mtrx = *matrix;
    int k = 0;
    int i = inf->size;
    int j = inf->root;

    if (mx_isdigit(resarr[j + 1][0])) {
        while (mx_strcmp(set[k], resarr[j - 1]) != 0)
            k++;
        if (!mtrx[i][k] || mtrx[i][k] > mx_atoi(resarr[j + 1]))
            mtrx[i][k] = mx_atoi(resarr[j + 1]);
    } 
    else {
        while (mx_strcmp(set[k], resarr[j + 1]) != 0)
            k++;
        if (!mtrx[i][k] || mtrx[i][k] > mx_atoi(resarr[j + 2]))
            mtrx[i][k] = mx_atoi(resarr[j + 2]);
    }
}

static void mx_mtrx(char **set, char **resarr, int ***mtrx) {
    t_inf *indx = malloc(sizeof(t_inf));

    for (indx->size = 0; set[indx->size]; indx->size++) {
        for (indx->root = 0; resarr[indx->root]; indx->root++) {
            if (mx_strcmp(set[indx->size], resarr[indx->root]) == 0) {
                mx_new_mtrx_value(set, resarr, &(*mtrx), indx);
            }
        }
    }
    free(indx);
    indx = NULL;
}

int **mx_create_matrix(char **set, char ***resarr) {
    int num_elems = 0;

    for (int i = 0; set[i] != NULL; i++) {
        num_elems++;
    }

    int **mtrx = (int **)malloc(sizeof(int *) * num_elems);

    if (mtrx == NULL) {
        return NULL;
    }

    for (int i = 0; i < num_elems; i++) {
        mtrx[i] = (int *)malloc(sizeof(int) * num_elems);

        if (mtrx[i] == NULL) {
            for (int j = 0; j < 1; j++) {
                free(mtrx[j]);
            }
            free(mtrx);
            return NULL;
        }
    }

    mx_mtrx(set, *resarr, &mtrx);
    return mtrx;
}
