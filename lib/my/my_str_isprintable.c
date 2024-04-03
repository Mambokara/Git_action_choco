/*
** EPITECH PROJECT, 2023
** ui
** File description:
** ui
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int return_val = 1;

    while (str[i] != '\0'){
        if (str[i] <= 33){
            return_val = 0;
            i++;
        } else {
            i++;
        }
    }
    return return_val;
}
