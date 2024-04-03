/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** cd_get_pos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"
#include <linux/limits.h>

int get_oldpos(char **env)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D'
        && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D'){
            return i;
        }
        i++;
    }
    return 84;
}

char *get_pos(char **env)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D'){
            return env[i];
        }
        i++;
    }
}

int get_position(char **env)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D'){
            return i;
        }
        i++;
    }
}

char *get_home(char **env)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == 'H' && env[i][1] == 'O'
        && env[i][2] == 'M' && env[i][3] == 'E'){
            return &env[i][5];
        }
        i++;
    }
}
