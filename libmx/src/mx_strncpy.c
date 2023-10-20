#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int j = 0; src[j] && j != len; j++) {
        dst[j] = src[j];
    }
    return dst;
}
