#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int size_1 = mx_strlen(s1);
    int size_2 = mx_strlen(s2);
    int j = size_1;

    for (int i = 0; j < (size_1 + size_2); i++) {
        s1[j] = s2[i];
        j++;
    }
    s1[j++] = '\0';
    return s1;
}
