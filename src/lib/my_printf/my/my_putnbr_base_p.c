/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** pointeur
*/

#include "../include/my_printf.h"

int shownbr_base_unsigned(unsigned long nbr, int length, char const *base)
{
    int i = 0;

    if (nbr > 0) {
        i = nbr % length;
        shownbr_base_unsigned(nbr / length, length, base);
        my_putchar(base[i]);
    }
    return (0);
}

int my_putnbr_base_p(unsigned long long nbr, char const *base)
{
    int length = 0;
    nbr += 224;

    while (base[length] != '\0')
        length += 1;
    if (nbr == 0) {
        my_putchar('0');
        return (0);
    }
    return (shownbr_base_unsigned(nbr, length, base));
}
