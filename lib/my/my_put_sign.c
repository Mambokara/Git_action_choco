/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_put_sign
*/
#include "../../include/printf.h"
#include <stdio.h>

int my_put_sign(int nb)
{
    if (nb * -1 < 0) {
        my_putchar('+');
    }
    if (nb * -1 > 0) {
        my_putchar('-');
    }
    return 0;
}
