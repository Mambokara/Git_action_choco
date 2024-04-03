/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** Search for a string of characters in an other string
*/
#include <stddef.h>
#include <string.h>
#include "../../include/my.h"

char *is_one(char *str, char const *to_find)
{
    int test = 0;
    int i = 0;
    int ui = 0;

    while (str[i] != '\0'){
        if (str[i] == to_find[0]){
            test += 1;
        } else {
            test = 0;
        }
        ui++;
        if (test == 1){
            return &str[ui - my_strlen(to_find)];
        }
        i++;
    }
    return NULL;
}

char *is_not_one(char *s, char const *f)
{
    int i = 0;
    int a = 0;
    int ui = 0;
    int test = 0;

    while (s[i] != '\0'){
        if (s[i] == f[a] && (s[i + 1] == f[a + 1] || s[i - 1] == f[a - 1])){
            test += 1;
            a++;
        } else {
            a = 0;
            test = 0;
        }
        ui++;
        if (test == my_strlen(f)){
            return &s[ui - my_strlen(f)];
        }
        i++;
    }
    return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    if (to_find == NULL){
        return str;
    }
    if (my_strlen(to_find) == 1){
        return is_one(str, to_find);
    } else if (my_strlen(to_find) == 0) {
        write(2, "No string researched", 20);
        return NULL;
    } else {
        return is_not_one(str, to_find);
    }
}
