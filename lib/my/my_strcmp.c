/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compare to strings
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int resultat = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] != s2[i]){
            resultat = (s1[i] - s2[i]);
            return (resultat);
        }
        i = i + 1;
        }
    return 0;
}
