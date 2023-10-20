#include "../inc/pathfinder.h"

static void mx_check_count_of_islnds(int count, char *num_islnds) {
    int parsed_islnds = mx_atoi(num_islnds);

    if (count != parsed_islnds || count == 0 || count == 1) {
        mx_errmessage_invld_num_of_islnd();
    }
}

static int mx_count_set(char **arr, char *num_islnds) {
    if (!arr || !*arr) {
        return 0;
    }

    int count = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (mx_isdigit(arr[i][0])) {
            continue;
        }

        int found = 0;

        for (int j = i - 1; j >= 0; j--) {
            if (mx_strcmp(arr[i], arr[j]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            count++;
        }
    }

    mx_check_count_of_islnds(count, num_islnds);
    return count;
}

static int mx_create_flag(char *arr, char **set) {
    for (int i = 0; set[i]; i++) {
        if (mx_strcmp(arr, set[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

static void mx_create_unique_set(char ***set, char ***resarr) {
    int set_indx = 0;
    char **arr = *resarr;
    char **set_1 = *set;

    for (int i = 0; arr[i]; i++) {
        if (mx_isdigit(*(arr[i]))) {
            continue;
        }

        if (!mx_create_flag(arr[i], set_1)) {
            set_1[set_indx] = mx_strdup(arr[i]);
            set_1[set_indx + 1] = NULL;
            set_indx++;
        }
    }
}

void mx_create_islnd_collection(char ***set, char ***resarr, char *num_islnds) {
    int count = mx_count_set(*resarr, num_islnds);
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    mx_create_unique_set(&(*set), &(*resarr));
}
