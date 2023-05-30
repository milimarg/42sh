/*
** EPITECH PROJECT, 2023
** max
** File description:
** antman
*/

#include "my.h"

int max_in_int_tab(int *symb_tab)
{
    int bigger = 0;
    for (int i = 0; i < 128; i++) {
        if (symb_tab[i] > bigger) {
            bigger = symb_tab[i];
        }
    }
    return (bigger);
}
