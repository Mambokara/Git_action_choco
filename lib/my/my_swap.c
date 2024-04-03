/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Function made to swap the content of two integers given as parameters
*/

void my_swap(int *a, int *b)
{
    int tempptr;

    tempptr = *a;
    *a = *b;
    *b = tempptr;
}
