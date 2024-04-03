/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** change_directory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int change_directory_home(minishell_t *mysh, char *home)
{
    set_oldpwd(mysh);
    chdir(home);
    set_newpwd(mysh);
    return 0;
}

int change_directory_minus(char **infos, minishell_t *mysh, int oldpos)
{
    char *cd_minus;
    char *oldposition;

    if (my_strcmp(infos[1], "-") == 0){
        if (oldpos == 84){
            my_printf(": No such file or directory.\n");
            return 1;
        }
        oldposition = my_strdupe(mysh->env[oldpos]);
        cd_minus = my_strdupe(&oldposition[7]);
        set_oldpwd(mysh);
        if (chdir(cd_minus) == -1){
            return 1;
        }
        set_newpwd(mysh);
        return 0;
    }
    return -1;
}

int change_directory_all(char **infos, minishell_t *mysh)
{
    if (my_strcmp(infos[1], "-") != 0 && my_strcmp(infos[1], "~") != 0){
        set_oldpwd(mysh);
        if (chdir(infos[1]) == -1){
            return 1;
        }
        set_newpwd(mysh);
        return 0;
    }
    return -1;
}

int change_directory_tild(char **infos, minishell_t *mysh)
{
    char *home = get_home(mysh->env);

    if (my_strcmp(infos[1], "~") == 0){
        set_oldpwd(mysh);
        if (chdir(home) == -1){
            my_putchar('.');
            return 1;
        }
        set_newpwd(mysh);
        return 0;
    }
    return -1;
}

int change_directory(minishell_t *mysh, char **infos)
{
    int oldpos = get_oldpos(mysh->env);
    char *home = get_home(mysh->env);
    int val = 0;

    if (!infos[1]){
        return (change_directory_home(mysh, home));
    }
    val = change_directory_minus(infos, mysh, oldpos);
    if (val != -1)
        return val;
    val = change_directory_tild(infos, mysh);
    if (val != -1)
        return val;
    if (check_file_dir(infos) != 0)
        return 1;
    val = change_directory_all(infos, mysh);
    if (val != -1)
        return val;
}
