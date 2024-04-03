/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** split a string into a a table of table
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

void init_struct(word_array_t *w, char *delimiters, char *string)
{
    w->is_delim = 1;
    w->delimiters = my_strdup(delimiters);
    w->line = 0;
    w->line_pos = 0;
    w->len = 0;
    w->string = my_strdup(string);
    w->index = 0;
    w->quote = 0;
    w->finish_delim = 0;
}

void free_struct(word_array_t *w)
{
    free(w->delimiters);
    free(w->string);
    free(w);
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

void disp_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
