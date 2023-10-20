#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int length = 0;
    
    for (; *s != 0; s++) {
        length++;
    }
    return length;
}
