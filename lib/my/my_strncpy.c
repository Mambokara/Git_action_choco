/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Program made to copy a string into an other
*/
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    if (n > i){
        dest[i] = '\0';
    }
    return dest;
}
