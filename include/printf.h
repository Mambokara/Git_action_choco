/*
** EPITECH PROJECT, 2023
** corentinbergaentzle
** File description:
** printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>

int put_zero(char *, int);
int my_showstr(char *);
int my_strlen(char const *);
int get_bin(unsigned int);
int my_putchar(int);
int print_float_min(double nb);
int print_float_max(double nb);
char *my_revstr(char *);
int my_put_nbr(int);
int my_put_nbr_uns(unsigned int);
int my_put_long_uns(unsigned long);
int my_putstr(char const *);
int transfo_hex_min(unsigned int);
int transfo_hex_max(unsigned int);
int get_decimal(char, unsigned int);
int my_decimal_to_octal(unsigned int);
int my_put_nbr_uns(unsigned int nb);
int my_nb_float(double nb);
int my_nb_scientific(double nb);
int my_put_long(long nb);
int check_string(const char *format, int i, va_list list);
int check_conv(const char *format, int i, va_list list);
int check_float(const char *format, int i, va_list list);
int check_int(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
int my_count_nbr(int);
int get_modulo(double, int);
int print_pointer_hex(unsigned int);
int my_put_sign(int);

#endif /* !PRINTF_H_ */
