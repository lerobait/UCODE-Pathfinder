#include "../inc/pathfinder.h"

static void mx_print_invld(int nline) {
    nline++;
    mx_errmessage_invld_line(nline);
}

static void mx_check_space(char **lines, char *file) {
    char *curr_line = file;
    char **line_arr = lines;

    if (*curr_line == '\n') {
        mx_print_invld(0);
    }

    for (; *curr_line; curr_line++) {
        if (*curr_line == '\n' && *(curr_line + 1) == '\n') {
            for (int i = 0; line_arr[i]; i++) {
                int curr_line_len = mx_strlen(line_arr[i]);

                if (mx_strncmp(curr_line - curr_line_len, line_arr[i], mx_strlen(line_arr[i])) == 0) {
                    mx_print_invld(i + 1);
                }
            }
        }
    }
}

static void mx_check_delim(char **lines, int nline) {
    for (int n = 1; n <= nline; n++) {
        int i = 0;
        int cpy_i = 0;

        for (; mx_isalpha(lines[n][i]); i++) {}

        if (i == 0 || lines[n][i] != '-') {
            mx_print_invld(n);
            continue;
        }

        i++;

        for (cpy_i = i; mx_isalpha(lines[n][cpy_i]); cpy_i++) {}

        if (cpy_i - i == 0 || lines[n][cpy_i] != ',') {
            mx_print_invld(n);
            continue;
        }

        cpy_i++;

        for (; mx_isdigit(lines[n][cpy_i]); cpy_i++);

        if (cpy_i - i == 0 || lines[n][cpy_i] != '\0') {
            mx_print_invld(n);
        }
    }
}

static void mx_check_file_contents(char *file) {
    char **lines = mx_strsplit(file, '\n');
    int num_line = 0;

    for (; lines[num_line]; num_line++) {}

    if (lines[0][0] == '0') {
        mx_errmessage_invld_num_of_islnd();
    }

    for (int i = 0; lines[0][i]; i++) {
        if (!mx_isdigit(lines[0][i])) {
            mx_errmessage_first_line_invld();
        }
    }
    mx_check_delim(lines, num_line - 1);
    mx_check_space(lines, file);
    mx_del_strarr(&lines);
}

void mx_check_err(int argc, char *file, char **argv) {
    if (argc != 2) {
        mx_errmessage_invld_args();
    }
    if (!file) {
        mx_errmessage_file_dexist(argv[1]);
    }
    if (mx_strlen(file) == 0) {
        mx_errmessage_file_empty(argv[1]);
    }
    mx_check_file_contents(file);
}
