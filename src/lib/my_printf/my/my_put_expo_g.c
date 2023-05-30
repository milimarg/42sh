/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** piscine
*/

#include "../include/my_printf.h"

int power_g_upp(double number, float point)
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
    counter = my_put_expo_g(point, count);
    my_putstr("E");
    expo(count, point);
    return (counter + 4);
}

int power_g(double number, float point)
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
    counter = my_put_expo_g(point, count);
    my_putstr("e");
    expo(count, point);
    return (counter + 4);
}

int my_put_float_g(double number)
{
    float point = number;
    int counter = 0;
    counter = power_g(number, point);
    return (counter);
}

int my_put_float_g_upp(double number)
{
    float point = number;
    int counter = 0;
    counter = power_g_upp(number, point);
    return (counter);
}
