#include "../inc/pathfinder.h"

void mx_errmessage_invld_line(int num_of_line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(num_of_line));
    mx_printerr(" is not valid\n");
    exit(-1);
}
