/*
** EPITECH PROJECT, 2023
** corentinbergaentzle
** File description:
** get_bin
*/

#include "../../include/printf.h"
#include <stdlib.h>

static int count_number_bin(unsigned int nbr)
{
    int counter = 0;

    if (nbr == 0){
        return 1;
    } else {
        while (nbr != 0){
            nbr = nbr / 2;
            counter++;
        }
    }
    return counter;
}

static void test_0(int nb)
{
    if (nb == 0){
    my_putchar(48);
    }
}

static void recursion(unsigned int nb)
{
    if (nb > 0){
        recursion(nb / 2);
        my_putchar(48 + nb % 2);
    }
}

int get_bin(unsigned int nb)
{
    test_0(nb);
    recursion(nb);
    return (count_number_bin(nb));
}
