#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0 || fd < 0) {
        return -2; // Некорректные аргументы
    }

    size_t bytes = 0;
    char buf;
    size_t capacity = buf_size;

    if (*lineptr == NULL) {
        *lineptr = (char *)malloc(buf_size);
    } else {
        if ((size_t)mx_strlen(*lineptr) >= capacity) { 
            capacity = (size_t)mx_strlen(*lineptr) + buf_size;
            *lineptr = (char *)mx_realloc(*lineptr, capacity);
        }
    }

    while (read(fd, &buf, 1) == 1) {
        if (buf == delim) {
            break;
        }

        if (bytes >= capacity - 1) {
            capacity *= 2;
            *lineptr = (char *)mx_realloc(*lineptr, capacity);
        }

        (*lineptr)[bytes] = buf;
        bytes++;
    }

    if (bytes == 0 && buf == 0) {
        return -1; // Конец файла
    }

    (*lineptr)[bytes] = '\0';

    return bytes;
}
