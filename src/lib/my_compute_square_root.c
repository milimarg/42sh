/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** piscine
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 0 || nb < 0)
        return (0);
    for (int a = 1; a <= nb; a++) {
        if (a * a == nb)
            return (a);
    }
    return (0);
}
