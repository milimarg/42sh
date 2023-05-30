/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_putnbr(int nb)
{
    int count = 0;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        count++;
    }
    if (nb > 9) {
        count += my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (count + 1);
}
