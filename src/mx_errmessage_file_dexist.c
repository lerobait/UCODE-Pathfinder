#include "../inc/pathfinder.h"

void mx_errmessage_file_dexist(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    exit(-1);
}
