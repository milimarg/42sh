/*
** EPITECH PROJECT, 2022
** strncpy
** File description:
** piscine
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (n; src[i] != '\0' && n >= i; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
