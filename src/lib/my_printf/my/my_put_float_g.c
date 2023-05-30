/*
** EPITECH PROJECT, 2022
** put_float
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int my_put_expo_g(double number, int count);
int print_zero(int power, long long nb, int six);
int tempo(long temp, int six);
int my_put_float_zero(double number);

int my_put_expo_g(double number, int count)
{
    long nb = number * 100000;
    int counter = 0;
    counter += my_putnbr(nb / 100000);
    my_putchar('.');
    counter++;
    if (nb <= -1 && count > 0) {
        counter += my_putnbr(-nb % 100000);
        return (counter);
    } if (nb >= 1 && count > 0) {
        counter += my_putnbr(nb % 100000);
        return (counter);
    } else
        counter += my_putnbr(nb % 100000);
    return (counter);
}

int print_zero(int power, long long nb, int six)
{
    int counter = 0;
    while (six >= 0) {
        six--;
        if (power > nb % 10000000) {
            power /= 10;
            my_putchar('0');
            counter++;
        }
    }
    return (counter);
}

int tempo(long temp, int six)
{
    int counter = 0;
    int power = my_compute_power_rec(10, six);
    while (temp % 10 == 0) {
        temp /= 10;
        }
    temp /= power;
    counter += my_putnbr_float(temp);
    return (counter);
}

int my_put_float_zero(double number)
{
    int power = 1000000;
    long long nb = number * 10000000;
    long temp = nb % 10000000;
    int count = 0;
    int neg = 0;
    count += my_putnbr_float(nb / 10000000);
    if (nb < 0) {
        nb *= -1;
        temp *= -1;
        count--;
        neg++;
    }
    if (count < 5) {
        my_putchar('.');
        count++;
        count += print_zero(power,nb, count);
        if (count <= 5)
            count += tempo(temp, count - 1);
    }
    return (count + neg);
}
