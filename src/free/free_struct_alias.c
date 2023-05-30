/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** free_struct_alias
*/

#include "../../include/minishell.h"

void free_struct_alias(alias_t *head)
{
    alias_t *remove = NULL;

    while (head != NULL) {
        remove = head;
        head = head->next;
        free(remove->command);
        free(remove->name);
        free(remove->string);
        free(remove);
    }
}
