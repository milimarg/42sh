/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** piscine
*/

#include "my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int m = my_strlen(str) - 1;
    char i;
    while (a < m) {
        i = str[m];
        str[m] = str[a];
        str[a] = i;
        m--;
        a++;
    }
    return (str);
}
