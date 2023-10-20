#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int length = mx_strlen(s1);
    char *str1 = mx_strnew(length);
    char *str2 = mx_strcpy(str1, s1);
    return str2;
}
