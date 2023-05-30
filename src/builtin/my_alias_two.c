/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** link_list_alias
*/

#include "../../include/minishell.h"

static int there_is_space_in_command(char *command, int index)
{
    for (int i = index; command[i]; i++) {
        if (command[i] == ' ')
            return 1;
    }
    return 0;
}

static void complete_str_two(alias_t **element, char **all,
char **new_str, int len_command_tab)
{
    if (len_command_tab > 3)
        (*new_str) = my_strcat((*new_str), "(");
    (*element)->command = my_strdup(all[2]);
    for (int i = 2; all[i]; i++) {
        if (i > 2)
            (*element)->command = my_strcat((*element)->command, all[i]);
        (*new_str) = my_strcat((*new_str), all[i]);
        if (all[i + 1] == NULL)
            break;
        (*element)->command = my_strcat((*element)->command, " ");
        (*new_str) = my_strcat((*new_str), " ");
    }
    if (len_command_tab > 3)
        (*new_str) = my_strcat((*new_str), ")");
    (*new_str) = my_strcat((*new_str), "\0");
}

static void complete_str(alias_t **element, char **all,
int len_command_tab)
{
    char *new_str = NULL;

    new_str = strdup(all[1]);
    new_str = my_strcat(new_str, "\t");
    (*element)->name = my_strdup(all[1]);
    (*element)->next = NULL;
    if (len_command_tab == 3) {
        (*element)->command = my_strdup(all[2]);
        new_str = my_strcat(new_str, all[2]);
        (*element)->string = new_str;
        return;
    }
    complete_str_two(element, all, &new_str, len_command_tab);
    (*element)->string = new_str;
}

void add_node(alias_t **head, char *command_line, char **all_commands)
{
    alias_t *element = malloc(sizeof(alias_t));
    alias_t *temp = *head;
    int len_command_tab = 0;

    for (; all_commands[len_command_tab]; len_command_tab++);
    complete_str(&element, all_commands, len_command_tab);
    if (temp != NULL) {
        for (; temp->next != NULL; temp = temp->next);
        temp->next = element;
    } else
        *head = element;
}

void display_alias(my_minishell_t  *my_minishell, char **all_commands)
{
    alias_t *temp = my_minishell->struct_alias;

    for (; temp != NULL; temp = temp->next)
        my_printf("%s\n", temp->string);
}
