/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** executer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int check_segv(int status)
{
    if (WIFSIGNALED(status) == true){
        if (SIGSEGV == WTERMSIG(status) && WCOREDUMP(status)){
            my_putstr("Segmentation fault (core dumped)\n");
            return status;
        }
        if (SIGSEGV == WTERMSIG(status)){
            my_putstr("Segmentation fault\n");
            return status;
        }
        if (SIGFPE == WTERMSIG(status) && WCOREDUMP(status)){
            my_putstr("Floating exception (core dumped)\n");
            return status;
        }
        if (SIGKILL == WTERMSIG(status)){
            my_putstr("Killed\n");
            return status;
        }
    }
    return 0;
}

int check_file(char *long_path, char **infos)
{
    DIR *dir = opendir(long_path);

    if (access(long_path, F_OK) == -1){
        my_printf("%s: Command not found.\n", long_path);
        return -1;
    }
    if (access(long_path, X_OK) == -1){
        my_printf("%s: Permission denied.\n", long_path);
        return -1;
    }
    if (dir != NULL){
        my_printf("%s: Permission denied.\n", long_path);
        return -1;
    }
}

int exec(char *long_path, char **infos, minishell_t *mysh)
{
    if (check_file(long_path, infos) == -1){
        exit(EXIT_FAILURE);
    }
    if (execve(long_path, infos, mysh->env) == -1)
        my_printf("%s: Exec format error. Wrong Architecture.\n", long_path);
        exit(EXIT_FAILURE);
}

int execute_function(char **infos, int nb_words, minishell_t *mysh)
{
    pid_t pid = 0;
    int status = 0;
    int val = 0;
    char *long_path;

    long_path = get_absolute(infos[0], mysh->env);
    pid = fork();
    if (pid > 0){
        waitpid(pid, &status, 0);
        kill(pid, 15);
    } else {
        exec(long_path, infos, mysh);
    }
    val = check_segv(status);
    if (val != 0)
        return status;
    return WEXITSTATUS(status);
}
