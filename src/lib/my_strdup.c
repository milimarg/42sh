/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** piscine
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
