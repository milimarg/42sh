/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_putstr(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        str[a];
        a = a + 1;
    }
    return (a + 1);
}
