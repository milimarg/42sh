/*
** EPITECH PROJECT, 2022
** my_put_float_e
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int power(double number, float point)
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
    my_putstr("e");
    expo(count, point);
    return (counter + 4);
}

int my_put_float_e(double number)
{
    float point = number;
    int counter = 0;
    counter = power(number, point);
    return (counter);
}

int my_put_in_expo(double number, int count)
{
    long nb = number * 1000000;
    int counter = 0;
    counter += my_putnbr(nb / 1000000);
    my_putchar('.');
    counter++;
    if (nb <= -1 && count > 0) {
        my_putnbr(-nb % 1000000);
        counter += my_nbrlen(-nb % 1000000);
        return (counter);
    }
    if (nb >= 1 && count > 0) {
        my_putnbr(nb % 1000000);
        counter += my_nbrlen(nb % 1000000);
        return (counter);
    } else {
        my_putnbr(nb % 1000000);
        counter += my_nbrlen(nb % 1000000);
    }
    return (counter);
}

void expo(int count, double point)
{
    if (point < 1 && point > -1) {
        my_putchar('-');
        count *= -1;
    } else
        my_putchar('+');
    if (count <= 9 && count >= -9) {
        my_putchar('0');
        my_putnbr(count);
    } else
        my_putnbr(count);
}
