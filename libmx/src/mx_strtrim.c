#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str != NULL) {
        int str_len = 0;
        char *new_str = NULL;

        while (mx_isspace(*str)) {
            str++;
        }

        str_len = mx_strlen(str);

        while (mx_isspace(str[str_len - 1])) {
            str_len--;
        }

        new_str = mx_strndup(str, str_len);
        return (char *)new_str;
    }
    else
        return NULL;
}
