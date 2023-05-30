/*
** EPITECH PROJECT, 2022
** flag_decimal
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_d(va_list list, char *format, int i)
{
    int nb = va_arg(list , int);
    int count = 0;
    count = my_putnbr(nb);
    return (count + 1);
}
