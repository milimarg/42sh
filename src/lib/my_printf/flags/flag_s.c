/*
** EPITECH PROJECT, 2022
** flag c
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_s(va_list list, char *format, int i)
{
    int count = 0;
    count = my_putstr(va_arg(list, char *));
    return (count);
}
