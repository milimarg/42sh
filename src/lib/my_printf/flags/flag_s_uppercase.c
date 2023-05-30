/*
** EPITECH PROJECT, 2022
** B-CPE-101-STG-1-1-myprintf-noe.tritsch
** File description:
** flag_s_uppercase.c
*/

#include "../include/my_printf.h"
#include "../include/flags.h"

int is_letter(char str)
{
    if (str >= 32 && str <= 126)
        return (1);
    return (0);
}

int to_octal(char str)
{
    int nb = str;
    int count = 0;
    count = my_nbrlen(nb);
    my_putnbr(nb);
    return (count + 1);
}

int flag_s_upp(char *str)
{
    int i = 0;
    int count = 0;

    for (; str[i] != '\0'; i++) {
        if (is_letter(str[i]) == 1) {
            my_putchar(str[i]);
            count++;
        }
        if (is_letter(str[i]) == 0) {
            my_putchar(92);
            count += to_octal(str[i]);
        }
    }
    return (count);
}

int flag_s_uppercase(va_list list, char *format, int i)
{
    int count = 0;
    count = flag_s_upp(va_arg(list, char*));
    return (count + 1);
}
