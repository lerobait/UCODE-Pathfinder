#include "../inc/pathfinder.h"

void mx_join(char **res, char *s2) {
    char *s1 = *res;
    size_t len_1 = mx_strlen(s1);
    size_t len_2 = mx_strlen(s2);
    char *new_str = mx_strnew(len_1 + len_2);

    for (size_t i = 0; i < len_1; i++) {
        new_str[i] = s1[i];
    }

    for (size_t i = 0; i < len_2; i++) {
        new_str[len_1 + i] = s2[i];
    }

    mx_strdel(&(*res));
    *res = new_str;
}
