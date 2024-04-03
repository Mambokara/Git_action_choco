/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** executioner
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int exitter(char **infos)
{
    my_printf("exit\n");
    if (infos[1]){
        return getnbr(infos[1]);
    } else {
        return 0;
    }
}

int my_setenv_empty(char *name, minishell_t *mysh)
{
    int pos = get_env_pos(name, mysh->env);
    char *env_string = malloc(sizeof(char) *
    (my_strlen(name) + 2));

    env_string[0] = '\0';
    if (pos != -1){
        my_strcat(env_string, name);
        my_strcat(env_string, "=");
        replace_env(env_string, mysh->env, pos);
        return 0;
    }
    if (pos == -1){
        my_strcat(env_string, name);
        my_strcat(env_string, "=");
        add_env(mysh, env_string);
        return 0;
    }
}

int make_setenv(char **infos, minishell_t *mysh)
{
    if (infos[1][0] > 'a' && infos[1][0] < 'z' ||
    infos[1][0] > 'A' && infos[1][0] < 'Z'){
        if (!infos[2]){
            my_setenv_empty(infos[1], mysh);
            return -1;
        }
        my_setenv(infos[1], infos[2], mysh);
        return -1;
    } else {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
}
