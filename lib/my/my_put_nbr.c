/*
** EPITECH PROJECT, 2023
** my_print_nbr
** File description:
** Program made to display the numbers indicated as a paramter
*/

#include "../../include/my.h"

static void test_0(int nb)
{
    if (nb == 0){
    my_putchar(48);
    }
}

static void recursion(int nb)
{
    if (nb < 0){
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb > 0){
        recursion(nb / 10);
        my_putchar(48 + nb % 10);
    }
}

static void min_possible(void)
{
    my_putchar(45);
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    test_0(nb);
    if (nb == -2147483648){
        min_possible();
    } else {
        recursion(nb);
    }
    return 0;
}
