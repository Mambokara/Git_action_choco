/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Program made to display the length of the string given as a parameter
*/

int my_strlen(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0'){
        cpt += 1;
    }
    return (cpt);
}
