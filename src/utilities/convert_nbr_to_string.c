/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-augustin.grosnon
** File description:
** convert_nbr_to_string
*/

#include "../../include/minishell.h"

void convert_nbr_to_string(int nb, char *str, my_minishell_t *min)
{
    if (nb >= 10) {
        convert_nbr_to_string(nb / 10, str, min);
        min->dollar_index++;
        str[min->dollar_index] = (nb % 10 + '0');
    } else {
        str[min->dollar_index] = (nb + '0');
    }
}
