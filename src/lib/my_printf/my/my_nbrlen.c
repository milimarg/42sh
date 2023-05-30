/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int my_nbrlen(int number)
{
    int tmp = number;

    for (int i = 1; tmp > 0; i++) {
        if (tmp / my_compute_power_rec(10,i) <= 0)
            return (i + 1);
        }
}
