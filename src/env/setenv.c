/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** setenv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

void replace_env(char *string, char **env, int pos)
{
    env[pos] = my_strdupe(string);
}

char **add_env(minishell_t *mysh, char *string)
{
    char **tmp_env = get_env(mysh->env);
    char **tmp_env2;
    int i = 0;

    while (mysh->env[i] != NULL){
        i++;
    }
    tmp_env2 = malloc(sizeof(char *) * (i + 2));
    tmp_env2 = copy_env(tmp_env, tmp_env2);
    tmp_env2[i] = my_strdupe(string);
    tmp_env2[i + 1] = NULL;
    mysh->env = tmp_env2;
    return tmp_env2;
}

char **my_setenv(char *name, char *string, minishell_t *mysh)
{
    int pos = get_env_pos(name, mysh->env);
    char *env_string = malloc(sizeof(char) *
    (my_strlen(name) + my_strlen(string) + 2));

    env_string[0] = '\0';
    if (pos != -1){
        my_strcat(env_string, name);
        my_strcat(env_string, "=");
        my_strcat(env_string, string);
        replace_env(env_string, mysh->env, pos);
        return 0;
    }
    if (pos == -1){
        my_strcat(env_string, name);
        my_strcat(env_string, "=");
        my_strcat(env_string, string);
        add_env(mysh, env_string);
        return 0;
    }
}
