/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** pisicine
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
    my_putchar(*a);
    my_putchar(*b);
}
