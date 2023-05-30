/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}
