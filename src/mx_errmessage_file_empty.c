#include "../inc/pathfinder.h"

void mx_errmessage_file_empty(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
    exit(-1);
}
