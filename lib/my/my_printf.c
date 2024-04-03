/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** Simplified printf
*/

#include <stdarg.h>
#include "../../include/printf.h"

int ptr(int (**to_print)())
{
    to_print[0] = my_putstr;
    to_print[1] = my_putchar;
    to_print[2] = my_put_nbr;
    to_print[3] = my_put_nbr;
    to_print[4] = get_bin;
    to_print[5] = my_put_nbr_uns;
    to_print[6] = my_decimal_to_octal;
    to_print[7] = transfo_hex_min;
    to_print[8] = transfo_hex_max;
    to_print[9] = my_nb_float;
    to_print[10] = my_nb_float;
    to_print[11] = print_float_min;
    to_print[12] = print_float_max;
    to_print[13] = print_pointer_hex;
    to_print[14] = my_showstr;
    return 0;
}

int check_flag(const char *format, int (**to_print)(), int i, va_list list)
{
    int a = 0;
    int j = 0;
    char flags[15] = "scdibuoxXfFeEpS";

    while (flags[j] != '\0'){
        if (format[i] == flags[j]){
            a = (to_print[j])(va_arg(list, int *));
        }
        j++;
    }
    if (format[i] == '%'){
        my_putchar('%');
        i++;
        a++;
    }
    return a;
}

int check_diese(const char *format, int (**to_print)(), int i, va_list list)
{
    int cpt = 0;

    if (format[i] == '#'){
        i ++;
        cpt++;
        if (format[i] == 'o'){
            my_putchar('0');
            cpt--;
        }
        if (format[i] == 'b')
            my_putstr("0b");
        if (format[i] == 'x')
            my_putstr("0x");
        if (format[i] == 'X')
            my_putstr("0X");
    }
    cpt += check_flag(format, to_print, i, list);
    return cpt;
}

int check_print(const char *format, int i)
{
    if (format[i - 1] == '#'){
        return 0;
    } else {
        my_putchar(format[i]);
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int cpt = 0;
    int i = 0;
    int (*print[15])();

    va_start(list, format);
    ptr(print);
    while (format[i] != '\0'){
        if (format[i] == '%'){
            cpt += check_diese(format, print, i + 1, list);
            i++;
        } else {
            check_print(format, i);
            cpt++;
        }
        i++;
    }
    va_end(list);
    return cpt;
}
