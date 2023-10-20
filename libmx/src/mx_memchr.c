#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    if (n != 0) {
        const char *ptr = s;

        for (size_t i = 0; i < n; i++) {
            if (ptr[i] == c)
                return (char*) & ptr[i];
        }
        return NULL;
    }
    else
        return 0;
}
