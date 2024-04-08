/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** cd_env
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"
#include <linux/limits.h>

void set_oldpwd(minishell_t *mysh)
{
    char *pos = get_pos(mysh->env);

    //my_setenv("OLDPWD", &pos[4], mysh);
}

void set_newpwd(minishell_t *mysh)
{
    //int pos_newpwd = get_position(mysh->env);
    //char *buffer = malloc(sizeof(char) * PATH_MAX);
    //char *newpwd;
//
    //getcwd(buffer, PATH_MAX);
    //my_setenv("PWD", buffer, mysh);
}
