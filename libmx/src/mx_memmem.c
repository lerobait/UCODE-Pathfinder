#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len <= 0) return NULL;
    if (big_len < little_len) return NULL;

    unsigned char *b = (unsigned char *)big;
    unsigned char *l = (unsigned char *)little;
    size_t max_srch = big_len - little_len;

    for (size_t i = 0; i <= max_srch; i++) {
        if (b[i] == l[0] && mx_memcmp(b + i, l, little_len) == 0)
            return (void *)(b + 1);
    }
    return NULL;
}
