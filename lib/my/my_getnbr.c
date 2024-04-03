/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Program made to et the number from a string of characters
*/

#include "../../include/my.h"

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

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = verif_neg(str);
    int end_while = 0;
    int *ptr = &end_while;
    long number;

    while (str[i] != '\0' && *ptr == 0){
        number = add_num(i, ptr, number, str);
        i++;
    }
    number = number * neg;
    my_put_nbr(number);
    if (number > 2147483647 || number < -2147483647){
        return 0;
    }
    return number;
}
