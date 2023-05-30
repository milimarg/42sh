/*
** EPITECH PROJECT, 2022
** float
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_putnbr_float(long int nb)
{
    int count = 0;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        count++;
    }
    if (nb > 9) {
        count += my_putnbr_float(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (count + 1);
}
