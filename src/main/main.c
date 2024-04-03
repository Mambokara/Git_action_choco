/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/minishell.h"

int launch_terminal(int argc, char **argv, char **env)
{
    minishell_t *mysh = malloc(sizeof(minishell_t));
    char **infos;
    int val = 0;
    size_t len;

    mysh->env = get_env(env);
    if (!isatty(0)){
        return (launch_not_isatty(infos, mysh, val, len));
    } else {
        return launch_isatty(infos, len, mysh, val);
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc > 1){
        write(2, "Too much arguments\n", 19);
        return 84;
    }
    return launch_terminal(argc, argv, env);
}
