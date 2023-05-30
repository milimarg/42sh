/*
** EPITECH PROJECT, 2022
** my_putnbr_u
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int my_putnbr_u(long int nb)
{
    unsigned long int nmax = 4294967295;
    int counter = 0;
    if (nb < 0) {
        nb *= - 1;
        counter += my_putnbr_u(nmax - nb + 1);
    } else {
        if (nb > 9) {
            counter += my_putnbr(nb / 10);
        }
        my_putchar(nb % 10 + 48);
        counter++;
    }
    return (counter);
}
