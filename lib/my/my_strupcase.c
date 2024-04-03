/*
** EPITECH PROJECT, 2023
** ui
** File description:
** ui
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
            i++;
        } else {
            i++;
        }
    }
    return str;
}
