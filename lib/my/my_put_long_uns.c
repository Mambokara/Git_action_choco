/*
** EPITECH PROJECT, 2023
** my_print_nbr
** File description:
** Program made to display the numbers indicated as a paramter
*/

#include "../../include/printf.h"

static int count_long_number_uns(unsigned long nbr)
{
    int counter = 0;

    if (nbr == 0){
        return 1;
    } else {
        while (nbr != 0){
            nbr = nbr / 10;
            counter++;
        }
    }
    return counter;
}

static void test_0(long nb)
{
    if (nb == 0){
    my_putchar(48);
    }
}

static void recursion(unsigned long nb)
{
    if (nb > 0){
        recursion(nb / 10);
        my_putchar(48 + nb % 10);
    }
}

int my_put_long_uns(unsigned long nb)
{
    test_0(nb);
    recursion(nb);
    return count_long_number_uns(nb);
}
