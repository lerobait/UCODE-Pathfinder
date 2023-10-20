#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *ptr = (unsigned char *)s + n - 1;
    unsigned char chr = (unsigned char)c;

    for (; ptr >= (unsigned char *)s; ptr--) {
        if (*ptr == chr)
            return (void *)ptr;
    }
    return NULL;
}
