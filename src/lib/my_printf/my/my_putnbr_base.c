/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_putnbr_base(int nb, char const *str)
{
    int base = my_strlen(str);
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        count ++;
    }
    if (nb > base) {
        count += my_putnbr_base(nb / base, str);
    }
    my_putchar(str[nb % base]);
    return (count);
}
