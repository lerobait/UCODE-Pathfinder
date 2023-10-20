#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int sub_len = 0;

    if (sub && str) {
        sub_len = mx_strlen(sub);

        for (int index = 0; *str; index++) {
            if (mx_strncmp(str, sub, sub_len) == 0) {
                return index;
            }
            str++;
        }
        return -1;
    }
    return -2;
}
