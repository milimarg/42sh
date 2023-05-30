/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_set_two
*/

#include "../../include/minishell.h"

static int for_one(variable_t **temp, variable_t **remove, char *name)
{
    for ((*temp); (*temp) != NULL; (*temp) = (*temp)->next) {
        if ((*temp)->next != NULL
        && my_strcmp((*temp)->next->name, name) == 0) {
            (*remove) = (*temp)->next;
            (*temp)->next = (*temp)->next->next;
            free((*remove)->value);
            free((*remove)->name);
            free((*remove)->string);
            free((*remove));
            return 0;
        }
    }
    return 1;
}

int remove_double_set(variable_t **head, char *name)
{
    variable_t *remove = NULL;
    variable_t *temp = *head;

    if (*head == NULL)
        return 0;
    if (my_strcmp((*head)->name, name) == 0) {
        remove = *head;
        (*head) = (*head)->next;
        free(remove->value);
        free(remove->name);
        free(remove->string);
        free(remove);
        return 0;
    }
    if (for_one(&temp, &remove, name) == 0)
        return 0;
}

static int complete_str(variable_t **element, char *temp_cmd,
variable_t **head, int len_equal)
{
    char **tab = my_str_to_word_array_spe(temp_cmd, '=');

    (*element)->next = NULL;
    (*element)->name = my_strdup(tab[0]);
    (*element)->string = my_strdup(tab[0]);
    (*element)->string = my_strcat((*element)->string, "\t");
    if (tab[1] == NULL) {
        tab[1] = my_strdup("\0");
        (*element)->value = my_strdup("\0");
        (*element)->string = my_strcat((*element)->string, "\0");
    } else {
        (*element)->value = my_strdup(tab[1]);
        (*element)->string = my_strcat((*element)->string, tab[1]);
    }
    if (len_equal > 1) {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return 84;
    }
    return 0;
}

int add_var(variable_t **head, char *temp_cmd)
{
    variable_t *element = malloc(sizeof(variable_t));
    variable_t *temp = *head;
    int len_equal = 0;
    int res = 0;

    for (int i = 0; temp_cmd[i]; i++) {
        if (temp_cmd[i] == '=')
            len_equal++;
    }
    res = complete_str(&element, temp_cmd, head, len_equal);
    if (temp != NULL) {
        for (; temp->next != NULL; temp = temp->next);
        temp->next = element;
    } else
        *head = element;
    if (res == 84)
        return 84;
    return 0;
}
