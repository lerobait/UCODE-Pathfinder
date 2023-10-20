#include "../inc/pathfinder.h"

static void mx_count_lines(char *line, char **islnd_1, char **islnd_2, char **dis) {
    char *delim_1 = mx_strchr(line, '-');
    char *delim_2 = mx_strchr(delim_1 + 1, ',');

    if (delim_1 && delim_2) {
        *islnd_1 = mx_strndup(line, delim_1 - line);
        *islnd_2 = mx_strndup(delim_1 + 1, delim_2 - delim_1 - 1);
        *dis = mx_strdup(delim_2 + 1);
    }
    else {
        *dis = NULL;
        *islnd_1 = NULL;
        *islnd_2 = NULL;
    }
}

static void mx_fill(char ***resarr, char **lines, int line) {
    int arr_indx = 0;
    int new_line = line;
    char **arr = *resarr;

    for (; lines[line]; line++) {
        char *dis = NULL;
        char *islnd_1 = NULL;
        char *islnd_2 = NULL;

        mx_count_lines(lines[line], &islnd_1, &islnd_2, &dis);

        if (mx_strcmp(islnd_1, islnd_2) == 0 && mx_atoi(dis) != 0) {
            new_line++;
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(new_line));
            mx_printerr(" is not valid\n");
            exit(0);
        }

        arr[arr_indx++] = mx_strdup(islnd_1);
        mx_strdel(&islnd_1);

        arr[arr_indx++] = mx_strdup(islnd_2);
        mx_strdel(&islnd_2);

        arr[arr_indx++] = mx_strdup(dis);
        mx_strdel(&dis);

        for (int i = 0; i < arr_indx - 3; i += 3) {
            if (mx_strcmp(arr[arr_indx - 2], arr[i]) == 0 &&
                mx_strcmp(arr[arr_indx - 3], arr[i + 1]) == 0) {
                    mx_errmessage_bridgedup(); 
            }
            if (mx_strcmp(arr[arr_indx - 3], arr[i]) == 0 &&
                mx_strcmp(arr[arr_indx - 2], arr[i + 1]) == 0) {
                    mx_errmessage_bridgedup();
            }
        }
    }
}

void mx_create_arr(char **lines, char ***resarr) {
    int line;

    for (line = 1; lines[line]; line++) {}

    *resarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    mx_fill(&(*resarr), lines, 1);
}
