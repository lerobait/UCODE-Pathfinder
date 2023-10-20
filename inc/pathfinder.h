#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_inf {
    int size;
    int root;
}              t_inf;

typedef struct s_path {
    int indx;
    int id;
    int dis;
    struct s_path *next_path;
    struct s_path *next_connect;
}               t_path;

typedef struct s_islnd {
    int islnd_dis;
    int islnd_indx;
    struct s_path *path;
    struct s_islnd *next;
}               t_islnd;

typedef struct s_islnds {
    int mat;
    int islnd_1;
    int islnd_2;
}               t_islnds;

typedef struct s_islnd_names {
    char *name_1;
    char *name_2;
    char *name_3;
    int num;
}               t_islnd_names;

typedef struct s_path_list {
    t_islnd *first;
    t_islnd *second;
    t_islnd *third;
    t_islnd *fourth;
}               t_path_list;

void mx_printerr(const char *s);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
bool mx_isalpha(int c);
int mx_unique_path(t_path **new, t_path **current);

// Errors
void mx_check_err(int argc, char *file, char **argv);
void mx_errmessage_invld_args();
void mx_errmessage_file_dexist(char *filename);
void mx_errmessage_file_empty(char *filename);
void mx_errmessage_invld_num_of_islnd();
void mx_errmessage_first_line_invld();
void mx_errmessage_invld_line(int num_of_line);
void mx_errmessage_bridgedup();
void mx_errmessage_invld_len();

// Pathfinder parse
void mx_parse(char *fd, int ***mtrx, char ***set);
void mx_create_arr(char **lines, char ***resarr);
void mx_create_islnd_collection(char ***set, char ***resarr, char *num_islnds);
int **mx_create_matrix(char **set, char ***resarr);

// Add
void mx_add_link(t_path **current_path, t_path **new_path);
t_path *mx_add_single_path(t_path **prev, int islnd, int dis);
t_path *mx_add_path(t_path **prev, int islnd, int dis);

// Path Master
void mx_push_path_back(t_path **path, t_path **prev, int islnd, int dis);
t_path *mx_create_path(int islnd, int dist);
t_path *mx_cpy_path(t_path **data);

// Delete
void mx_del_mtrx(int ***matrix, char **set);
void mx_del_path(t_path **head);

// Island
void mx_join(char **res, char *s2);
t_islnd *mx_find_shortest_islnd(t_islnd **remaining);
void mx_create_new_path(t_islnd **islnd, t_path **path, int indx, int dis);
void mx_pop_islnd_front(t_islnd **head);
void mx_pop_isnd_mid(t_islnd **remaining, int indx);

// Sort
void mx_path_sort(t_path **disp, int size_p);

// Output
void mx_print_output(t_islnd **visited, int root, int size, char **set);

// Pathfinder
void mx_find_path(int **mtrx, char **set);

#endif
