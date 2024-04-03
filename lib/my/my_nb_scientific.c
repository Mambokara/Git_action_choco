/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_nb_scientific
*/
#include "../../include/printf.h"

int verif_puissance_min(int puissance)
{
    my_putchar('e');
    if (puissance == 0) {
        my_putchar('+');
    }
    if (puissance > 0) {
        my_putchar('+');
    }
    if (puissance < 0) {
        my_putchar('-');
        puissance = - puissance;
    }
    if (puissance < 10) {
        my_putchar('0');
    }
    if (puissance > 10) {
        my_putchar('a');
    }
    my_put_nbr(puissance);
    return 0;
}

int verif_puissance_max(int puissance)
{
    my_putchar('E');
    if (puissance == 0) {
        my_putchar('+');
    }
    if (puissance > 0) {
        my_putchar('+');
    }
    if (puissance < 0) {
        my_putchar('-');
        puissance = - puissance;
    }
    if (puissance < 10) {
        my_putchar('0');
    }
    if (puissance > 10) {
        my_putchar('a');
    }
    my_put_nbr(puissance);
    return 0;
}

int print_float_min(double ui)
{
    double cpt = 10.0;
    int puissance = 0;

    if (ui < 0) {
        ui = ui * - 1;
        my_putchar('-');
    }
    while (ui < 1) {
        ui = ui * cpt;
        puissance --;
    }
    while (ui > 9) {
        ui = ui / 10;
        puissance ++;
    }
    my_nb_float(ui);
    verif_puissance_min(puissance);
    return 0;
}

int print_float_max(double ui)
{
    double cpt = 10.0;
    int puissance = 0;

    if (ui < 0) {
        ui = ui * - 1;
        my_putchar('-');
    }
    while (ui < 1) {
        ui = ui * cpt;
        puissance --;
    }
    while (ui > 9) {
        ui = ui / 10;
        puissance ++;
    }
    my_nb_float(ui);
    verif_puissance_max(puissance);
    return 0;
}
