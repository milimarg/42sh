/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** tab_env_from_queue
*/

#include "../../include/minishell.h"

int biggest_line_in_env(my_env_t *tmp)
{
    int actual = 0;
    int biggest = 0;
    while (tmp != NULL) {
        actual += my_strlen(tmp->name) + 1;
        for (int i = 0; tmp->path != NULL && tmp->path[i] != NULL; i++) {
            actual += my_strlen(tmp->path[i]) + 1;
        }
        if (actual > biggest)
            biggest = actual;
        tmp = tmp->next;
        actual = 0;
    }
    return (biggest);
}

int count_my_queue(my_env_t *tmp)
{
    int i = 0;
    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

char *create_my_env_line(my_env_t *actual, int biggest_line)
{
    char *tmp = malloc(sizeof(char) * biggest_line + 1);
    int a = 0;
    for (int i = 0; actual->name[i] != '\0'; i++) {
        tmp[a] = actual->name[i];
        a++;
    }
    tmp[a] = '=';
    a++;
    for (int i = 0; actual->path != NULL && actual->path[i] != NULL; i++) {
        if (i > 0) {
            tmp[a] = ':';
            a++;
        }
        for (int j = 0; actual->path[i][j] != '\0'; j++) {
            tmp[a] = actual->path[i][j];
            a++;
        }
    }
    tmp[a] = '\0';
    return (tmp);
}

char **tab_env_from_queue(my_env_t *env)
{
    my_env_t *tmp = env;
    int lines = count_my_queue(tmp);
    tmp = env;
    int biggest_line = biggest_line_in_env(tmp);
    char **new_env = malloc(sizeof(char *) * (lines + 1));
    tmp = env;
    for (int i = 0; i < lines; i++) {
        new_env[i] = create_my_env_line(tmp, biggest_line);
        tmp = tmp->next;
    }
    new_env[lines] = NULL;
    return (new_env);
}
