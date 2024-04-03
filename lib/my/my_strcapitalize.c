/*
** EPITECH PROJECT, 2023
** ui
** File description:
** ui
*/

#include "../../include/my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase(str);
    while (str[i] != '\0'){
        if (i == 0 && str[i] > 96 && str[i] < 123){
            str[i] -= 32;
        }
        if (str[i] == 32 && str[i + 1] > 96 && str[i + 1] < 123){
            str[i + 1] -= 32;
        }
        if (str[i] == '+' && str[i + 1] > 96 && str[i + 1] < 123){
            str[i + 1] -= 32;
        }
        if (str[i] == '-' && str[i + 1] > 96 && str[i + 1] < 123){
            str[i + 1] -= 32;
        }
        i++;
    }
    return str;
}
