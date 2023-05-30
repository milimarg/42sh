/*
** EPITECH PROJECT, 2022
** flag_nbr(i)
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_i(va_list list, char *format, int i)
{
    int nb = va_arg(list , int);
    int count = 0;
    count = my_putnbr(nb);
    return (count + 1);
}
