/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** piscine
*/

#include "../include/my_printf.h"

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    if (p < 0) {
        return (0);
    } if (p == 0) {
        return (1);
    } if (p != 0 ) {
        result = my_compute_power_rec(nb, p - 1) * nb;
    }
    return (result);
}
