/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** piscine
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    if ((s1[i] == '\0' && s2[i] == '\0') || (s1[i] == s2[i]))
        return (0);
    else {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
}
