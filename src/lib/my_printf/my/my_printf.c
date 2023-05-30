/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** piscine
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int flags_operators(char *flag, va_list list, int i, int counter)
{
    int count = 0;
    int (*tab[])(va_list, char *,int) = {
        flag_b, flag_c, flag_d,flag_e,
        flag_e_uppercase, flag_f, flag_f_uppercase,
        flag_g, flag_g_uppercase, flag_i, flag_o, flag_p,
        flag_s, flag_s_uppercase,
        flag_x, flag_hexa_uppercase,
        flag_u, flag_percent,
    };
    char *flags = "bcdeEfFgGiopsSxXu%";
    for (int j = 0; flags[j] != '\0'; j++) {
        if (flags[j] == flag[i]) {
            count = tab[j](list, flag, i);
            return (count);
        }
        if (flag[i] == 'n') {
            flag_n(list, counter);
            return (count);
        }
    }
}

int not_flags(char *format, int i)
{
    int temp = i;
    int j;
    char *flags = "bcdeEfFgGiopsSxXu%n";
    for (;format[i] != '\0'; i++) {
        for (j = 0; flags[j] != format[i] && flags[j] != '\0'; j++) {
        }
        if (flags[j] == format[i])
            return (i - 1);
    }
    return (temp - 2);
}

int loop_printf(char *format, va_list list, int i, int count)
{
    if (format[i] == '%' && format[i + 1] == '\0')
        return (-1);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i = not_flags(format, i + 1);
            count += flags_operators(format, list, i + 1, count);
            i += 2;
            count--;
        } else {
            my_putchar(format[i]);
            i++;
            count++;
        }
    }
    return (count);
}

int my_printf(char *format, ...)
{
    va_list list;
    int i = 0;
    int count = 0;
    va_start(list, format);
    count = loop_printf(format, list, i , count);
    va_end(list);
    return (count);
}
