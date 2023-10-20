#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if(hex != NULL) {
        int length = 0;
        unsigned long result = 0;
        unsigned long base = 1;

        for (; hex[length] != '\0';) {
            length++;
        }

        for (int i = length - 1; i >= 0; i--) {
            if (hex[i] <= '9' && hex[i] >= '0') {
                result += ((hex[i] - 48) * base);
                base *= 16;
            }
            else if (hex[i] >= 'A' && hex[i] <= 'z') {
                if (hex[i] >= 'A' && hex[i] <= 'Z') {
                    result += ((hex[i] - 55) * base);
                    base *= 16;
                }
                else {
                    result += ((hex[i] - 87) * base);
                    base *= 16;
                }
            }
        }
        return result;
    }
    else
        return 0;
}
