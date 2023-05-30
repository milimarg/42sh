/*
** EPITECH PROJECT, 2022
** flag_u
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_u(va_list list, char *format, int i)
{
    int count = 0;
    count = my_putnbr_u(va_arg(list, int));
    return (count + 1);
}
