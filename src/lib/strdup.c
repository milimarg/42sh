/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 2));
    int i = 0;

    for (; src[i] != '\0'; i ++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
