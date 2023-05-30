/*
** EPITECH PROJECT, 2022
** flags
** File description:
** piscine
*/

#include "../include/my_printf.h"

int power_upp(double number, float point)
{
    int count = 0;
    int counter = 0;
    while (point >= 10 || point <= -10) {
        count++;
        point /= 10;
    }
    while (point <= 1 && point >= -1) {
        count--;
        point *= 10;
    }
    counter = my_put_in_expo(point, count);
    my_putstr("E");
    expo(count, point);
    return (counter + 4);
}

int my_put_float_e_upp(double number)
{
    float point = number;
    int counter = 0;
    counter = power_upp(number, point);
    return (counter);
}
