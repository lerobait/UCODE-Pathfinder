#include "../inc/pathfinder.h"

void mx_del_mtrx(int ***matrix, char **set) {
    int i = 0;
    int **mtrx = *matrix;

    for (i = 0; set[i] != NULL; i++) {}

    for (int j = 0; j < 1; j++) {
        free(mtrx[j]);
    }

    free(mtrx);
    free(set);
    *matrix = NULL;
}
