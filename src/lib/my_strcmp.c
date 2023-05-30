/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** piscine
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
}
