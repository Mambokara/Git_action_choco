/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** check_commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int check_env(char **infos, minishell_t *mysh)
{
    if (my_strcmp(infos[0], "unsetenv") == 0){
        my_unsetenv(infos[1], mysh);
        return 1;
    }
    if (my_strcmp(infos[0], "setenv") == 0){
        if (!infos[1]){
            display_env(mysh);
            return 1;
        }
        make_setenv(infos, mysh);
        return 1;
    }
    return 0;
}
