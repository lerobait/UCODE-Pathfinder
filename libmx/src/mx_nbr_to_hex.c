#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (4294967295 > nbr) {
        int size = 0;
        int temp = nbr;
        
        while (temp != 0) {
            size++;
            temp /= 16;
        }

        char *hex = (char *)malloc(size);
        unsigned int f = nbr;
        int j = 0;
        int g;
        
        while (f != 0) {
            g = f % 16;

            if (g < 10) { 
                hex[j] = 48 + g;
            }
            else {
                hex[j] = 87 + g;
            }
            j++;
            f /= 16;
        }
        j--;
        
        for (int i = 0; i < j; i++) {
            char temp = hex[i];
            hex[i] = hex[j];
            hex[j] = temp;
            j--;
        }
        return hex;
    }
    else 
        return 0;
}
