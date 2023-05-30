/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** piscine
*/

#include "my.h"

int my_is_prime(int nb)
{
    int a = 0;
    for (int diviseur = 1; diviseur <= nb; diviseur++) {
        if (nb % diviseur != 0 || nb > 0)
            a++;
        else
            return (0);
    }
    if (a < 2 )
        return (0);
    else
        return (1);
}
