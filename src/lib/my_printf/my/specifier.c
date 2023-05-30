/*
** EPITECH PROJECT, 2022
** specifier
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int return_to_pourcent(const char *format, int i)
{
    while (format[i] != '%')
        i--;
    return (i + 1);
}

int put_space(const char *format, int i)
{
    int number = 0;
    int count = 0;
    while (format[i] < '0' && format[i] != '\0' || format [i] > '9'
            && format[i] != '\0') {
        i++;
    }
    if (format[i] > '0' && format[i] <= '9') {
        number = format[i];
        i++;
        count++;
        while (format[i] >= '0' && format[i] <= '9') {
            number = number * 10 + format[i];
            count++;
            i++;
        }
    }
    number = number - (48 * count);
    number--;
    return (number);
}
