#include "../inc/libmx.h"

void mx_printint(int n) {
    int min = -2147483648;

    if (n != min) {

        if (n < 0) {
            mx_printchar('-');
            n *= -1;
        }
        if (n > 9) {
            mx_printint(n / 10);
        }
        mx_printchar(n % 10 + '0');
    }
    else
        write(1, "-2147483648", 11);
}
