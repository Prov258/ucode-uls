#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int word_count = mx_count_words(s, c);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));
    int result_index = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            int word_start = i;
            int word_length = 1;

            while (s[i + 1] != c && s[i + 1] != '\0') {
                word_length++;
                i++;
            }

            char *word = mx_strnew(word_length);
            mx_strncpy(word, s + word_start, word_length);
            result[result_index] = word;
            result_index++;
        }
    }

    result[result_index] = NULL;
    return result;
}

