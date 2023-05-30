/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** piscine
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int	i = 0;
    int	sign = 0;
    int	result = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * (-1);
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    if (sign == -1)
        result = result * (sign);
    return (result);
}
