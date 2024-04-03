/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Program made to concatenate two
** strings together
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int sdest = my_strlen(dest);
    int ssrc = my_strlen(src);

    while (i != ssrc){
        dest[sdest + i] = src[i];
        i++;
    }
    dest[sdest + i] = '\0';
    return dest;
}
