#include "../inc/pathfinder.h"

t_islnd *mx_find_shortest_islnd(t_islnd **remaining) {
    t_islnd *head = NULL;
    t_islnd *shortest = NULL;

    if (remaining || *remaining) {
        head = *remaining;
        shortest = *remaining;

        while (head) {
            if (head->islnd_dis != 0) {
                if (shortest->islnd_dis > head->islnd_dis || !shortest->islnd_dis) {
                    shortest = head;
                }
            }
            
            head = head->next;
        }
    }

    return shortest;
}
