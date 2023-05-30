/*
** EPITECH PROJECT, 2022
** flag_n
** File description:
** my_printf
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

void flag_n(va_list list, int count)
{
    int *adress = va_arg(list,int *);
    *adress = count;
}
