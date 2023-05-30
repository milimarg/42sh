/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** piscine
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *result = malloc(sizeof(char) * (dest_len + src_len + 1));
    int i = 0;

    for (; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    for (int j = 0; src[j] != '\0'; j++) {
        result[i] = src[j];
        i++;
    }
    result[dest_len + src_len] = '\0';
    free(dest);
    return (result);
}
