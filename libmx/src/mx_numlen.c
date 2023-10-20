#include "../inc/libmx.h"

int mx_numlen(int number) {
    int length = 0;

    while (number) {
        number /= 10;
        length++;
    }
    return length;
}
