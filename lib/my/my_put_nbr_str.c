/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** my_put_nbr_str
*/

#include "../../include/my.h"
#include <stdlib.h>

char *get_if_0(int nb, char *str)
{
    str = malloc(sizeof(char) * 2);
    str[0] = '0';
    str[1] = '\0';
    return str;
}

int get_len(int tmp)
{
    int len;

    if (tmp == 0){
        return 1;
    }
    while (tmp != 0){
        tmp = tmp / 10;
        len++;
    }
    return len;
}

char *put_nbr_str(int nb)
{
    int tmp = nb;
    int len = 0;
    char *str;
    int i = 0;

    if (nb == 0)
        return get_if_0(nb, str);
    len = get_len(tmp);
    str = malloc(sizeof(char) * len + 1);
    while (nb != 0){
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}
