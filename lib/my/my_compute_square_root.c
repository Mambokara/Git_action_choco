/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Program that display the square root of the number given as parameter
*/
int my_compute_square_root(int nb)
{
    int i = 1;

    while (i * i != nb){
        if (i * i > nb){
            return 0;
        }
        i++;
    }
    return i;
}
