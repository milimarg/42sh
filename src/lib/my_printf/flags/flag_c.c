/*
** EPITECH PROJECT, 2022
** flag_char
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_c(va_list list, char *format, int i)
{
    int count = 2;
    my_putchar(va_arg(list, int));
    return (count);
}
