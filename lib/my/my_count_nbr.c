/*
** EPITECH PROJECT, 2023
** my_print_nbr
** File description:
** Program made to display the numbers indicated as a paramter
*/

#include "../../include/printf.h"

static int count_number(int nbr)
{
    int counter = 0;

    if (nbr == -2147483648)
        return 11;
    if (nbr == 0){
        return 1;
    } else if (nbr < 0) {
        nbr = -nbr;
        counter ++;
    }
    while (nbr != 0){
        nbr = nbr / 10;
        counter++;
    }
    return counter;
}

int my_count_nbr(int nb)
{
    int a = count_number(nb);

    return a;
}
