/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Program that allocate memory and store a string in it
*/
#include "printf.h"
#include <stdlib.h>
#include "../../include/my.h"

char *my_strndup(char const *src, int nb)
{
    int a = my_strlen(src);
    char *str;
    static int deb = 0;
    int i = 0;

    while (src[deb] == ' ' || src[deb] == '\t'){
        deb++;
    }
    str = malloc(sizeof(char) * nb + 1);
    while ((src[deb] != ' ' && src[deb] != '\t') && src[deb] != '\0'){
        str[i] = src[deb];
        deb++;
        i++;
    }
    str[i] = '\0';
    return str;
}
