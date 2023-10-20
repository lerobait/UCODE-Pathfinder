#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    bool state = true;
    unsigned w_counter = 0;

    if (str != NULL) {
        for (int del = 0; str[del]; ++del) {
            if (str[del] == c) {
                state = true;
            }
            else if (state == true) {
                state = false;
                ++w_counter;
            }
        }
        return w_counter;
    }
    else
        return -1;
}
