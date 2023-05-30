/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** piscine
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}
