/*
** EPITECH PROJECT, 2023
** ui
** File description:
** ui
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
            i++;
        } else {
            i++;
        }
    }
    return str;
}
