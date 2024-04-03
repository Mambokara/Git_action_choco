/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Program that allocate memory and store a string in it
*/
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char *src)
{
    int a = my_strlen(src);
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (a + 1) * 100);
    while (src[i] != '\n'){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
