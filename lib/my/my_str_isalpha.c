/*
** EPITECH PROJECT, 2023
** ui
** File description:
** ui
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int return_val = 1;

    while (str[i] != '\0'){
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)){
            i++;
        } else {
            return_val = 0;
            i++;
        }
    }
    return return_val;
}
