#include "../inc/libmx.h"

// static int mx_get_file_length(const char *file) {
//     int length = 0;
//     int file_descriptor = -1;
//     char buffer[1];

//     if (!file) {
//         return -1;
//     }

//     file_descriptor = open(file, O_RDONLY);

//     if (file_descriptor < 0) {
//         return -1;
//     }

//     while (read(file_descriptor, buffer, 1)) {
//         length++;
//     }

//     if (close(file_descriptor) < 0) {
//         return -1;
//     }

//     return length;
// }

// char *mx_file_to_str(const char *file) {
//     int file_descriptor = -1;
//     int file_length = 0;
//     int i = 0;
//     char buffer[1];
//     char *target_str = NULL;

//     file_length = mx_get_file_length(file);

//     if (file_length >= 0) {
//         target_str = mx_strnew(file_length);

//         if (!target_str) {
//             return NULL;
//         }

//         file_descriptor = open(file, O_RDONLY);

//         if (file_descriptor < 0) {
//             return NULL;
//         }

//         while (read(file_descriptor, buffer, 1)) {
//             target_str[i++] = buffer[0];
//         }

//         if (close(file_descriptor) < 0) {
//             return NULL;
//         }
//     }

//     return target_str;
// }

char *mx_file_to_str(const char *file){
    if(!file) return NULL;
	
	int file_1 = open(file, O_RDONLY);
	int file_2 = open(file, O_RDONLY);

    char buf;
	int file_len = 0;

	if(file_1 < 0){
		close(file_1);
		return NULL;
	}

   	for(; read(file_2, &buf, 1); file_len++) {}

	char *str = mx_strnew(file_len);
	
	read(file_1, str, file_len);
	close(file_1);
	return str;
}
