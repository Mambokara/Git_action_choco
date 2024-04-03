/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

char *my_strdupe(char *src)
{
    int a = my_strlen(src);
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (a + 1));
    while (src[i] != '\0'){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

static int verif_neg(char const *str)
{
    int neg = 1;
    int i = 0;

    while (str[i] < 46){
        if (str[i] == '-'){
            neg = neg * -1;
        }
        i++;
    }
    return neg;
}

static int add_num(int i, int *ptr, int number, char const *str)
{
    if (str[i] > 47 && str[i] < 58){
        number = number * 10;
        number = number + (str[i] - 48);
        if (str[i + 1] < 48 || str[i + 1] > 57){
            *ptr += 1;
        }
    }
    return number;
}

int getnbr(char const *str)
{
    int i = 0;
    int neg = verif_neg(str);
    int end_while = 0;
    int number = 0;

    while (str[i] != '\0'){
        if (str[i] < '0' && str[i] > '9'){
            i++;
            continue;
        }
        number = number * 10 + (str[i] - 48);
        i++;
    }
    if (number > 2147483647 || number < -2147483647){
        return 0;
    }
    return number;
}

char *add_enter(char *read)
{
    char *tmp;

    tmp = my_strdupe(read);
    read = malloc(sizeof(char) * my_strlen(tmp) + 2);
    read[0] = '\0';
    my_strcat(read, tmp);
    my_strcat(read, "\n");
    return read;
}
