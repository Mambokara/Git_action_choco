/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** split a string into a a table of table
*/

#include <stdlib.h>
#include "../../include/my.h"

int delim(char c, char *delimiters, word_array_t *w)
{
    for (int i = 0; delimiters[i] != '\0'; i++){
        if (c == '\0'){
            return 1;
        }
        if (w->quote % 2 != 0){
            return 1;
        }
        if (c == delimiters[i]){
            return 0;
        }
    }
    return 1;
}

int count_words(char *string, char *delimiters, word_array_t *w)
{
    int nb_words = 0;
    int space = 1;

    for (int i = 0; string[i] != '\0'; i ++){
        if (delim(string[i], delimiters, w) == 0 && space == 0){
            nb_words ++;
            space = 1;
            w->finish_delim = 0;
        }
        if (string[i + 1] == '\0' && space == 0)
            nb_words ++;
        if (delim(string[i], delimiters, w) != 0){
            space = 0;
            w->finish_delim = 1;
        }
        if (delim(string[i], delimiters, w) != 0 &&
        delim(string[i - 1], delimiters, w) == 0 && string[i + 1] == '\0')
            nb_words++;
    }
    return nb_words;
}

char **check_space(char **word_array, word_array_t *w)
{
    if (delim(w->string[w->index], w->delimiters, w) == 0
    && w->is_delim == 0 && w->quote % 2 == 0){
        w->is_delim = 1;
        word_array[w->line][w->len] = '\0';
        w->line_pos = 0;
        w->line += 1;
    }
    return word_array;
}

char **make_split(word_array_t *w, char **word_array)
{
    w->quote += (w->string[w->index] == '"') ? 1 : 0;
    word_array = check_space(word_array, w);
    if (delim(w->string[w->index], w->delimiters, w) != 0 && w->is_delim != 0){
        w->len = 0;
        while (delim(w->string[w->index + w->len], w->delimiters, w) != 0
        && w->string[w->index + w->len] != '\0')
            w->len++;
        word_array[w->line] = malloc(sizeof(char) * (w->len + 1));
    }
    if (delim(w->string[w->index], w->delimiters, w) != 0){
        w->is_delim = 0;
        word_array[w->line][w->line_pos] = w->string[w->index];
        w->line_pos += 1;
    }
    return word_array;
}

char **add_words(char *str, char **word_array, word_array_t *w)
{
    for (w->index = 0; str[w->index] != '\0'; w->index ++){
        word_array = make_split(w, word_array);
    }
    if (w->finish_delim == 1){
        word_array[w->line][w->len] = '\0';
    }
    return word_array;
}
