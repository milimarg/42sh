/*
** EPITECH PROJECT, 2022
** flags
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_g(va_list list, char *format, int i)
{
    double comp = va_arg(list, double);
    int count = 0;
    if (comp >= 1000000 || comp <= (-1000000))
        count = my_put_float_g(comp);
    else
        count = my_put_float_zero(comp);
    return (count + 1);
}

int flag_g_uppercase(va_list list, char *format, int i)
{
    double comp = va_arg(list, double);
    int count = 0;
    if (comp >= 100000 && comp <= (-100000))
        count = my_put_float_g_upp(comp);
    else
        count = my_put_float_zero(comp);
    return (count + 1);
}
