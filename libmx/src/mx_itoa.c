#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int tmp = number;
    char *res = NULL;
    int len = mx_numlen(number);
    res = mx_strnew(len);

    if (number == -2147483648) {
        return mx_strcpy(res, "-2147483648");
    }
    if (number == 0) {
        return mx_strcpy(res, "0");
    }
    tmp = number;

    for (int i = 0; i < len; i++) {
        if (tmp < 0) {
            res[len] = '-';
            tmp = -tmp;
        }
        res[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    mx_str_reverse(res);
    return res;
}
