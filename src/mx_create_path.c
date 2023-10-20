#include "../inc/pathfinder.h"

t_path *mx_create_path(int islnd, int dist) {
    t_path *node = (t_path *)malloc(1 * sizeof(t_path));

    node->id = islnd;
    node->dis = dist;
    node->next_connect = NULL;
    node->next_path = NULL;
    
    return node;
}
