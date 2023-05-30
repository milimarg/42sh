/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** fonction
*/

#include "../include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
