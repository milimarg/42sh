/*
** EPITECH PROJECT, 2022
** flag e
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_e(va_list list, char *format, int i)
{
    int count = 0;
    count = my_put_float_e(va_arg(list, double));
    return (count);
}

int flag_e_uppercase(va_list list, char *format, int i)
{
    int count = 0;
    count = my_put_float_e_upp(va_arg(list, double));
    return (count);
}
