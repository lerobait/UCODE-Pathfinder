#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char* destination = (unsigned char*)dst;
    unsigned char* source = (unsigned char*)src;

    for (size_t i = 0; i < n; i++) {
        destination[i] = source[i];

        if (source[i] == (unsigned char)c)
            return (void*) & (destination[i + 1]);
    }
    return NULL;
}
