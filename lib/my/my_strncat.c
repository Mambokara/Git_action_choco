/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** Program made to concatenate the n characters
** of a given string with another one
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int sdest = my_strlen(dest);
    int ssrc = my_strlen(src);

    while (i != ssrc && i != nb){
        dest[sdest + i] = src[i];
        i++;
    }
    dest[sdest + i] = '\0';
    return dest;
}
