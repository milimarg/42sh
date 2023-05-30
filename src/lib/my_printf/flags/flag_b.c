/*
** EPITECH PROJECT, 2022
** flag binaire
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int my_putnbr_base_long(long nb, char const *str, int count);

int flag_b(va_list list, char *format, int i)
{
    int count = 0;
    count = my_putnbr_base_long(va_arg(list, int), "01", 0);
    return (count);
}
