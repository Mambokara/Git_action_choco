/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** env_commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

char **get_env(char **env)
{
    int i = 0;
    int size = 0;
    char **my_env;

    while (env[size] != NULL){
        size++;
    }
    my_env = malloc(sizeof(char *) * (size + 1));
    while (env[i] != NULL){
        my_env[i] = my_strdupe(env[i]);
        i++;
    }
    my_env[i] = NULL;
    return my_env;
}

void display_env(minishell_t *mysh)
{
    int i = 0;

    while (mysh->env[i] != NULL){
        if (mysh->env[i][0] == '\0'){
            i++;
            continue;
        }
        my_putstr(mysh->env[i]);
        my_putchar('\n');
        i++;
    }
}

int get_env_pos(char *name, char **env)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == '\0'){
            i++;
            continue;
        }
        if (my_strncmp(name, env[i], my_strlen(name)) == 0){
            return i;
        }
        i++;
    }
    return -1;
}

char **copy_env(char **tmp_env, char **env)
{
    int i = 0;

    while (tmp_env[i] != NULL){
        env[i] = my_strdupe(tmp_env[i]);
        i++;
    }
    return env;
}

int get_env_size(char **my_env)
{
    int i = 0;

    while (my_env[i] != NULL){
        i++;
    }
}
