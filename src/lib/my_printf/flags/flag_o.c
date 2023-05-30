/*
** EPITECH PROJECT, 2022
** flag octal
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_o(va_list list, char *format, int i)
{
    unsigned long long number = va_arg(list, unsigned long long);
    int count = 0;
    count = my_putnbr_base_unsign(number, "01234567", 0);
    return (count + 1);
}
