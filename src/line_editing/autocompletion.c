/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** autocompletion
*/

#include "../../include/minishell.h"

int autocomplete_input(line_t *struct_line, my_minishell_t *my_minishell);

static int my_strncmp_autocomp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    if (s2[i] == '\0' || (s1[i] == s2[i]))
        return (0);
    else {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
}

static void display_files_in_dir(const char *searched_str, const char *dir_path)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = NULL;
    int continue_loop = 1;

    if (dir == NULL)
        return;
    while (continue_loop) {
        entry = readdir(dir);
        if (!entry) {
            continue_loop = 0;
            break;
        }
        if (my_strncmp_autocomp(entry->d_name, searched_str,
        my_strlen(searched_str)) == 0) {
            write(1, entry->d_name, my_strlen(entry->d_name));
            write(1, "\t", 1);
        }
    }
    closedir(dir);
}

static char *make_string(line_t *struct_line)
{
    char *str = malloc(sizeof(char) * (struct_line->index + 1));

    memset(str, 0, struct_line->len + 1);
    for (int i = 0; i < struct_line->index; i++)
        str[i] = struct_line->string[i];
    return (str);
}

static void display_files_current_dir(void)
{
    DIR *dir = opendir(getcwd(NULL, 1000));
    struct dirent *entry = NULL;
    int continue_loop = 1;

    if (dir == NULL)
        return;
    while (continue_loop) {
        entry = readdir(dir);
        if (!entry) {
            continue_loop = 0;
            break;
        }
        if (entry->d_name[0] == '.')
            continue;
        write(1, entry->d_name, my_strlen(entry->d_name));
        write(1, "\t", 1);
    }
    closedir(dir);
}

int handle_tab(line_t *struct_line, my_minishell_t *my_minishell)
{
    if (struct_line->buffer != '\t')
        return (0);
    if (struct_line->len == 0) {
        write(1, "\n", 1);
        display_files_current_dir();
    } else {
        if (autocomplete_input(struct_line, my_minishell))
            return (1);
        write(1, "\n", 1);
        for (int i = 0; my_minishell->last_path[i]; i++)
            display_files_in_dir(make_string(struct_line),
            my_minishell->last_path[i]);
    }
    write(1, "\n", 1);
    print_my_prompt(my_minishell);
    write(1, struct_line->string, struct_line->len);
    for (int i = 0; i < struct_line->len - struct_line->index; i++)
        write(1, "\033[D", 3);
    return (1);
}
