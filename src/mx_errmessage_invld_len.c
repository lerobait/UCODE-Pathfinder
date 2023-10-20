#include "../inc/pathfinder.h"

void mx_errmessage_invld_len() {
    mx_printerr("error: sum of bridges lengths is too big\n");
    exit(-1);
}
