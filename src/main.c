#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) {
    char **set = NULL;
    int **mtrx = NULL;
    char *file = mx_file_to_str(argv[1]);

    mx_check_err(argc, file, argv);
    mx_parse(file, &mtrx, &set);
    mx_find_path(mtrx, set);
    mx_del_mtrx(&mtrx, set);
    mx_strdel(&file);
    mx_del_strarr(&set);
    return 0;
}
