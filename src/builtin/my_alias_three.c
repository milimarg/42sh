/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_alias_three
*/

#include "../../include/minishell.h"

int handling_error_alias(char *str, char **all, int len_tab)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\'' || str[i] == '"')
            count++;
    }
    if (count == 0)
        return (1);
    if (count % 2 != 0)
        return (84);
    if (all[3] == NULL && count == 2)
        return (1);
    return (0);
}

int check_alias_str(char *str, char **all)
{
    int len_tab = 0;
    int have_quote = 0;

    for (; all[len_tab]; len_tab++);
    have_quote = handling_error_alias(str, all, len_tab);
    if (have_quote == 84 || have_quote == 1)
        return (have_quote);
    return (0);
}

static int for_one( alias_t **temp, alias_t **remove, char *name)
{
    for ((*temp); (*temp) != NULL; (*temp) = (*temp)->next) {
        if ((*temp)->next != NULL
        && my_strcmp((*temp)->next->name, name) == 0) {
            (*remove) = (*temp)->next;
            (*temp)->next = (*temp)->next->next;
            free((*remove)->command);
            free((*remove)->name);
            free((*remove)->string);
            free((*remove));
            return 0;
        }
    }
    return 1;
}

int remove_double(alias_t **head, char *name)
{
    alias_t *remove = NULL;
    alias_t *temp = *head;

    if (*head == NULL)
        return 0;
    if (my_strcmp((*head)->name, name) == 0) {
        remove = *head;
        (*head) = (*head)->next;
        free(remove->command);
        free(remove->name);
        free(remove->string);
        free(remove);
        return 0;
    }
    if (for_one(&temp, &remove, name) == 0)
        return 0;
}
