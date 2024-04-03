/*
** EPITECH PROJECT, 2023
** corentinbergaentzle
** File description:
** get_decimal
*/

#include "../../include/printf.h"
#include <stdlib.h>

static int count_number(unsigned int nbr)
{
    int counter = 0;

    if (nbr == 0){
        return 1;
    } else {
        while (nbr != 0){
            nbr = nbr / 16;
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

static void recursion(unsigned int nb, char *hex)
{
    if (nb > 0){
        recursion(nb / 16, hex);
        my_putchar(hex[nb % 16]);
    }
}

int transfo_hex_min(unsigned int nb)
{
    char hex[16] = "0123456789abcdef";

    test_0(nb);
    recursion(nb, hex);
    return count_number(nb);
}

int transfo_hex_max(unsigned int nb)
{
    char hex[16] = "0123456789ABCDEF";

    test_0(nb);
    recursion(nb, hex);
    return count_number(nb);
}

int print_pointer_hex(unsigned int nb)
{
    my_putstr("0x");
    transfo_hex_min(nb);
    return (count_number(nb) + 2);
}
