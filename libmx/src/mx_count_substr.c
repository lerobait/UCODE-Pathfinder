#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -1;
    
    const char *n = sub;
    const char *p = str;
    int res;

    for(res = 0; (p = mx_strstr(p, n)) != 0; res++) {
        p += mx_strlen(n);
    }
    return res;
}
