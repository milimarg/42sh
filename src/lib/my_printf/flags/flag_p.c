/*
** EPITECH PROJECT, 2022
** flag_p
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_p(va_list list, char *format, int i)
{
    int count = 0;
    long int pointeur = va_arg(list,long);
    my_putstr("0x");
    count = my_putnbr_base_long(pointeur, "0123456789abcdef", 0);
    return (count + 3);
}
