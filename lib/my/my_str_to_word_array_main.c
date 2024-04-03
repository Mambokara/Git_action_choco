/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** main function of the str_to_word_array
*/

#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char **my_str_to_word_array(char *string, char *delimiters)
{
    word_array_t *w = malloc(sizeof(word_array_t));
    int nb_words;
    char **word_array;
    int i = 0;

    init_struct(w, delimiters, string);
    nb_words = count_words(string, delimiters, w);
    word_array = malloc(sizeof(char *) * (nb_words + 2));
    word_array = add_words(string, word_array, w);
    word_array[nb_words] = NULL;
    free_struct(w);
    return word_array;
}
