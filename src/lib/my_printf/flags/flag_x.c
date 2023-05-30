/*
** EPITECH PROJECT, 2022
** flag_x
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_x(va_list list, char *format, int i)
{
    int count = 0;
    int hexa = va_arg(list,int);
    count = my_putnbr_base_long(hexa, "0123456789abcdef", 0);
    return (count + 1);
}
