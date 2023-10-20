#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if ((!haystack) || (!needle)) return NULL;
    
	int len = mx_strlen(needle);
	const char *i = haystack;
    
	while ((i = mx_strchr(i, *needle)) != 0) {
		if (mx_strncmp(i, needle, len) == 0) {
			return (char*)i;
        }
        i++;
	}
	return NULL;
}
