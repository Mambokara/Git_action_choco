/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_decimal_to_octal
*/

#include "../../include/printf.h"

static int count_number_uns(unsigned int nbr)
{
    int counter = 0;

    if (nbr == 0){
        return 1;
    } else {
        while (nbr != 0){
            nbr = nbr / 8;
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
        recursion(nb / 8);
        my_putchar(48 + nb % 8);
    }
}

int my_decimal_to_octal(unsigned int nb)
{
    test_0(nb);
    recursion(nb);
    return (count_number_uns(nb));
}
