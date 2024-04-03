/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** launch_terminal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int check_exec_not_atty(char **infos, minishell_t *mysh)
{
    if (check_env(infos, mysh) == 1){
        return 1;
    }
    if (my_strcmp(infos[0], "env") == 0){
        display_env(mysh);
        return 1;
    }
    if (my_strcmp2(infos[0], "exit") == 0){
        my_printf("exit\n");
        if (infos[1]){
            return getnbr(infos[1]);
        } else {
            return 0;
        }
    }
    if (my_strcmp2(infos[0], "cd") == 0){
        return change_directory(mysh, infos);
    }
    return -1;
}

void remove_tab(char **infos)
{
    int i = 0;

    while (infos[i] != NULL){
        if (my_strlen(infos[i]) == 0)
            infos[i] = NULL;
        i++;
    }
}

int launch_not_isatty(char **infos, minishell_t *mysh, int val, size_t len)
{
    char *read = NULL;
    int return_val = 0;
    int i = 0;

    while (1){
        i = 0;
        if (getline(&read, &len, stdin) == EOF || my_strlen(read) == 1)
            return return_val;
        if (read[my_strlen(read) - 1] != '\n')
            read = add_enter(read);
        infos = split(read, " \t");
        remove_tab(infos);
        val = check_exec_not_atty(infos, mysh);
        if (val != -1)
            continue;
        return_val = execute_function(infos, count_words(read), mysh);
        free_array(infos);
        read = NULL;
    }
}

int check_exec(char **infos, minishell_t *mysh)
{
    if (my_strcmp2(infos[0], "unsetenv") == 0){
        my_unsetenv(infos[1], mysh);
        return -1;
    }
    if (my_strcmp2(infos[0], "setenv") == 0){
        make_setenv(infos, mysh);
        return -1;
    }
    if (my_strcmp2(infos[0], "env") == 0){
        display_env(mysh);
        return -1;
    }
    if (my_strcmp2(infos[0], "exit") == 0)
        return exitter(infos);
    if (my_strcmp2(infos[0], "cd") == 0){
        change_directory(mysh, infos);
        return -1;
    }
    return -2;
}

int launch_isatty(char **infos, size_t len, minishell_t *mysh, int val)
{
    char *read = NULL;

    while (1){
        my_printf("$> ");
        getline(&read, &len, stdin);
        if (my_strlen(read) == 0)
            return 0;
        if (read[0] == '\n')
            continue;
        infos = split(read, " \t");
        val = check_exec(infos, mysh);
        if (val != -1 && val != -2)
            return val;
        if (val == -1)
            continue;
        execute_function(infos, count_words(read), mysh);
        free_array(infos);
        read = NULL;
    }
}
