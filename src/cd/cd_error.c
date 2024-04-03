/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** cd_error
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"
#include <sys/stat.h>

int check_file_dir(char **infos)
{
    DIR *dir = opendir(infos[1]);
    struct stat s;

    if (stat(infos[1], &s) == -1){
        my_printf("%s: No such file or directory.\n", infos[1]);
        return 1;
    }
    if (access(infos[1], R_OK) == -1){
        my_printf("%s: Permission denied.\n", infos[1]);
        return 1;
    }
    if (dir == NULL){
        my_printf("%s: Not a directory.\n", infos[1]);
        return 1;
    }
}
