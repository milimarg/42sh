/*
** EPITECH PROJECT, 2022
** B-CPE-101-STG-1-1-myprintf-noe.tritsch
** File description:
** flag_f.c
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flag_f_uppercase(va_list list, char *format, int i)
{
    int count = 0;
    count = my_put_float(va_arg(list, double));
    return (count + 1);
}

int flag_f(va_list list, char *format, int i)
{
    int count = 0;
    count = my_put_float(va_arg(list, double));
    return (count + 1);
}
