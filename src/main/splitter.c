/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** splitter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int count_words(char *str)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0'; i++){
        if ((str[i] == ' ' && str[i + 1] != ' ') &&
            (str[i] == ' ' && str[i + 1] != '\t') && i != 0){
            count++;
        }
        if ((str[i] == '\t' && str[i + 1] != '\t') &&
            (str[i] == '\t' && str[i + 1] != ' ') && i != 0){
            count++;
        }
    }
    if (str[i] == '\0' && str[i - 1] != ' '){
        count++;
    }
    return count;
}

char **split(char *raw_cmd, char *splitter)
{
    char *ptr = NULL;
    char **cmd = NULL;
    size_t i = 0;
    int size = count_words(raw_cmd);

    cmd = malloc(sizeof(char *) * (size + 1));
    if (size == 1){
        cmd[0] = my_strdup(raw_cmd);
        cmd[1] = NULL;
        return cmd;
    }
    ptr = strtok(raw_cmd, splitter);
    while (ptr) {
        cmd[i] = my_strdup(ptr);
        ptr = strtok(NULL, splitter);
        i++;
    }
    cmd[i] = '\0';
    return (cmd);
}

int count_paths(char *str)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0'; i++){
        if ((str[i] == ':'))
            count++;
        }
    return count;
}

char **spliter(char *raw_cmd, char *splitter)
{
    char *ptr = NULL;
    char **cmd = NULL;
    size_t i = 0;
    int size = count_paths(raw_cmd);

    cmd = malloc(sizeof(char *) * (size + 1));
    if (size == 0){
        cmd[0] = my_strdupe(raw_cmd);
        cmd[1] = NULL;
        return cmd;
    }
    ptr = strtok(raw_cmd, splitter);
    while (ptr) {
        cmd[i] = my_strdupe(ptr);
        ptr = strtok(NULL, splitter);
        i++;
    }
    return (cmd);
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
}
