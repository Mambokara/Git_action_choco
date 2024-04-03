/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** a header composed of the prototypes of our lib's function
*/

#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

int my_strlen(char const *);
int get_bin(unsigned);
char *my_strndup(char const *, int);
int my_putchar(char);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_put_nbr_uns(unsigned int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
int my_put_long_uns(unsigned long);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_strlen(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_strcmp(char const *, char const *);
int my_compute_square_root(int);
int transfo_hex_min(unsigned int);
int transfo_hex_max(unsigned int);
int get_decimal(char, unsigned int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_decimal_to_octal(unsigned int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_show_word_array(char *const *);
int my_put_nbr_uns(unsigned int nb);
int my_put_sign(int);
char *put_nbr_str(int);
char *my_strdup(char *);
int my_strcmp2(char const *s1, char const *s2);
int my_printf(const char *format, ...);
int getnbr(char const *);

#endif /*MY_H_*/
