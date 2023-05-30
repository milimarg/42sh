/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_whereis
*/

#include "../../include/minishell.h"

int find_man_page(const char *searched_str, char *dir_path);

char *set_string(char *dir_path, char *file_name)
{
    char *full_string = NULL;

    full_string = my_strcat(my_strdup(dir_path), "/");
    full_string = my_strcat(full_string, file_name);
    return (full_string);
}

int my_strncmp_whereis(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    if (s2[i] == '\0' && s1[i] == '.')
        return (0);
    else {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
}

static int find_file_in_dir(const char *searched_str, char *dir_path)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = NULL;
    char *full_string = NULL;

    if (dir == NULL)
        return (0);
    while (entry = readdir(dir)) {
        if (my_strcmp(entry->d_name, searched_str) == 0) {
            full_string = set_string(dir_path, entry->d_name);
            full_string = my_strcat(my_strdup(dir_path), "/");
            full_string = my_strcat(full_string, entry->d_name);
            write(1, " ", 1);
            write(1, full_string, my_strlen(full_string));
            free(full_string);
            closedir(dir);
            return (1);
        }
    }
    closedir(dir);
    return (0);
}

static void call_function_loop(char *command, my_minishell_t *my_minishell)
{
    char *man_str = "/usr/share/man/man";

    write(1, command, my_strlen(command));
    write(1, ":", 1);
    for (int i = 0; my_minishell->last_path[i]; i++)
        find_file_in_dir(command, my_minishell->last_path[i]);
    for (int i = 9; i >= 1; i--)
        find_man_page(command, my_strcat(my_strdup(man_str),
        (char [2]){i + 48, '\0'}));
    write(1, "\n", 1);
}

int my_whereis(char **all_command, my_minishell_t *my_minishell)
{
    int nb_arg = 0;

    for (; all_command[nb_arg]; nb_arg++);
    if (nb_arg < 2) {
        write(2, "whereis: not enough arguments\nTry 'whereis --help' for more"
        " information.\n", 73);
        return (1);
    }
    for (int i = 1; all_command[i]; i++)
        call_function_loop(all_command[i], my_minishell);
    return (0);
}
