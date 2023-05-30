/*
** EPITECH PROJECT, 2022
** flag_%
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_percent(va_list list, char *format, int i)
{
    int count = 2;
    my_putchar('%');
    return (count);
}
