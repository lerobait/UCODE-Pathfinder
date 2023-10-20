#include "../inc/pathfinder.h"

void mx_parse(char *fd, int ***mtrx, char ***set) {
    char **src = mx_strsplit(fd, '\n');
    char **ptr = NULL;

    mx_create_arr(src, &ptr);
    mx_create_islnd_collection(&(*set), &ptr, src[0]);
    *mtrx = mx_create_matrix(*set, &ptr);
    mx_del_strarr(&src);
    mx_del_strarr(&ptr);
}
