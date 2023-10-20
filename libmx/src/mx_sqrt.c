#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x > 0) {
        for (int i = 1; i <= x / i; ++i) {
            if (i * i == x)
                return i;
        }
        return 0;
    }
    else
        return 0;
}
