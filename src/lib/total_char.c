/*
** EPITECH PROJECT, 2023
** total_occurency
** File description:
** antman
*/

#include "my.h"

int total_occurency(int *symb_tab)
{
    int total = 0;
    for (int i = 0; i < 127; i++) {
        total += symb_tab[i];
    }
    return (total);
}
