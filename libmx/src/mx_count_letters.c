#include "../inc/libmx.h"

int mx_count_letters(const char *s, char c) {
    int j = 0;

    while (s[j] && s[j] != c) {
        j++;
    }
    return j;
}
