/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** autocomplete_input
*/

#include "../../include/minishell.h"

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

static char *find_files_in_dir(const char *searched_str, const char *dir_path)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = NULL;
    char *string = NULL;

    if (dir == NULL)
        return (NULL);
    while (1) {
        entry = readdir(dir);
        if (!entry)
            break;
        if (my_strncmp_autocomp(entry->d_name, searched_str,
        my_strlen(searched_str)) == 0)
            string = (string == NULL) ? strdup(entry->d_name) : (void *)-1;
        if (string == (void *)-1)
            break;
    }
    closedir(dir);
    return (string);
}

static char *make_string(line_t *struct_line)
{
    char *str = malloc(sizeof(char) * (struct_line->index + 1));

    memset(str, 0, struct_line->index + 1);
    for (int i = 0; i < struct_line->index; i++)
        str[i] = struct_line->string[i];
    return (str);
}

static void reset_current_string(line_t *struct_line, char *string)
{
    strcat(struct_line->string, string);
    struct_line->len += my_strlen(string) + 1;
    struct_line->index = struct_line->len;
    strcat(struct_line->string, " ");
    write(1, string, my_strlen(string));
    write(1, " ", 1);
}

int autocomplete_input(line_t *struct_line, my_minishell_t *my_minishell)
{
    char *string = NULL;
    char *temp_string = NULL;
    int number_string = 0;
    for (int i = 0; my_minishell->last_path[i]; i++) {
        temp_string = find_files_in_dir(make_string(struct_line),
        my_minishell->last_path[i]);
        if (temp_string == (void *)-1)
            return (0);
        if (string != NULL && temp_string != NULL) {
            free(string);
            return (0);
        }
        if (string == NULL && temp_string != NULL)
            string = temp_string;
    }
    if (string == NULL)
        return (1);
    reset_current_string(struct_line, string + struct_line->len);
    free(string);
    return (1);
}
