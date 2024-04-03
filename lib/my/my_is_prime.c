/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Program made to check if the number given
** as parameter is a prime number or not
*/

int my_is_prime(int nb)
{
    int div = 2;

    if ((nb % 2 == 0 && nb != 2) || nb <= 1){
        return 0;
    }
    while (nb % div != 0 && div <= nb / 2){
        div++;
    }
    if (nb % div != 0 || nb == 2){
        return 1;
    } else {
        return 0;
    }
}
