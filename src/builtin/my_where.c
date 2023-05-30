/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_which
*/

#include "../../include/minishell.h"

static int find_file_in_dir(const char *searched_str, char *dir_path)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = NULL;
    char *full_string = NULL;

    if (dir == NULL)
        return (0);
    while (entry = readdir(dir)) {
        if (my_strcmp(entry->d_name, searched_str) == 0) {
            full_string = my_strcat(my_strdup(dir_path), "/");
            full_string = my_strcat(full_string, entry->d_name);
            write(1, full_string, my_strlen(full_string));
            write(1, "\n", 1);
            free(full_string);
            closedir(dir);
            return (1);
        }
    }
    closedir(dir);
    return (0);
}

static int check_builtin(char *command)
{
    for (int i = 0; BUILTIN_TAB[i]; i++)
        if (my_strcmp(command, BUILTIN_TAB[i]) == 0) {
            my_printf("%s is a shell built-in\n", command);
            return (1);
        }
    return (0);
}

static void call_function_loop(char *command, my_minishell_t *my_minishell)
{
    int is_executed = 0;

    for (alias_t *temp = my_minishell->struct_alias; temp != NULL;
    temp = temp->next)
        if (my_strcmp(temp->name, command) == 0) {
            is_executed += 1;
            my_printf("%s is aliased to %s\n", command, temp->command);
        }
    is_executed += check_builtin(command);
    for (int i = 0; my_minishell->last_path[i]; i++)
        if (find_file_in_dir(command, my_minishell->last_path[i]))
            is_executed += 1;
    if (is_executed)
        return;
    my_printf("%s: Command not found.\n", command);
    my_minishell->exit = 1;
}

int my_where(char **all_command, my_minishell_t *my_minishell)
{
    int nb_arg = 0;

    for (; all_command[nb_arg]; nb_arg++);
    if (nb_arg < 2) {
        write(2, "where: Too few arguments.\n", 26);
        my_minishell->exit = 1;
        return (1);
    }
    for (int i = 1; all_command[i]; i++)
        call_function_loop(all_command[i], my_minishell);
    return (my_minishell->exit);
}
