/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Program that return an inverted string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp;

    while (str[i] != '\0'){
        i++;
    }
    while (j != i / 2){
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
        j++;
    }
    return str;
}
