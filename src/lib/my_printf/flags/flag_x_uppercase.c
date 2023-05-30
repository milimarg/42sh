/*
** EPITECH PROJECT, 2022
** B-CPE-101-STG-1-1-myprintf-noe.tritsch
** File description:
** flag_X.c
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_hexa_uppercase(va_list list, char *format, int i)
{
    int count = 0;
    int hexa = va_arg(list, int);
    count = my_putnbr_base_long(hexa, "0123456789ABCDEF", 0);
    return (count + 1);
}
