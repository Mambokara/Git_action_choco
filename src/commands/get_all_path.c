/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** get_all_path
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

char *get_path(char **env, char *path)
{
    int i = 0;

    while (env[i] != NULL){
        if (env[i][0] == '\0'){
            i++;
        }
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
        env[i][2] == 'T' && env[i][3] == 'H'){
            break;
        }
        i++;
    }
    if (env[i] == NULL){
        return path;
    }
    return env[i];
}

char *get_path_abs(char **pathes, char *binary, char *path, int nb_path)
{
    for (int i = 0; i < nb_path; i++){
        binary = malloc(sizeof(char) * (((my_strlen(pathes[i]) + 1)
        + 1 + (my_strlen(path) + 1))));
        binary[0] = '\0';
        my_strcat(binary, pathes[i]);
        my_strcat(binary, "/");
        my_strcat(binary, path);
        if (access(binary, F_OK) == 0)
            return binary;
        binary = NULL;
    }
    return path;
}

char *get_absolute(char *path, char **env)
{
    char *Path = my_strdupe(get_path(env, path));
    char *binary = NULL;
    char **pathes = NULL;
    int nb_path = count_paths(Path);

    Path = my_strdupe(&Path[5]);
    if (path[0] != '/' && (path[0] != '.' && path[1] != '/')){
        if (nb_path == 0){
            my_strcat(Path, "/");
            my_strcat(Path, path);
            return Path;
        }
        pathes = spliter(Path, ":");
        binary = get_path_abs(pathes, binary, path, nb_path);
        return binary;
    }
    return path;
}
