#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int sum = mx_strlen(replace) - mx_strlen(sub);
    int len = mx_strlen(str) + mx_count_substr(str, sub) * sum;
    char *res = mx_strnew(len);

    if (mx_strlen(str) <= mx_strlen(sub) || !str || !sub || !replace) {
        return NULL;
    }
    else {
        for (int i = 0; i < len; str++, i++) {
            if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub))) {
                str += mx_strlen(sub);

                for (int j = 0; j < mx_strlen(replace); i++, j++) {
                    res[i] = replace[j];
                }
            }
            res[i] = *str;
        }
        return res;
    }
}
