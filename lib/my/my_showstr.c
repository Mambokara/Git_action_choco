/*
** EPITECH PROJECT, 2023
** showstr
** File description:
** my_showstr
*/

#include "../../include/printf.h"

int put_zero(char *str, int i)
{
    if (str[i] >= 0 && str[i] <= 15){
        my_putchar('0');
        return 1;
    }
    return 0;
}

int my_showstr(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 0 && str[i] <= 31){
            my_putchar('\\');
            put_zero(str, i);
            transfo_hex_min(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return 0;
}
