#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;

    int j = 0;
    char *tmp = NULL;
    char *mmr = NULL;

    mmr = mx_strnew(mx_strlen(str));

    for (int i = 0; str[i]; i++) {
        if (!(mx_isspace(str[i]))) {
            mmr[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            mmr[j] = ' ';
            j++;
        }
    }
    tmp = mx_strtrim(mmr);
    mx_strdel(&mmr);
    return tmp;
}
