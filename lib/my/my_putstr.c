/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Program made to display the characters of the string given in paramter
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
