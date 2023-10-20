#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 != NULL && s2 != NULL) {
        if (s1 == NULL) {
            return mx_strdup(s2);
        }
        else if (s2 == NULL) {
            return mx_strdup(s1);
        }
        else {
            int new_s1 = mx_strlen(s1);
            int new_s2 = mx_strlen(s2);
            char *new_str = mx_strnew(new_s1 + new_s2);
            new_str = mx_strcpy(new_str, s1);
            new_str = mx_strcat(new_str, s2);
            return new_str;
        }
    }
    else
        return NULL;
}
