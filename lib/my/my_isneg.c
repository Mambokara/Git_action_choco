/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Program to indicate if the number in negative or not
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return 0;
}
