/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int  my_put_float(double number)
{
    int power = 100000;
    long long nb = number * 1000000;
    int count = 0;
    count = my_putnbr_float(nb / 1000000);
    my_putchar('.');
    count++;
    if (nb < 0) {
        nb *= -1;
        for (; power >= nb % 1000000; power /= 10, count++) {
            my_putchar('0');
        }
        count += my_putnbr_float(nb % 1000000);
    } else {
        for (; power >= nb % 1000000; power /= 10, count++) {
            my_putchar('0');
        }
        count += my_putnbr_float(nb % 1000000);
    }
    return (count);
}
