/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** nb_float
*/
#include "../../include/printf.h"
#include <stdlib.h>

char *get_string_num(long long nb, char *str)
{
    int i = 0;

    while (nb != 0){
        str[i] = 48 + (nb % 10);
        nb = nb / 10;
        i++;
    }
    return str;
}

static int print_zero(int ui)
{
    int taille = 0;

    taille = my_count_nbr(ui);
    while (taille < 6){
        my_putchar('0');
        taille ++;
    }
    return 0;
}

int get_modul2(long long tmp, char *str, int i)
{
    int a = i;
    int ui = 0;

    if (tmp < 0){
        tmp = -tmp;
        i = i;
    }
    str = my_revstr(get_string_num(tmp, str));
    while (a < 6 + i){
        ui = ui * 10 + (str[a] - 48);
        a ++;
    }
    if (str[a] >= 48 + 5)
        ui++;
    print_zero(ui);
    my_put_nbr(ui);
    return a;
}

int get_modulo(double nb, int a)
{
    long long tmp = 0;
    char *str;
    int i = a;

    str = malloc(sizeof(char) * 1000);
    tmp = nb * 10000000;
    if ((int)nb == 0){
        tmp += 10000000;
        i++;
    }
    return get_modul2(tmp, str, i);
}

static double nb_0_neg(double nb)
{
    if ((nb < 0.00 && nb > -1.00) || (nb == -0.000000)) {
        nb = nb * -1.00;
        my_putchar('-');
        return nb;
    }
    return 0;
}

int my_nb_float(double nb)
{
    long ui = 0;
    int a = 0;

    nb = nb_0_neg(nb);
    ui = nb;
    if (ui < 0){
        ui = -ui;
        my_putchar('-');
    }
    a = my_put_long(ui);
    if (ui == 0){
        a = a - 1;
    }
    my_putchar('.');
    a = get_modulo(nb, a);
    if (ui < 0){
        a = a + 1;
    }
    return a + 1;
}
