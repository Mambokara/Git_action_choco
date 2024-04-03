/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** unsetenv
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int my_unsetenv(char *name, minishell_t *mysh)
{
    int pos = get_env_pos(name, mysh->env);

    if (pos == -1){
        return 0;
    }
    mysh->env[pos][0] = '\0';
    return 0;
}
