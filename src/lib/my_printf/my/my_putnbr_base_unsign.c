/*
** EPITECH PROJECT, 2022
** my_putnbr_base_unsign
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int my_putnbr_base_unsign(unsigned long long nb, char const *str,int count)
{
    long base = my_strlen(str);
    int compteur = 0;
    if (nb < 0) {
        nb *= -1;
        compteur += my_putnbr_base_unsign(4294967295 - nb + 1, str, count);
    } else {
        if (nb >= base) {
            count++;
            compteur += my_putnbr_base_unsign(nb / base, str, count);
        }
        if ((nb % base) == 0 && count == 1) {
            my_putchar(1);
            my_putchar(str[nb % base]);
            compteur += 2;
        } else {
            my_putchar(str[nb % base]);
            compteur++;
        }
    }
    return (compteur);
}
